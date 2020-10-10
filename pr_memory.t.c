//
// Created by PCHEN on 2020/10/10.
//

#include <pr_memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

///////////////////////////////////////////////////////////////////////////////
////
#define SIZE 10

///////////////////////////////////////////////////////////////////////////////
////
typedef struct pr_mem_test_object_s{
    int d_value;
}pr_mem_test_object_t;

void* debug_malloc(pr_size_t bytes){
    void* p =  malloc(bytes);
    printf("malloc(%d) at %p\n", bytes, p);
    return p;
}

void debug_free(void* p){
    printf("free(%p)\n", p);
    free(p);
}

///////////////////////////////////////////////////////////////////////////////
////

void test1(){
    pr_simple_allocator_t sa;
    sa.malloc = debug_malloc;
    sa.free = debug_free;

    int i;
    pr_mem_test_object_t* ary[SIZE];
    for(i=0; i<SIZE; i++){
        ary[i] = sa.malloc(sizeof(*ary[i]));
        assert(ary[i]);
    }

    for(i=0; i<SIZE; i++){
        sa.free(ary[i]);
    }
}

void test_aligned(){
    int *p1 = malloc(10*sizeof *p1);
    printf("default-aligned addr:   %p\n", (void*)p1);
    free(p1);

    int *p2 = pr_aligned_alloc(1024, 1024*sizeof *p2);
    printf("1024-byte aligned addr: %p\n", (void*)p2);
    pr_aligned_free(p2);
}

///////////////////////////////////////////////////////////////////////////////
////

int main(int argc, char** argv){
    test1();
    test_aligned();
    return 0;
}
