#include "stdio.h"

#include "ual.h"

int main(int argc, char const *argv[])
{
    char *ptr = ual_malloc(10);
    printf("ptr: %p\n", ptr);
    ual_free(ptr);

    printf("malloc\n");

    void *mutex = ual_mutex_create();
    printf("mutex: %p\n", mutex);

    ual_mutex_lock(mutex);

    printf("lock\n");

    ual_mutex_unlock(mutex);

    ual_mutex_destroy(mutex);

    return 0;
}
