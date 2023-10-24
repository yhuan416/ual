#include "ual.h"

#include <pthread.h>

taskId ual_task_create_wrapper(taskFunc func, void *arg, taskAttr *attr)
{
    pthread_t thread;
    int32_t ret = pthread_create(&thread, NULL, func, arg);
    if (ret != 0)
        return NULL;

    return (taskId)thread;
}

void ual_task_join_wrapper(taskId task)
{
    pthread_join((pthread_t)task, NULL);
}
