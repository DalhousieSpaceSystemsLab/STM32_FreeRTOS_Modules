#ifndef __CSL_SETUP
#define __CSL_SETUP

extern "C" {
    #include "main.h"
}

#include "definitions.h"
#include "task_communication.h"

namespace csl {
    bool setup(csl::SubSystem subsystem);
}

#endif