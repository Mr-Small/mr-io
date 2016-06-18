// mrfile.cpp
// author: Mr-Small
#include <stdarg.h>
#include "mrfile.h"

namespace mrio {

// Constructor.
MrFile::MrFile() : fp_(NULL) {
}

// Destructor.
MrFile::~MrFile() {
  close();
}

// Open file.
int MrFile::open(const char *name, const char *mode) {

  fp_ = fopen(name, mode);
  if (fp_ == NULL) {
    return -1;
  }
  open_ = true;
  return 0;
}

// Close file.
void MrFile::close() {
  if (fp_ != NULL) {
    fclose(fp_);
    fp_ = NULL;
  }
  open_ = false;
}

// Write file.
int MrFile::write(const void *data, unsigned int size) {

  int ret = -1;
  if (data && isOpen()) {
    if (lock_.lock()) {
      ret = fwrite(data, size, 1, fp_);
    }
  }
  lock_.unlock();
  return ret;
}

// Read file.
int MrFile::read(void *data, unsigned int size) {

  int ret = -1;
  if (data && isOpen()) {
    if (lock_.lock()) {
      ret = fread(data, size, 1, fp_);
    }
  }
  return ret;
}

// Write file to text.
int MrFile::writeText(const char* text, ...) {

  int ret = -1;
  if (text && isOpen()) {
    va_list vaList;
    char buff[256] = {0};

    va_start(vaList, text);
    vsprintf(buff, text, vaList);
    va_end(vaList);

    unsigned int size = strnlen(buff, 256);
    ret = write(buff, size);
  }
  return ret;
}

// Get file size.
unsigned int MrFile::getFileSize() {
  unsigned int pos = 0;
  if (!isOpen()) {
    return pos;
  }

  unsigned int current = ftell(fp_);
  fseek(fp_, 0, SEEK_END);
  pos = ftell(fp_);
  fseek(fp_, current, SEEK_SET);

  return pos;
}

// Check EOF.
bool MrFile::isEof() {
  return feof(fp_) == 0 ? false : true;
}

} // namespace mrio
