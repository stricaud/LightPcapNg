#include <iostream>

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
}

PcapNg::~PcapNg(void) {
  light_pcapng_close(_pcapng);
}

int PcapNg::OpenRead(char *file, int flag)
{
  _pcapng = light_pcapng_open_read(file, LIGHT_FALSE);
  // if (_pcapng) {
  //   _fileinfo = light_pcang_get_file_info(_pcapng);
  // }
  
  return 0;
}


PYBIND11_MODULE(pycapng, m) {
    m.doc() = "LightPcapNG Python Bindings";
    py::class_<PcapNg>(m, "PcapNg")
      .def(py::init<>())
      .def("OpenRead", &PcapNg::OpenRead);
    py::class_<PcapNgFileInfo>(m, "PcapNgFileInfo")
      .def(py::init<>())
      .def("ReadPcapNg", &PcapNgFileInfo::ReadPcapNg)
      .def("GetFileComment", &PcapNgFileInfo::GetFileComment)
      .def("GetOSDesc", &PcapNgFileInfo::GetOSDesc)
      .def("GetHardwareDesc", &PcapNgFileInfo::GetHardwareDesc)
      .def("GetUserAppDesc", &PcapNgFileInfo::GetUserAppDesc)
      .def("GetFileInfoMajorVersion", &PcapNgFileInfo::GetFileInfoMajorVersion)
      .def("GetFileInfoMinorVersion", &PcapNgFileInfo::GetFileInfoMinorVersion);
}
