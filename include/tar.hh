#pragma once

#include "types.hh"

#define TDIR 0x35
#define TFIL 0x30

struct tar_header_t {
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
};

struct tar_file_t {
    tar_header_t header;
    char data[];
};

using tarball_t = tar_file_t *;

namespace tar {
    using header_t = tar_header_t;
    using file_t = tar_file_t;
    using tarball_t = tarball_t;
    void readfile(tarball_t tarball, char *fp, char *buff);
    void *getptr(tarball_t tarball, char *fp);
}
