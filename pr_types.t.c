//
// Created by PCHEN on 2020/10/10.
//
#include <pr_types.h>
#include <stdlib.h>
#include <stdio.h>

///////////////////////////////////////////////////////////////////////////////
////
typedef struct pr_types_test_int8_s{
    pr_int8_t d_int8;
}pr_types_test_int8_t;

///////////////////////////////////////////////////////////////////////////////
////
void printSize(const char* msg, pr_size_t size){
    printf("size of '%s' is %d\n", msg, size);
}

#define PRINT_SIZE(type) printSize(#type, sizeof(type))
///////////////////////////////////////////////////////////////////////////////
////

int main(int argc, char** argv){
    PRINT_SIZE(int8_t);
    PRINT_SIZE(int16_t);
    PRINT_SIZE(int32_t);
    PRINT_SIZE(int64_t);
    PRINT_SIZE(uint8_t);
    PRINT_SIZE(uint16_t);
    PRINT_SIZE(uint32_t);
    PRINT_SIZE(uint64_t);
    PRINT_SIZE(intptr_t);
    PRINT_SIZE(uintptr_t);
    PRINT_SIZE(char);
    PRINT_SIZE(unsigned char);
    PRINT_SIZE(int);
    PRINT_SIZE(short);
    PRINT_SIZE(long);
    PRINT_SIZE(double);
    PRINT_SIZE(long long);
    PRINT_SIZE(pr_types_test_int8_t);
    printf("INT8_MIN: %d\n", INT8_MIN);
    printf("INT8_MAX: %d\n", INT8_MAX);
    printf("INT16_MIN: %d\n", INT16_MIN);
    printf("INT16_MAX: %d\n", INT16_MAX);
    printf("INT32_MIN: %d\n", INT32_MIN);
    printf("INT32_MAX: %d\n", INT32_MAX);
    printf("INT64_MIN: %lld\n", INT64_MIN);
    printf("INT64_MAX: %lld\n", INT64_MAX);
    printf("UINT8_MAX: %u\n", UINT8_MAX);
    printf("UINT16_MAX: %u\n", UINT16_MAX);
    printf("UINT32_MAX: %u\n", UINT32_MAX);
    printf("UINT64_MAX: %llu\n", UINT64_MAX);
    return 0;
}

