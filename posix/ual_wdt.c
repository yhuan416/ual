#include "ual.h"

#include "stdlib.h"

int ual_wdt_start_wrapper(int timeout)
{
    (void)timeout;
    return 0;
}

void ual_wdt_stop_wrapper(void)
{
    return;
}

void ual_wdt_reset_wrapper(int timeout)
{
    (void)timeout;
}
