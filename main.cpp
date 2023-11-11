#include <print>

#include "include/enum.h"

DEFINE_ENUM(Status, Fail, Success, Exception);

int main() {
  Status status1 = Status::Fail;
	Status status2 = Status::Success;

  if(status1 != status2) {
    std::println("{} - {}", status1, status2);
  }

  status1 = status2;

  if (status1 == status2) {
    std::println("{} - {}", status1, status2);
  }
}
