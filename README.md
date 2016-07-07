# mr-io
Simple C/C++ IO.

## Description

Mr-IO that has been easy to handle the input and output in C ++.

> MrStream

I/O stream class.

MrFile inherits from MrStream.

> MrLock

MrLock is a class that was easy to handle the Lock.

e.g.

```c++
#include "mrlock.h"

MrLock mrlock;

if (mrlock.lock()) {
    // Do something.
}
mrlock.unlock();
```

> MrFile

MrFile is a class that was easy to handle the File.
