#ifndef _PCAPNGFILEINFOPP_H_
#define _PCAPNGFILEINFOPP_H_

namespace py = pybind11;

#include "light_pcapng.hpp"  

class PcapNg;

class PcapNgFileInfo {
public:
  PcapNgFileInfo();
  PcapNgFileInfo(const std::string file_comment, const std::string os, const std::string hardware, const std::string user_app);
  ~PcapNgFileInfo(void);
  int ReadFile(PcapNg *pcapng);
  int WriteFile(PcapNg *pcapng);
  int GetFileInfoMajorVersion() { if (_fileinfo) { return _fileinfo->major_version; } return 0; }
  int GetFileInfoMinorVersion() { if (_fileinfo) { return _fileinfo->minor_version; } return 0; }
  char *GetFileComment() { if (_fileinfo) { if (_fileinfo->file_comment) { return _fileinfo->file_comment; } }; return NULL; }
  char *GetOSDesc() { if (_fileinfo) { if (_fileinfo->os_desc) { return _fileinfo->os_desc; } }; return NULL; }
  char *GetHardwareDesc() { if (_fileinfo) { if (_fileinfo->hardware_desc) { return _fileinfo->hardware_desc; } }; return NULL; }
  char *GetUserAppDesc() { if (_fileinfo) { if (_fileinfo->user_app_desc) { return _fileinfo->user_app_desc; } }; return NULL; }
  light_pcapng_file_info *get_fileinfo() { return _fileinfo; };
private:
  light_pcapng_file_info *_fileinfo;  
};

#endif // _PCAPNGFILEINFOPP_H_

