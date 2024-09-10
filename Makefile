CFLAGS = -Wall -fpic -ffreestanding -fno-stack-protector -nostdinc -nostdlib -I./include -Wall -Wno-return-type -Wno-int-to-pointer-cast -Os -Wall -Werror -Wno-parentheses
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
LDFLAGS =  -nostdlib -n -T link.ld
STRIPFLAGS =  -s -K mmio -K fb -K bootboot -K environment -K initstack
OBJDIR = objects

CPPSOURCES = $(shell find src -name '*.cc' -not -name '.*')
OBJECTS = $(patsubst src/%.cc,$(OBJDIR)/%.o,$(CPPSOURCES))
SOURCES = $(CPPSOURCES)


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

$(OBJDIR)/%.o: src/%.cc
	@echo "    CX\t$<"
	@g++ $(CXXFLAGS) -mno-red-zone -c $< -o $@

clean:
	@clear
	@echo "    RM\tkernel.elf"
	@rm -f kernel.elf

config:
	@echo "    GEN\tconfig.hh"
	@$$SHELL ./genconfig.sh
