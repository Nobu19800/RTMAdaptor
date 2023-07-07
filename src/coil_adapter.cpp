
#include "coil_adapter.h"
#include <thread>
#include <chrono>

void coil_usleep(const uint64_t usec) {
  std::this_thread::sleep_for(std::chrono::nanoseconds(usec));
}
