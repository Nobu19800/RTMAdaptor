
#include "coil_adapter.h"
#include <coil/Time.h>

void coil_usleep(const uint64_t usec) {
  coil::usleep(usec);
}
