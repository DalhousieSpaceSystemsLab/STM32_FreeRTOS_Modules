#ifndef __CSL_DEFINITIONS
#define __CSL_DEFINITIONS

#define CSL_TOTAL_QUEUES 20
#define CSL_QUEUE_MAX_ITEMS 4
#define CSL_QUEUE_ITEM_SIZE 251

namespace csl {
    enum SubSystem {
        SS_IPC = 000,
        SS_ADC = 100,
        SS_CMM = 200,
        SS_EPS = 300,
        SS_OBM = 400,
        SS_OBA = 500,
        SS_PAY = 600,
        SS_SFT = 700,
        SS_THM = 800,
        SS_TEST1 = 10100,
        SS_TEST2 = 10200,
        SS_TEST3 = 10300,
        SS_TEST4 = 10400,
        SS_TEST5 = 10500,
        SS_TEST6 = 10600,
        SS_TEST7 = 10700,
        SS_TEST8 = 10800
    };
}

#endif
  