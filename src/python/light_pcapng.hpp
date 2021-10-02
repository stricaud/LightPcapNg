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
  light_pcapng_t *get_pcapng(void) { return _pcapng; };
private:
  light_pcapng_t *_pcapng;
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
