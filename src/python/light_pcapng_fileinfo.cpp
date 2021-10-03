#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>

#include <light_pcapng.h>
#include <light_pcapng_ext.h>

#include "light_pcapng_fileinfo.hpp"

namespace py = pybind11;

PcapNgFileInfo::PcapNgFileInfo(void) {
  _fileinfo = NULL;
}

PcapNgFileInfo::~PcapNgFileInfo(void) {
  // if (_fileinfo) {
  //   light_free_file_info(_fileinfo);
  // }
}

PcapNgFileInfo::PcapNgFileInfo(const std::string file_comment, const std::string os, const std::string hardware, const std::string user_app)
{
  _fileinfo = light_create_file_info(os.c_str(), hardware.c_str(), user_app.c_str(), file_comment.c_str());
}

int PcapNgFileInfo::ReadFile(PcapNg *pcapng)
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

int PcapNgFileInfo::WriteFile(PcapNg *pcapng)
{
  if (pcapng) {
    light_pcapng_t *_pcapng = pcapng->get_pcapng();
    _pcapng = light_pcapng_open_write(pcapng->get_filename(), _fileinfo, pcapng->get_compression_level());

    return 0;
  }

  return -1;
}

