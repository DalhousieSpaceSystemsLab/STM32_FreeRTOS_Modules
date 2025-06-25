#include "tc2_entry.h"
#include "string.h"


namespace tc2 {

  csl::SubSystem subsystem = csl::SS_TEST2;

  void entry(void* argument) {
    
    csl::setup(subsystem);

    char buf[CSL_QUEUE_ITEM_SIZE] = {0};
    unsigned int rev_len = 0;

    for(;;)
    {
        bool result = csl::receive_message(subsystem, &buf[0], &rev_len);

        if (result) {
          printf("Recvieved (%d): %s\n\r", rev_len, &buf[0]);
        } else {
          printf("Recvieved nothing\n\r");
        }

        osDelay(400);
      }
    }
}
