#ifndef _UAL_H_
#define _UAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// memory
typedef char *(*ual_malloc_func)(size_t size);
typedef void (*ual_free_func)(void *ptr);

// mutex
typedef void *(*ual_mutex_create_func)(void);
typedef void (*ual_mutex_destroy_func)(void *mutex);
typedef void (*ual_mutex_lock_func)(void *mutex);
typedef void (*ual_mutex_unlock_func)(void *mutex);

// queue
typedef void *(*ual_queue_create_func)(int size, int count);
typedef void (*ual_queue_destroy_func)(void *queue);
typedef int (*ual_queue_push_func)(void *queue, const void *data, int timeout);
typedef int (*ual_queue_pop_func)(void *queue, void *data, int timeout);

// wdt
typedef int (*ual_wdt_start_func)(int timeout);
typedef void (*ual_wdt_stop_func)(void);
typedef void (*ual_wdt_reset_func)(int timeout);

typedef struct _ual {
    ual_malloc_func ual_malloc;
    ual_free_func ual_free;

    ual_mutex_create_func ual_mutex_create;
    ual_mutex_destroy_func ual_mutex_destroy;
    ual_mutex_lock_func ual_mutex_lock;
    ual_mutex_unlock_func ual_mutex_unlock;

    ual_queue_create_func ual_queue_create;
    ual_queue_destroy_func ual_queue_destroy;
    ual_queue_push_func ual_queue_push;
    ual_queue_pop_func ual_queue_pop;

    ual_wdt_start_func ual_wdt_start;
    ual_wdt_stop_func ual_wdt_stop;
    ual_wdt_reset_func ual_wdt_reset;
} ual_t;

extern ual_t ual_func_table;

#define ual_malloc(size)            ual_func_table.ual_malloc(size)
#define ual_free(ptr)               ual_func_table.ual_free(ptr)

#define ual_mutex_create()          ual_func_table.ual_mutex_create()
#define ual_mutex_destroy(mutex)    ual_func_table.ual_mutex_destroy(mutex)
#define ual_mutex_lock(mutex)       ual_func_table.ual_mutex_lock(mutex)
#define ual_mutex_unlock(mutex)     ual_func_table.ual_mutex_unlock(mutex)

#endif // !_UAL_H_