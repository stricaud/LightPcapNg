#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>

#include <light_pcapng.h>
#include <light_pcapng_ext.h>

#include "light_pcapng_fileinfo.hpp"

namespace py = pybind11;

PcapNgFileInfo::PcapNgFileInfo(void) {

}

int PcapNgFileInfo::ReadPcapNg(PcapNg *pcapng)
{
  if (pcapng) {
    light_pcapng_t *_pcapng = pcapng->get_pcapng();
    if (_pcapng) {
      _fileinfo = light_pcang_get_file_info(_pcapng);
    }

    return 0;
  }

  return -1;
}

PcapNgFileInfo::~PcapNgFileInfo(void) {

}

