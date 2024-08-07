#include <initrd.h>
#include <tar.h>

initrd_t initrd;

initrd_t initrd_init(BOOTBOOT bootboot)
{
    return (initrd_t)bootboot.initrd_ptr;
}

void *initrd_get(initrd_t initrd, char *fp)
{
    // if exception, it will be passed through this function
    return (void*)tar_getptr(initrd, fp);
}
