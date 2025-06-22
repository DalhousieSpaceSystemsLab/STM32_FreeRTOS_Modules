#ifndef __CSL_PIN_COMMUNICATION
#define __CSL_PIN_COMMUNICATION

#include "main.h"
#include "definitions.h"
#include "queue.h"

namespace csl {
    struct _QueueMessage {
        char[CSL_QUEUE_ITEM_SIZE] buffer;
        unsigned int size;
    }

    bool send_message(csl::SubSystem subsystem, char* ptr, unsigned int len);
    bool receive_message(csl::SubSystem subsystem, char ptr[sizeof(csl::_QueueMessage)], unsigned int *len);
    bool available_message(csl::SubSystem subsystem);

    bool _create_message_queue(csl::SubSystem subsystem);
    QueueHandle_t _get_message_queue(csl::SubSystem subsystem);
}

#endif