#include "counting_entry.h"

namespace counting {
void entry(void* argument) {
    for(int i = 0;;i++)
    {
      printf("%d\n\r", i);
      osDelay(500);
    }
}
}