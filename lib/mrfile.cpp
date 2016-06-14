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

} // namespace mrio
