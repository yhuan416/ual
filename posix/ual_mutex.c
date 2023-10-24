#include "ual.h"

#include "stdlib.h"

#include "pthread.h"

mutexId ual_mutex_create_wrapper(void)
{
    pthread_mutex_t *mutex = (pthread_mutex_t *)ual_malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(mutex, NULL);
    return (mutexId)mutex;
}

void ual_mutex_destroy_wrapper(mutexId mutex)
{
    pthread_mutex_destroy((pthread_mutex_t *)mutex);
    ual_free(mutex);
}

void ual_mutex_lock_wrapper(mutexId mutex)
{
    pthread_mutex_lock((pthread_mutex_t *)mutex);
}

void ual_mutex_unlock_wrapper(mutexId mutex)
{
    pthread_mutex_unlock((pthread_mutex_t *)mutex);
}
