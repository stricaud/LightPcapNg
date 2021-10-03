#ifndef _PCAPNGPP_H_
#define _PCAPNGPP_H_

#include <pybind11/numpy.h>

#include "light_pcapng_fileinfo.hpp"

namespace py = pybind11;

class PcapNgFileInfo;

class PcapNg {
public:
  PcapNg(void);
  ~PcapNg(void);
  int OpenRead(char *file, int flag);
  int OpenWrite(char *file, PcapNgFileInfo *info);
  int OpenAppend(char *file);
  int Close(void);
  int WritePacket(py::bytes data, const std::string &comment);
  //
  light_pcapng_t *get_pcapng(void) { return _pcapng; };
  int get_compression_level(void) { return compression_level; };
  char *get_filename(void) { return filename; };
private:
  light_pcapng_t *_pcapng;
  char *filename;
  int compression_level;
};

// class PcapNgHeader {
// public:
  
  
// };

// class PcapNgFileInfo {
// public:
  
// private:

// };

// class PcapNgBlock {
// public:
  
  
// };

#endif // _PCAPNGPP_H_
