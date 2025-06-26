#include "setup.h"

namespace csl {
    bool setup(csl::SubSystem subsystem) {
        return csl::_create_message_queue(subsystem);
    }
}