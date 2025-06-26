#ifndef __CSL_PIN_COMMUNICATION
#define __CSL_PIN_COMMUNICATION

extern "C" {
    #include "main.h"
    #include "queue.h"
}

#include "definitions.h"
#include "cstring"

namespace csl {
    bool send_message(csl::SubSystem subsystem, char* ptr, unsigned int len);
    bool receive_message(csl::SubSystem subsystem, char *ptr, unsigned int *len);
    bool available_message(csl::SubSystem subsystem);

    bool _create_message_queue(csl::SubSystem subsystem);
    QueueHandle_t _get_message_queue(csl::SubSystem subsystem);
}

#endif