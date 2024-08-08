CFLAGS = -Wall -fpic -ffreestanding -fno-stack-protector -nostdinc -nostdlib -I./include -Wall -Wno-return-type -Wno-int-to-pointer-cast -Os
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
LDFLAGS =  -nostdlib -n -T link.ld
STRIPFLAGS =  -s -K mmio -K fb -K bootboot -K environment -K initstack
ASFLAGS =

CSOURCES = $(wildcard src/*.c)
SSOURCES = $(wildcard src/*.S)
CPPSOURCES = $(wildcard src/*.cc)
OBJECTS = $(patsubst src/%.c,%.o,$(CSOURCES)) $(patsubst src/%.S,%.o,$(SSOURCES)) $(patsubst src/%.cc,%_cc.o,$(CPPSOURCES))
SOURCES = $(CSOURCES) $(SSOURCES) $(CPPSOURCES)


all: config clean $(OBJECTS)
	@echo "    LD\t$(OBJECTS)"
	@ld $(LDFLAGS) $(OBJECTS) -o kernel.elf
	@echo "    SP\tkernel.elf"
	@strip $(STRIPFLAGS) kernel.elf

%_cc.o: src/%.cc
	@echo "    CC\t$<"
	@g++ $(CXXFLAGS) -mno-red-zone -c $< -o $@

%.o: src/%.c
	@echo "    CC\t$<"
	@gcc $(CFLAGS) -mno-red-zone -c $< -o $@

%.o: src/%.S
	@echo "    AS\t$<"
	@as $(ASFLAGS) -o $@ $<

mrproper:
	@echo "    RM\t$(OBJECTS)"
	@rm -f $(OBJECTS)

clean: mrproper
	@clear
	@echo "    RM\tkernel.elf"
	@rm -f kernel.elf

config:
	@echo "    GEN\tconfig.h"
	@$$SHELL ./genconfig.sh
