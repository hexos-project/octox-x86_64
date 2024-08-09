#pragma once

#include <types.h>

void irq_all_on();
void irq_all_off();
void irq_on(u8 irq);
void irq_off(u8 irq);
