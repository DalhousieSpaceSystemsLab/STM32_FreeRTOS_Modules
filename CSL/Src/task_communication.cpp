#include "task_communication.h"

struct QueueMessage {
    char buffer[CSL_QUEUE_ITEM_SIZE];
    unsigned int size;
};

struct QueueHandleNode {
    QueueHandle_t handle;
    csl::SubSystem subsystem;    
};

QueueHandleNode queue_nodes[CSL_TOTAL_QUEUES] = {};
unsigned int queue_nodes_size = 0;

bool csl::send_message(csl::SubSystem subsystem, char* ptr, unsigned int len) {
    if (len > CSL_QUEUE_ITEM_SIZE - 1) return false;
    
    QueueHandle_t handle = csl::_get_message_queue(subsystem);
    if (handle == nullptr) return false;

    QueueMessage msg;
    msg.size = len;
    void* res = memcpy(msg.buffer, ptr, len);
    if (res == NULL) return false;

    msg.buffer[len] = '\0';

    BaseType_t send_result = xQueueSend(handle, &msg, 0);
    return send_result == pdTRUE;
}

bool csl::receive_message(csl::SubSystem subsystem, char *ptr, unsigned int *len) {
    QueueHandle_t handle = csl::_get_message_queue(subsystem);
    if (handle == NULL) return false;

    QueueMessage msg;
    BaseType_t receive_result = xQueueReceive(handle, &msg, 0);

    if (receive_result != pdTRUE) return false;
    void* res = memcpy(ptr, msg.buffer, msg.size);
    if (res == NULL) return false;

    *len = msg.size;

    return true;
}

bool csl::available_message(csl::SubSystem subsystem) {
    QueueHandle_t handle = csl::_get_message_queue(subsystem);
    if (handle == NULL) return false;

    UBaseType_t messages_waiting = uxQueueMessagesWaiting(handle);

    return messages_waiting > 0;
}

bool csl::_create_message_queue(csl::SubSystem subsystem) {
    if (queue_nodes_size == CSL_TOTAL_QUEUES) return false;
    
    QueueHandleNode node;
    
    node.handle = xQueueCreate(CSL_QUEUE_MAX_ITEMS, sizeof(QueueMessage));
    node.subsystem = subsystem;

    if (node.handle == NULL) return false;

    unsigned int node_index = queue_nodes_size;
    
    // Using insert sort to keep the the list of queues sorted
    while (node_index != 0 && queue_nodes[node_index-1].subsystem > subsystem) {
        queue_nodes[node_index] = queue_nodes[node_index-1];
        node_index -= 1;
    }

    queue_nodes[node_index] = node;
    queue_nodes_size += 1;

    return true;
}

QueueHandle_t csl::_get_message_queue(csl::SubSystem subsystem) {
    unsigned int low = 0, high = queue_nodes_size;

    while (low != high) {
        unsigned int mid = (low + high) >> 1; // Average of low and high
        csl::SubSystem mid_subsystem = queue_nodes[mid].subsystem;

        if (mid_subsystem == subsystem) return queue_nodes[mid].handle;
        if (mid_subsystem < subsystem) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return NULL;
}