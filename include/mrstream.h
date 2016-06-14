// mrstream.h
// author: Mr-Small

#ifndef MRSTREAM_H_
#define MRSTREAM_H_

#include "mrlock.h"

namespace mrio {

class MrStream {
public:

  // Constructor.
  MrStream();

  // Destructor.
  virtual ~MrStream();

  // Check open stream.
  virtual bool isOpen();

  // Open stream.
  virtual int open(const char *name, const char *mode) = 0;

  // Close stream.
  virtual void close() = 0;

  // Write stream.
  virtual int write(const void *data, unsigned int size) = 0;

  // Read stream.
  virtual int read(void *data, unsigned int size) = 0;

protected:
  MrLock lock_;
  bool open_;
};

} // namespace mrio

#endif // MRSTREAM_H_
