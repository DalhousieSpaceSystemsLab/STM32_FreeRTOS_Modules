#ifndef __CSL_DEFINITIONS
#define __CSL_DEFINITIONS

#define CSL_TOTAL_QUEUES 20
#define CSL_QUEUE_MAX_ITEMS 4
#define CSL_QUEUE_ITEM_SIZE 252

namespace csl {
    enum SubSystem {
        IPC = 000,
        ADC = 100,
        CMM = 200,
        EPS = 300,
        OBM = 400,
        OBA = 500,
        PAY = 600,
        SFT = 700,
        THM = 800,
        TEST1 = 10100,
        TEST2 = 10200,
        TEST3 = 10300,
        TEST4 = 10400,
        TEST5 = 10500,
        TEST6 = 10600,
        TEST7 = 10700,
        TEST8 = 10800
    };
}

#endif
  