#include <tar.hh>
#include <uart.hh>
#include <mem.hh>
#include <math.hh>
#include <cpu.hh>

void tar::readfile(tarball_t tarball, char *fp, char *buff) {
    // fisrt find the file name
    for (tar_file_t *file = tarball; file->header.name[0] != '\0'; file++) {
        if (str::cmp(file->header.name, fp) == 0) {
            // then find the file data
            for (char *data = file->data; data[0] != '\0'; data++) {
                mem::copy(buff, data, otoi(file->header.size));
                buff[otoi(file->header.size)] = '\0';
                return;
            }
        }
    }
    uart::cout << "FileNotFoundError\n";
    cpu::halt();
}

void *tar::getptr(tarball_t tarball, char *fp) {
    // fisrt find the file name
    for (tar_file_t *file = tarball; file->header.name[0] != '\0'; file++) {
        if (str::cmp(file->header.name, fp) == 0) {
            return file->data;
        }
    }
    uart::cout << "file not found\n";
    cpu::halt();
}

/*
void print_tarball_header(tar_file_t *file) {
    // print all the header fields
    uart_puts("name: "); uart_puts(file->header.name); uart_puts("\n");
    uart_puts("mode: "); uart_puts(file->header.mode); uart_puts("\n");
    uart_puts("uid: "); uart_puts(file->header.uid); uart_puts("\n");
    uart_puts("gid: "); uart_puts(file->header.gid); uart_puts("\n");
    uart_puts("size: "); uart_puts(file->header.size); uart_puts("\n");
    uart_puts("mtime: "); uart_puts(file->header.mtime); uart_puts("\n");
    uart_puts("checksum: "); uart_puts(file->header.chksum); uart_puts("\n");
    uart_puts("type: "); uart_puts(file->header.typeflag == TDIR ? "dir" : "file"); uart_puts("\n");
    uart_puts("linkname: "); uart_puts(file->header.linkname); uart_puts("\n");
    uart_puts("ustar: "); uart_puts(file->header.magic); uart_puts("\n");
    uart_puts("version: "); uart_puts(file->header.version); uart_puts("\n");
    uart_puts("uname: "); uart_puts(file->header.uname); uart_puts("\n");
    uart_puts("gname: "); uart_puts(file->header.gname); uart_puts("\n");
    uart_puts("devmajor: "); uart_puts(file->header.devmajor); uart_puts("\n");
    uart_puts("devminor: "); uart_puts(file->header.devminor); uart_puts("\n");
    uart_puts("prefix: "); uart_puts(file->header.prefix); uart_puts("\n\n");
} */

/*
tarball_t next_tarball(tarball_t tarball) {
    size_t size = otoi(tarball->header.size);
    tarball += ceil(size, 512) / 512 + 1;

    uart_puts("Skipping ");
    uart_puthex(ceil(size, 512) / 512 + 1);
    uart_puts(" tar blocks\n");

    if (tarball->header.name[0] == '\0')
        return NULL;
    return tarball;
} */

/*
tarball_t filter_buggy_tarball(tarball_t tarball) {
    // it name ends with "."
    if (tarball == NULL)
        return NULL;
    uart_puts("Tarfile to filter: ");
    uart_puts(tarball->header.name);
    uart_puts("\n");
    int length = strlen(tarball->header.name);
    if (tarball->header.name[length - 1] == '.') {
        uart_puts("Filter!\n");
        return filter_buggy_tarball(next_tarball(tarball));
    }
    uart_puts("Not Filter!\n");
    return tarball;
} */

/*
void list_tarball(tarball_t tarball) {
    while (tarball != NULL) {
        tarball = filter_buggy_tarball(tarball);
        if (tarball == NULL)
            break;
        print_tarball_header(tarball);
        tarball = next_tarball(tarball);
    }
    uart_puts("Done!\n");
} */
