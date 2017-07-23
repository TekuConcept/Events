# C#-Style C++ Events

Header-only light-weight C#-style C++ events for object-oriented event-driven programming.

[![progress](https://img.shields.io/badge/OSX-pass-green.svg)]()&nbsp;
[![progress](https://img.shields.io/badge/Win32-pass-green.svg)]()&nbsp;
[![progress](https://img.shields.io/badge/Debian-pass-green.svg)]()

Tested on:<br>

| System | Info |
| --- | --- |
| Windows 7 64-bit | Compiled as 32-bit VS2013 |
| Windows 10 64-bit | Compiled as 32-bit VS2017 |
| macOS Sierra 10.12.5 64-bit | Compiled with AppleClang 802.0.42 |
| Debian Linux 4.4.9-ti-r25 | Beaglebone Black GCC 4.9.2 |
| Raspbian Linux 4.9.28-v7+ | Raspberry Pi 3 GCC 4.9.2 |

This project has also been tested by others and found to work on Chrome OS and PCDuino.

```
// Simple Example
#include "EventHandler.h"
#include "FunctionCommand.h"
typedef EventHandler<EventArgs> DefaultEventHandler;

class Action {
public:
  DefaultEventHandler onEvent;
  void doWork() {
    // do work
    Object obj(typeid(this), this);
    EventArgs e;
    onEvent.invoke(obj, e);
  }
}

class Responder {
public:
  void eventOnAction(Object& sender, EventArgs e) {
    // do more work
  }
}

int main() {
  Action action;
  Responder responder;
  action.onEvent += FunctionCommandPtr(
    Responder,
    EventArgs,
    &responder,
    eventOnAction
  );
  action.doWork();
  return 0;
}
```

Private functions can also be used as event callbacks. (Be careful not to break encapsulation in your project.)
