#include "os_internal.h"

void __osSetTimerIntr(OSTime time) {
    OSTime newTime;
    u32 mask;

    mask = __osDisableInt();
    D_8007E5B8 = osGetCount();
    newTime = D_8007E5B8 + time;
    __osSetCompare(newTime);
    __osRestoreInt(mask);
}
