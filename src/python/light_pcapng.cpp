#include <iostream>

#include <time.h>

#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>

#include <light_pcapng.h>
#include <light_pcapng_ext.h>

#include "light_pcapng.hpp"
#include "light_pcapng_fileinfo.hpp"

namespace py = pybind11;

PcapNg::PcapNg(void) {
  _pcapng = NULL;
  filename = NULL;
  
  compression_level = 10;
}

PcapNg::~PcapNg(void) {
  if (_pcapng) {
    light_pcapng_close(_pcapng);
  }
}

int PcapNg::OpenRead(char *file, int flag)
{
  _pcapng = light_pcapng_open_read(file, LIGHT_FALSE);
  filename = file;
  
  return 0;
}

int PcapNg::OpenWrite(char *file, PcapNgFileInfo *info)
{
  _pcapng = light_pcapng_open_write(file, info->get_fileinfo(), compression_level);
  filename = file;
  
  return 0;
}

// FIXME: Use this as soon as pybind11 supports conversion from bytes to vectors -> int PcapNg::WritePacket(const std::vector<uint8_t> &data, const std::string &comment)
int PcapNg::WritePacket(py::bytes data, const std::string &comment)  
{
  light_packet_header header;

  timespec timestamp;
  int frame_length;
  int retval;

  py::buffer_info info(py::buffer(data).request());
  uint8_t *data_bytes = reinterpret_cast<uint8_t *>(info.ptr);
  size_t data_len = static_cast<size_t>(info.size);
    
  header.captured_length = data_len;
  header.original_length = data_len; // Frame length
  retval = clock_gettime(CLOCK_MONOTONIC, &header.timestamp);
  header.data_link = LIGHT_LINKTYPE_ETHERNET; // get link layer type
  header.interface_id = 0;
  header.comment = NULL;
  header.comment_length = 0;
  if (!comment.empty()) {
    header.comment = (char *)comment.c_str();
    header.comment_length = static_cast<uint16_t>(comment.size());
  }
  light_write_packet(_pcapng, &header, data_bytes);

  return 0;
}

PYBIND11_MODULE(pycapng, m) {
    m.doc() = "LightPcapNG Python Bindings";
    py::class_<PcapNg>(m, "PcapNg")
      .def(py::init<>())
      .def("OpenRead", &PcapNg::OpenRead)
      .def("OpenWrite", &PcapNg::OpenWrite)
      .def("WritePacket", &PcapNg::WritePacket);
    py::class_<PcapNgFileInfo>(m, "PcapNgFileInfo")
      .def(py::init<>())
      .def(py::init<const std::string &, const std::string &,const std::string &,const std::string &>())
      .def("ReadFile", &PcapNgFileInfo::ReadFile)
      .def("WriteFile", &PcapNgFileInfo::WriteFile)
      .def("GetFileComment", &PcapNgFileInfo::GetFileComment)
      .def("GetOSDesc", &PcapNgFileInfo::GetOSDesc)
      .def("GetHardwareDesc", &PcapNgFileInfo::GetHardwareDesc)
      .def("GetUserAppDesc", &PcapNgFileInfo::GetUserAppDesc)
      .def("GetFileInfoMajorVersion", &PcapNgFileInfo::GetFileInfoMajorVersion)
      .def("GetFileInfoMinorVersion", &PcapNgFileInfo::GetFileInfoMinorVersion);
}
