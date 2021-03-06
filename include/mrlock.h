// mrlock.h
// author: Mr-Small

#ifndef MRLOCK_H_
#define MRLOCK_H_

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64)
/* Windows */
#include <typeinfo.h>
// Invalid handle value.
#define INVALID_HANDLE              NULL

#else
#include <typeinfo>
#include <unistd.h>
#if defined(ANDROID)
#include <semaphore.h>
// Invalid handle value.
#define INVALID_HANDLE              NULL
#else
// Invalid handle value.
#define INVALID_HANDLE              (-1)
#include <sys/sem.h>
#endif // ANDROID

#endif // WIN

#include <stdio.h>
#include <string.h>

namespace mrio {

class MrLock {
public:

  // Constructor.
  MrLock();

  // Destructor.
  virtual ~MrLock();

  // Lock.
  bool lock();

  // Unlock.
  void unlock();

  // Check locked.
  bool isLocked();

private:

  // Create lock handle.
  void createHandle();

  // Delete lock handle.
  void deleteHandle();

  bool lock_;

#if defined(WIN32) || defined(WIN64) || defined(_WIN32) || defined(_WIN64)
  // Windows platform handle.
  HANDLE lockHandle_;
#elif defined(ANDROID)
  // Android platform handle.
  sem_t *lockHandle_;
#else
  // Mac Linux etc...
  // struct seminfo
  union semuni {
    int val;
    struct semid_ds	*buff;
    unsigned short *array;
    struct seminfo *info;
  };

  struct sembuf sembuf_;
  int lockHandle_;
#endif // WIN

};

} // namespace mrio

#endif // MRLOCK_H_
