CFLAGS = -Wall -fpic -ffreestanding -fno-stack-protector -nostdinc -nostdlib -I./include -Wall -Wno-return-type -Wno-int-to-pointer-cast -Os -Wall -Werror
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
LDFLAGS =  -nostdlib -n -T link.ld
STRIPFLAGS =  -s -K mmio -K fb -K bootboot -K environment -K initstack
ASFLAGS =
RSFLAGS = --crate-type=staticlib -C panic=abort

CSOURCES = $(wildcard src/*.c)
SSOURCES = $(wildcard src/*.S)
CPPSOURCES = $(wildcard src/*.cc)
RSSOURCES = $(wildcard src/*.rs)
OBJECTS = $(patsubst src/%.c,%_c.o,$(CSOURCES)) $(patsubst src/%.S,%_s.o,$(SSOURCES)) $(patsubst src/%.cc,%_cc.o,$(CPPSOURCES)) $(patsubst src/%.rs,%_rs.o,$(RSSOURCES))
SOURCES = $(CSOURCES) $(SSOURCES) $(CPPSOURCES) $(RSSOURCES)


all: config clean $(OBJECTS)
	@echo "    LD\t$(OBJECTS)"
	@ld $(LDFLAGS) $(OBJECTS) -o kernel.elf
	@echo "    SP\tkernel.elf"
	@strip $(STRIPFLAGS) kernel.elf

%_cc.o: src/%.cc
	@echo "    CC\t$<"
	@g++ $(CXXFLAGS) -mno-red-zone -c $< -o $@

%_c.o: src/%.c
	@echo "    CC\t$<"
	@gcc $(CFLAGS) -mno-red-zone -c $< -o $@

%_s.o: src/%.S
	@echo "    AS\t$<"
	@as $(ASFLAGS) -o $@ $<

%_rs.o: src/%.rs
	@echo "    RS\t$<"
	@rustc $(RSFLAGS) $< -o $@

mrproper:
	@echo "    RM\t$(OBJECTS)"
	@rm -f *.o

clean: mrproper
	@clear
	@echo "    RM\tkernel.elf"
	@rm -f kernel.elf

config:
	@echo "    GEN\tconfig.h"
	@$$SHELL ./genconfig.sh
