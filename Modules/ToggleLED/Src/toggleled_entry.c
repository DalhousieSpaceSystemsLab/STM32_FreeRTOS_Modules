#include "toggleled_entry.h"

void toggleled_entry(void* argument) {
    for(;;)
    {
      HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
      printf("Toggled\n\r");
      osDelay(500);
    }
}