#ifndef _PCAPNGPP_H_
#define _PCAPNGPP_H_

namespace py = pybind11;


class PcapNg {
public:
  PcapNg(void);
  ~PcapNg(void);
  int OpenRead(char *file, int flag);
  int OpenWrite(char *file);
  int OpenAppend(char *file);
  int Close(void);
  // close()
private:
  light_pcapng_t *_pcapng;
  light_pcapng_file_info *_fileinfo;
  
};

// class PcapNgHeader {
// public:
  
  
// };

// class PcapNgFileInfo {
// public:
  
  
// };

// class PcapNgBlock {
// public:
  
  
// };

#endif // _PCAPNGPP_H_
