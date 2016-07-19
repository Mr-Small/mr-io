// mrsocket.h
// author: Mr-Small

#ifndef MRSOCKET_H_
#define MRSOCKET_H_

namespace mrio {

class MrSocket : public MrStream {
public:
  // Constructor.
  MrSocket();

  // Destructor.
  virtual ~MrSocket();

  // Open stream.
  virtual int open(const char *name, const char *mode);

  // Close stream.
  virtual void close();

  // Write stream.
  virtual int write(const void *data, unsigned int size);

  // Read stream.
  virtual int read(void *data, unsigned int size);
};

} // namespace mrio

#endif // MRSOCKET_H_
