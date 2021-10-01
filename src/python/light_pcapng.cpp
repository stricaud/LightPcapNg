#include <iostream>

#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>

#include <light_pcapng.h>
#include <light_pcapng_ext.h>

#include "light_pcapng.hpp"

namespace py = pybind11;

PcapNg::PcapNg(void) {
  _pcapng = NULL;
}

PcapNg::~PcapNg(void) {
  // close
}

int PcapNg::OpenRead(char *file, int flag)
{
  _pcapng = light_pcapng_open_read(file, LIGHT_FALSE);
  if (_pcapng) {
    _fileinfo = light_pcang_get_file_info(_pcapng);
  }
  
  return 0;
}


PYBIND11_MODULE(pycapng, m) {
    m.doc() = "LightPcapNG Python Bindings";
    py::class_<PcapNg>(m, "PcapNg")
      .def(py::init<>())
      .def("OpenRead", &PcapNg::OpenRead)
      .def("GetFileComment", &PcapNg::GetFileComment)
      .def("GetOSDesc", &PcapNg::GetOSDesc)
      .def("GetHardwareDesc", &PcapNg::GetHardwareDesc)
      .def("GetUserAppDesc", &PcapNg::GetUserAppDesc)
      .def("GetFileInfoMajorVersion", &PcapNg::GetFileInfoMajorVersion)
      .def("GetFileInfoMinorVersion", &PcapNg::GetFileInfoMinorVersion);
}
