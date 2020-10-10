#include <pr_memory.h>
#include <assert.h>

void *pr_aligned_alloc(pr_size_t alignment, pr_size_t bytes) {
    void* p1; // original block
    void** p2; // aligned block

    // We want it to be a power of two since
    // align_up operates on powers of two
    assert((alignment & (alignment - 1)) == 0);

    pr_size_t offset = alignment - 1 + sizeof(void*);
    if ((p1 = (void*)malloc(bytes + offset)) == NULL){
        return NULL;
    }
    p2 = (void**)(((pr_size_t)(p1) + offset) & ~(alignment - 1));
    p2[-1] = p1;
    return p2;
}

void *pr_aligned_free(void *ptr) {
    free(((void**)ptr)[-1]);
}


