#include "tc1_entry.h"
#include "string.h"

csl::SubSystem subsystem = csl::SS_TEST1;

namespace tc1 {
void entry(void* argument) {
    
    csl::setup(subsystem);

    char *msg = "This is my test message";
    unsigned int len = strlen(msg);

    char buf[CSL_QUEUE_ITEM_SIZE] = {0};
    unsigned int rev_len = 0;

    for(int i = 0;1;i++)
    {
      if ((i&1)==0) {
        csl::send_message(subsystem, msg, len);
      } else {
        csl::receive_message(subsystem, &buf[0], &rev_len);
        printf("Recvieved: %s\n\rlen: %d\n\r", &buf[0], rev_len);
        osDelay(500);
      }
    }
}
}