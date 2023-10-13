#include "ual.h"

char *ual_malloc_wrapper(size_t size);
void ual_free_wrapper(void *ptr);

void *ual_mutex_create_wrapper(void);
void ual_mutex_destroy_wrapper(void *mutex);
void ual_mutex_lock_wrapper(void *mutex);
void ual_mutex_unlock_wrapper(void *mutex);


// wdt
int ual_wdt_start_wrapper(int timeout);
void ual_wdt_stop_wrapper(void);
void ual_wdt_reset_wrapper(int timeout);

ual_t ual_func_table = {
    .ual_malloc = ual_malloc_wrapper,
    .ual_free = ual_free_wrapper,

    .ual_mutex_create = ual_mutex_create_wrapper,
    .ual_mutex_destroy = ual_mutex_destroy_wrapper,
    .ual_mutex_lock = ual_mutex_lock_wrapper,
    .ual_mutex_unlock = ual_mutex_unlock_wrapper,



    .ual_wdt_reset = ual_wdt_reset_wrapper,
    .ual_wdt_start = ual_wdt_start_wrapper,
    .ual_wdt_stop = ual_wdt_stop_wrapper,
};
