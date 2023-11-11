## advanced-enums

**DEFINE_ENUM(Status, Fail, Success, Exception);**

Defines an advanced enum (TM) called `Status` with the following values: `Fail`, `Success`, and `Exception`.

**Example**

A C++23 function that demonstrates how to use the example 'Status' enum

```c++
#include "advanced-enums.h"

DEFINE_ENUM(Status, Fail, Success, Exception);

Status Foo() {
  return Status::Success;
}

void Example() {
  const Status status1 = Status::Fail;
  const Status status2 = Foo();

  if (status1 == Status::Success); // false
  if (status1 != Status::Success); // true
  if (status1.IsException()); // false
  if (status1 != status2); // true

  std::println("{} - {}", status1, status2); // "Fail - Success"
}

```
**Usage**

To use the `advanced-enums` library, simply include the `advanced-enums.h` header file in your source code. You can then use the `DEFINE_ENUM` macro to define enums with additional functionality, such as a sleeker API and built in ToString & formatting support.


**Concerns**

Any enum created will now have all the types spelled out in memory. If you have any important variable names that you would like to obfuscate, simply define ENUM_ENCRYPTION_STRING to your compile time encryption.

**Final Thoughts**

There are other tools available that offer more features, but I prefer to use this macro because it is lightweight and made by me (>.>). Hopefully we will see some changes to macros in the coming c++ editions. The amount of compiler hacking required to make this work is ridiculous.
