#pragma once

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef __uint128_t uint128_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long long int64_t;
typedef __int128_t int128_t;

#define true 1
#define false 0
#define offsetof(a,b) ((u64)(&(((a*)(0))->b)))

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uint128_t u128;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef int128_t i128;

using uintptr_t = u64;
using intptr_t = u64;

typedef __SIZE_TYPE__ size_t;

typedef uint64_t uintn;
typedef int64_t intn;

class Error {
    const char *msg;
public:
    Error(const char *msg) : msg(msg) {}
    const char *what() const { return msg; }
    operator const char *() const { return msg; }
};

constexpr auto null = nullptr;

#define __packed __attribute__((packed))
#define __aligned(x) __attribute__((aligned(x)))
#define __section(x) __attribute__((section(x)))

#define __noreturn __attribute__((noreturn))

#define __used __attribute__((used))
#define __weak __attribute__((weak))
#define __section(x) __attribute__((section(x)))

#define __noinline __attribute__((noinline))

#define __const __attribute__((const))
#define __pure __attribute__((pure))

// fastcall
#define __fastcall __attribute__((fastcall))

// naked
#define __naked __attribute__((naked))

#define virt static inline

#define nomangle extern "C"
#define WRAP(x) { x; return; }
#define RWRAP(x) { return x; }
