CFLAGS = -Wall -fpic -ffreestanding -fno-stack-protector -nostdinc -nostdlib -I./include -Wall -Wno-return-type -Wno-int-to-pointer-cast -Os -Wall -Werror
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
LDFLAGS =  -nostdlib -n -T link.ld
STRIPFLAGS =  -s -K mmio -K fb -K bootboot -K environment -K initstack
ASFLAGS =
RSFLAGS = --crate-type=staticlib -C panic=abort -C opt-level=3 -C debuginfo=none -C strip=symbols
OBJDIR = objects

CSOURCES = $(shell find src -name '*.c' -not -name '.*')
SSOURCES = $(shell find src -name '*.S' -not -name '.*')
CPPSOURCES = $(shell find src -name '*.cc' -not -name '.*')
RSSOURCES = $(shell find src -name '*.rs' -not -name '.*')
FASMSOURCES = $(shell find src -name '*.fasm' -not -name '.*')
OBJECTS = $(patsubst src/%.c,$(OBJDIR)/%_c.o,$(CSOURCES)) \
		  $(patsubst src/%.S,$(OBJDIR)/%_s.o,$(SSOURCES)) \
		  $(patsubst src/%.cc,$(OBJDIR)/%_cc.o,$(CPPSOURCES)) \
		  $(patsubst src/%.rs,$(OBJDIR)/%_rs.o,$(RSSOURCES)) \
		  $(patsubst src/%.fasm,$(OBJDIR)/%_fasm.o,$(FASMSOURCES))
SOURCES = $(CSOURCES) $(SSOURCES) $(CPPSOURCES) $(RSSOURCES) $(FASMSOURCES)


build: prepare all

prepare:
	@echo "    RM\t$(OBJDIR)"
	@rm -rf $(OBJDIR)
	@echo "    MD\t$(OBJDIR)"
	@mkdir -p $(dir $(OBJECTS))

all: config clean $(OBJECTS)
	@echo "    LD\t$(OBJECTS)"
	@ld $(LDFLAGS) $(OBJECTS) -o kernel.elf
	@echo "    SP\tkernel.elf"
	@strip $(STRIPFLAGS) kernel.elf

$(OBJDIR)/%_cc.o: src/%.cc
	@echo "    CC\t$<"
	@g++ $(CXXFLAGS) -mno-red-zone -c $< -o $@

$(OBJDIR)/%_c.o: src/%.c
	@echo "    CC\t$<"
	@gcc $(CFLAGS) -mno-red-zone -c $< -o $@

$(OBJDIR)/%_s.o: src/%.S
	@echo "    AS\t$<"
	@as $(ASFLAGS) -o $@ $<

$(OBJDIR)/%_rs.o: src/%.rs
	@echo "    RS\t$<"
	@rustc $(RSFLAGS) $< -o $@

$(OBJDIR)/%_fasm.o: src/%.fasm
	@echo "    FA\t$<"
	@fasm $< $@ > /dev/null

clean:
	@clear
	@echo "    RM\tkernel.elf"
	@rm -f kernel.elf

config:
	@echo "    GEN\tconfig.h"
	@$$SHELL ./genconfig.sh
