#include "toggleled_entry.h"

namespace toggle_led {
void entry(void* argument) {
    for(;;)
    {
      HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
      printf("Toggled\n\r");
      osDelay(500);
    }
}
}