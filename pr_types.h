#ifndef INCLUDED_PR_TYPES_H
#define INCLUDED_PR_TYPES_H

///////////////////////////////////////////////////////////////////////////////
////

#ifndef INCLUDED_STDBOOL_H
#define INCLUDED_STDBOOL_H
#include <stdbool.h>
#endif // INCLUDED_STDBOOL_H

#ifndef INCLUDED_STDINT_H
#define INCLUDED_STDINT_H
#include <stdint.h>
#endif // INCLUDED_STDINT_H

#ifndef INCLUDED_STDDEF_H
#define INCLUDED_STDDEF_H
#include <stddef.h>
#endif // INCLUDED_STDDEF_H

///////////////////////////////////////////////////////////////////////////////
//// types
typedef int8_t      pr_int8_t;
typedef int16_t     pr_int16_t;
typedef int32_t     pr_int32_t;
typedef int64_t     pr_int64_t;
typedef intptr_t    pr_intptr_t;

typedef uint8_t     pr_uint8_t;
typedef uint16_t    pr_uint16_t;
typedef uint32_t    pr_uint32_t;
typedef uint64_t    pr_uint64_t;
typedef uintptr_t   pr_uintptr_t;

#ifdef __bool_true_false_are_defined
#    define pr_bool_t bool
#    define PR_TRUE true
#    define PR_FALSE false
#else
#    define pr_bool_t int
#    define PR_TRUE 1
#    define PR_FALSE 0
#endif

typedef uint8_t pr_byte_t;
typedef uint16_t pr_word_t;
typedef uint32_t pr_dword_t;
typedef uint64_t pr_qword_t;

typedef size_t pr_size_t;

#endif //INCLUDED_PR_TYPES_H