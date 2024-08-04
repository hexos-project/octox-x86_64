#pragma once
/* tar Header Block, from POSIX 1003.1-1990.  */

/* POSIX header.  */

#include "types.h"

#define TDIR 0x35
#define TFIL 0x30

typedef struct {
    char name[100];
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char mtime[12];
    char chksum[8];
    char typeflag;
    char linkname[100];
    char magic[6];
    char version[2];
    char uname[32];
    char gname[32];
    char devmajor[8];
    char devminor[8];
    char prefix[155];
    char pad[12];
} tar_header_t;

typedef struct {
    tar_header_t header;
    char data[];
} tar_file_t;

typedef tar_file_t *tarball_t;

void tar_readfile(tarball_t tarball, char *fp, char *buff);
void *tar_getptr(tarball_t tarball, char *fp);

extern error_t FileNotFoundError;
