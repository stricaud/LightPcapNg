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
  int GetFileInfoMajorVersion() { if (_fileinfo) { return _fileinfo->major_version; } return 0; }
  int GetFileInfoMinorVersion() { if (_fileinfo) { return _fileinfo->minor_version; } return 0; }
  char *GetFileComment() { if (_fileinfo) { if (_fileinfo->file_comment) { return _fileinfo->file_comment; } }; return NULL; }
  char *GetOSDesc() { if (_fileinfo) { if (_fileinfo->os_desc) { return _fileinfo->os_desc; } }; return NULL; }
  char *GetHardwareDesc() { if (_fileinfo) { if (_fileinfo->hardware_desc) { return _fileinfo->hardware_desc; } }; return NULL; }
  char *GetUserAppDesc() { if (_fileinfo) { if (_fileinfo->user_app_desc) { return _fileinfo->user_app_desc; } }; return NULL; }
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
  
// private:

// };

// class PcapNgBlock {
// public:
  
  
// };

#endif // _PCAPNGPP_H_
