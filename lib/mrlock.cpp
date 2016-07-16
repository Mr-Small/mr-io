// mrlock.cpp
// author: Mr-Small
#include <stdio.h>
#include "mrlock.h"

namespace mrio {

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
void MrLock::createHandle() {

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64)
  // Create mutex handle.
  lockHandle_ = CreateMutex(0, TRUE, NULL);
#elif defined(ANDROID)
  // Create semaphore.
  lockHandle_ = new sem_t;
  sem_init(lockHandle_, 0, 1);
#else
  // Create semaphore.
  lockHandle_ = semget((key_t)1111, 1, 0666 | IPC_CREAT);
  if (lockHandle_ != INVALID_HANDLE) {
    union semuni semunion;
    semunion.val = 1;
    if (semctl(lockHandle_, 0, SETVAL, semunion) == -1) {
      perror("create handle failed.");
    }
  }
#endif // WIIN
}

// Delete handle for lock.
void MrLock::deleteHandle() {

  unlock();
  if (lockHandle_ != INVALID_HANDLE) {
#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64)
  // Check mutex.
    CloseHandle(lockHandle_);
#elif defined(ANDROID)
    sem_destroy(lockHandle_);
#else
    union semuni semunion;
    if (semctl(lockHandle_, 0, IPC_RMID, semunion) == -1) {
      perror("delete handle failed.");
    }
#endif // WIN
    lockHandle_ = INVALID_HANDLE;
  }
  lock_ = false;
}

// Lock with handle.
bool MrLock::lock() {

  if (lock_) {
    return true;
  }

  if (lockHandle_ == INVALID_HANDLE) {
    perror("lock handle invalid.");
    return false;
  }

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64)

  // Wait for single object.
  if (WaitForSingleObject(lockHandle_, INFINITE) == WAIT_FAILED) {
    perror("waitforsingleobject wait failed.");
    return false;
  }
#elif defined(ANDROID)
  sem_wait(lockHandle_);
#else
  // semaphore lock.
  sembuf_.sem_num = 0;
  sembuf_.sem_op = -1;
  sembuf_.sem_flg = SEM_UNDO;

  if (semop(lockHandle_, &sembuf_, 1) == -1) {
    perror("semop failed.");
  }
#endif // WIN

  lock_ = true;
  return true;
}

// Unlock.
void MrLock::unlock() {

  if (!lock_) {
    return;
  }
#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64)
  ReleaseMutex(lockHandle_);
#elif defined(ANDROID)
  sem_post(lockHandle_);
#else
  sembuf_.sem_op = 1;
  if (semop(lockHandle_, &sembuf_, 1) == -1) {
    perror("semop failed.");
  }
#endif // WIN
  lock_ = false;
}

// Check locked.
bool MrLock::isLocked() {
  return lock_;
}

} // namespace mrio
