//#include <print>

#include "include/advanced-enums.h"

DEFINE_ENUM(Status, Fail, Success, Exception);

Status Foo() {
  return Status::Success;
}

void Example() {
  const Status status2 = Foo();
  const Status status1 = Status::Fail;

  if (status1 == Status::Success); // false
  if (status1 != Status::Success); // true
  if (status1.IsException()); // false
  if (status1 != status2); // true

  std::println("{} - {}", status1, status2); // "Fail - Success"
}

int main() {
  Example();
}
