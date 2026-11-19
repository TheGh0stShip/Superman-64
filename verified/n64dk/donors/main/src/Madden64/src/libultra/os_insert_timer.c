#include "os_internal.h"

OSTime __osInsertTimer(OSTimer* timer) {
    OSTimer* current;
    OSTime time;
    u32 mask = __osDisableInt();

    current = D_80074ED0->next;
    time = timer->value;
    for (; current != D_80074ED0 && time > current->value; current = current->next) {
        time -= current->value;
    }
    timer->value = time;
    if (current != D_80074ED0) {
        current->value -= time;
    }
    timer->next = current;
    timer->prev = current->prev;
    current->prev->next = timer;
    current->prev = timer;
    __osRestoreInt(mask);
    return time;
}
