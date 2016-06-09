// mrstream.cpp
// author: Mr-Small
#include "mrstream.h"

namespace mrio {

// Constructor.
MrStream::MrStream() : open_(false)
{
}

// Destructor.
MrStream::~MrStream() {
}

// Check open stream.
bool MrStream::isOpen() {
  return open_;
}

} // namespace mrio
