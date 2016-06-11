// mrfile.h
// author: Mr-Small

#ifndef MRFILE_H_
#define MRFILE_H_

#include "mrstream.h"

namespace mrio {

class MrFile : public MrStream {
public:
  // Constructor.
  MrFile();

  // Destructor.
  virtual ~MrFile();

  // Open file.
  virtual int open(const char *name);

  // Close file.
  virtual void close();

  // Write file.
  virtual int write(const void *data, unsigned int size);

  // Read file.
  virtual int read(void *data, unsigned int size);

  // Write file to text.
  int write(const char* text, ...);

  // Get file size.
  unsigned int getFileSize();

  // Check file eof?.
  bool isEof();

private:
  FILE *fp_;
};

} // namespace mrio

#endif // MRFILE_H_
