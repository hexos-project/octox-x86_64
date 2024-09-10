#pragma once

#include "types.hh"

#define BOOT_MAGIC "BOOT"

namespace BOOT {
    /* default virtual addresses for level 0 and 1 static loaders */
    enum class virtaddr : u64 {
        BOOTBOOT_MMIO   = 0xfffffffff8000000,  /* memory mapped IO virtual address */
        BOOTBOOT_FB     = 0xfffffffffc000000,  /* frame buffer virtual address */
        BOOTBOOT_INFO   = 0xffffffffffe00000,  /* bootboot struct virtual address */
        BOOTBOOT_ENV    = 0xffffffffffe01000,  /* environment string virtual address */
        BOOTBOOT_CORE   = 0xffffffffffe02000,  /* core loadable segment start */
    };

    /* framebuffer pixel format, only 32 bits supported */
    enum class fbtype : u8 {
        FB_ARGB   = 0,
        FB_RGBA   = 1,
        FB_ABGR   = 2,
        FB_BGRA   = 3,
    };

    /* mmap entry, type is stored in least significant tetrad (half byte) of size
    * this means size described in 16 byte units (not a problem, most modern
    * firmware report memory in pages, 4096 byte units anyway). */
    nomangle
    struct MMapEnt {
        uint64_t   ptr;
        uint64_t   size;

        u8 type() const { return size & 0xF; }
        bool is_free() const { return (size & 0xF) == 1; }
    } __packed;

    enum class mmap : u8 {
        MMAP_USED     = 0,   /* don't use. Reserved or unknown regions */
        MMAP_FREE     = 1,   /* usable memory */
        MMAP_ACPI     = 2,   /* acpi memory, volatile and non-volatile as well */
        MMAP_MMIO     = 3,   /* memory mapped IO region */
    };

    constexpr u64 INITRD_MAXSIZE = 16; /* Mb */

    nomangle struct BOOTBOOT {
        /* first 64 bytes is platform independent */
        uint8_t    magic[4];    /* 'BOOT' magic */
        uint32_t   size;        /* length of bootboot structure, minimum 128 */
        uint8_t    protocol;    /* 1, static addresses, see PROTOCOL_* and LOADER_* above */
        uint8_t    fb_type;     /* framebuffer type, see FB_* above */
        uint16_t   numcores;    /* number of processor cores */
        uint16_t   bspid;       /* Bootsrap processor ID (Local APIC Id on x86_64) */
        int16_t    timezone;    /* in minutes -1440..1440 */
        uint8_t    datetime[8]; /* in BCD yyyymmddhhiiss UTC (independent to timezone) */
        uint64_t   initrd_ptr;  /* ramdisk image position and size */
        uint64_t   initrd_size;
        uint64_t   fb_ptr;      /* framebuffer pointer and dimensions */
        uint32_t   fb_size;
        uint32_t   fb_width;
        uint32_t   fb_height;
        uint32_t   fb_scanline;

        /* the rest (64 bytes) is platform specific */
        union {
            struct {
            uint64_t acpi_ptr;
            uint64_t smbi_ptr;
            uint64_t efi_ptr;
            uint64_t mp_ptr;
            uint64_t unused0;
            uint64_t unused1;
            uint64_t unused2;
            uint64_t unused3;
            } __packed x86_64;
            struct {
            uint64_t acpi_ptr;
            uint64_t mmio_ptr;
            uint64_t efi_ptr;
            uint64_t unused0;
            uint64_t unused1;
            uint64_t unused2;
            uint64_t unused3;
            uint64_t unused4;
            } __packed aarch64;
        } arch;

        /* from 128th byte, MMapEnt[], more records may follow */
        MMapEnt    mmap;
        /* use like this:
        * MMapEnt *mmap_ent = &bootboot.mmap; mmap_ent++;
        * until you reach bootboot->size, while(mmap_ent < bootboot + bootboot->size) */
    } __packed;
}
