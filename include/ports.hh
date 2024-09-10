#pragma once

#include "types.hh"

virt void outb(uint16_t port, uint8_t val)
{
    __asm__ volatile ( "outb %b0, %w1" : : "a"(val), "Nd"(port) : "memory");
}

virt uint8_t inb(uint16_t port)
{
    uint8_t ret;
    __asm__ volatile ( "inb %w1, %b0"
                   : "=a"(ret)
                   : "Nd"(port)
                   : "memory");
    return ret;
}

virt void outw(uint16_t port, uint16_t value)
{
	__asm__ __volatile__ ("outw %1, %0" : : "dN" (port), "a" (value));
}

virt uint16_t inw(uint16_t port)
{
	uint16_t value;
	__asm__ __volatile__ ("inw %1, %0" : "=a"(value) : "Nd"(port));
	
	return value;
}

virt void outdw(uint16_t port, uint32_t value)
{
	__asm__ __volatile__ ("outl %1, %0" : : "dN" (port), "a" (value));
}

virt uint32_t indw(uint16_t port)
{
	uint32_t value;
	__asm__ __volatile__ ("inl %1, %0" : "=a"(value) : "Nd"(port));
	
	return value;
}

struct PortProxy {
	uint16_t port;
	PortProxy(uint16_t port) : port(port) {}
	void operator << (u8 val) { outb(port, val); }
	void operator >> (u8 *target) { *target = inb(port); }
	void operator << (u16 val) { outw(port, val); }
	void operator >> (u16 *target) { *target = inw(port); }
	void operator << (u32 val) { outdw(port, val); }
	void operator >> (u32 *target) { *target = indw(port); }
};

namespace ports {
    class PortsIO {
		PortsIO() {};
		~PortsIO() {};
	public:
		PortProxy operator () (uint16_t port) { return PortProxy(port); }
	};

	extern PortsIO io;
}
