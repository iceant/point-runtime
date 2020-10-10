#ifndef INCLUDED_PR_MEMORY_H
#define INCLUDED_PR_MEMORY_H

///////////////////////////////////////////////////////////////////////////////
////
#ifndef INCLUDED_STDLIB_H
#define INCLUDED_STDLIB_H
#include <stdlib.h>
#endif // INCLUDED_STDLIB_H

#ifndef INCLUDED_PR_TYPES_H
#include <pr_types.h>
#endif //INCLUDED_PR_TYPES_H

///////////////////////////////////////////////////////////////////////////////
//// types
typedef void* (*pr_malloc_t)(pr_size_t nBytes);
typedef void* (*pr_realloc_t)(void* ptr, pr_size_t newBytes);
typedef void* (*pr_calloc_t)(pr_size_t numOfElements, pr_size_t elementSize);
typedef void (*pr_free_t)(void* ptr);

typedef void* (*pr_aligend_alloc_t)(pr_size_t alignment, pr_size_t bytes);

typedef struct pr_simple_allocator_s{
    pr_malloc_t malloc;
    pr_free_t free;
}pr_simple_allocator_t;

typedef struct pr_complex_allocator_s{
    pr_malloc_t malloc;
    pr_realloc_t realloc;
    pr_calloc_t calloc;
    pr_free_t free;
}pr_complex_allocator_t;

typedef struct pr_aligned_allocator_s{
    pr_aligend_alloc_t aligned_alloc;
    pr_free_t aligned_free;
}pr_aligned_allocator_t;

///////////////////////////////////////////////////////////////////////////////
//// functions
void* pr_aligned_alloc(pr_size_t alignment, pr_size_t bytes);

void* pr_aligned_free(void * ptr);

///////////////////////////////////////////////////////////////////////////////
//// macros

#define PR_MEM_INIT_SIMPLE_ALLOCATOR(a) \
    do{                                 \
        a.malloc = malloc;              \
        a.free = free;                  \
    }while(0)

#define PR_MEM_INIT_COMPLEX_ALLOCATOR(a) \
    do{                                  \
        a.malloc = malloc;               \
        a.realloc = realloc;             \
        a.calloc = calloc;               \
        a.free = free;                   \
    }while(0)

#define PR_MEM_INIT_ALIGNED_ALLOCATOR(a)    \
    do{                                     \
        a.aligned_alloc = pr_aligned_alloc; \
        a.aligned_free = pr_aligned_free;   \
    }while(0)

#endif //INCLUDED_PR_MEMORY_H
