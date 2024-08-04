#pragma once

#include "types.h"

static inline void outb(uint16_t port, uint8_t val)
{
    __asm__ volatile ( "outb %b0, %w1" : : "a"(val), "Nd"(port) : "memory");
}

static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    __asm__ volatile ( "inb %w1, %b0"
                   : "=a"(ret)
                   : "Nd"(port)
                   : "memory");
    return ret;
}

static inline void outw(uint16_t port, uint16_t value)
{
	__asm__ __volatile__ ("outw %1, %0" : : "dN" (port), "a" (value));
}

static inline uint16_t inw(uint16_t port)
{
	uint16_t value;
	__asm__ __volatile__ ("inw %1, %0" : "=a"(value) : "Nd"(port));
	
	return value;
}

static inline void outdw(uint16_t port, uint32_t value)
{
	__asm__ __volatile__ ("outl %1, %0" : : "dN" (port), "a" (value));
}

static inline uint32_t indw(uint16_t port)
{
	uint32_t value;
	__asm__ __volatile__ ("inl %1, %0" : "=a"(value) : "Nd"(port));
	
	return value;
}
