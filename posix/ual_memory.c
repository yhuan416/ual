#include "ual.h"

#include "stdlib.h"

char *ual_malloc_wrapper(size_t size)
{
    return malloc(size);
}

void ual_free_wrapper(void *ptr)
{
    free(ptr);
}
