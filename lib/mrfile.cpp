// mrfile.cpp
// author: Mr-Small
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
