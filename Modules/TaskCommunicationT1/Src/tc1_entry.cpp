#include "tc1_entry.h"
#include "string.h"

namespace tc1 {

csl::SubSystem subsystem = csl::SS_TEST1;

void entry(void* argument) {
    
    csl::setup(subsystem);

    char buf[40] = {0};

    unsigned int delay;
    unsigned int len;

    for(int i = 0;1;i++)
    {
        len = sprintf(&buf[0], "Test message %d", i);

        bool res = csl::send_message(csl::SS_TEST2, buf, len);
        if (res) {
          printf("Sent message: %s\n\r", buf);
        } else {
          printf("Failed sending message: %s\n\r", buf);
        }
        
        delay = (i % 20 <= 10) ? 800 : 200;
        osDelay(delay);
    }
  }
}
