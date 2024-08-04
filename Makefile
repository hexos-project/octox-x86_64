CFLAGS = -Wall -fpic -ffreestanding -fno-stack-protector -nostdinc -nostdlib -I./include -Wall -Wno-return-type -Wno-int-to-pointer-cast -Os
LDFLAGS =  -nostdlib -n -T link.ld
STRIPFLAGS =  -s -K mmio -K fb -K bootboot -K environment -K initstack

SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c,%.o,$(SOURCES))


all: config clean $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf
	strip $(STRIPFLAGS) kernel.elf

%.o: src/%.c
	gcc $(CFLAGS) -mno-red-zone -c $< -o $@

mrproper:
	rm -f *.o

clean: mrproper
	rm -f kernel.elf

config:
	$$SHELL ./genconfig.sh
