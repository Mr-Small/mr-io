// mrlock.cpp
// author: Mr-Small

#include "mrlock.h"

namespace mr-io {

// Constructor.
MrLock::MrLock()
  : lock_(false)
  , lockHandle_(INVALID_HANDLE) {
  createHandle();
}

// Destructor.
MrLock::~MrLock() {
  deleteHandle();
}

// Create handle for lock.
MrLock::createHandle() {

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64)
  // Create mutex handle.
  lockHandle_ = CreateMutex(0, TRUE, NULL);
#else
  // Create semaphore.
  lockHandle_ = semget((key_t)1111, 1, 0666 | IPC_CREAT);
  if (lockHandle_ != AT_INVALID_HANDLE) {
    union semuni semunion;
    semunion.val = 1;
    if (semctl(lockHandle_, 0, SETVAL, semunion) == -1) {
      // TODO falid.
    }
  }
#endif // WIIN
}

} // namespace mr-io
