CFLAGS = -Wall -fpic -ffreestanding -fno-stack-protector -nostdinc -nostdlib -I./include -Wall -Wno-return-type -Wno-int-to-pointer-cast -Os
LDFLAGS =  -nostdlib -n -T link.ld
STRIPFLAGS =  -s -K mmio -K fb -K bootboot -K environment -K initstack

SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c,%.o,$(SOURCES))


all: config clean $(OBJECTS)
	@echo "    LD\tkernel.elf"
	@ld $(LDFLAGS) $(OBJECTS) -o kernel.elf
	@echo "    SP\tkernel.elf"
	@strip $(STRIPFLAGS) kernel.elf

%.o: src/%.c
	@echo "    CC\t$<"
	@gcc $(CFLAGS) -mno-red-zone -c $< -o $@

mrproper:
	@echo "    RM\t$(OBJECTS)"
	@rm -f $(OBJECTS)

clean: mrproper
	@echo "    RM\tkernel.elf"
	@rm -f kernel.elf

config:
	@echo "    GEN\tconfig.h"
	@$$SHELL ./genconfig.sh
