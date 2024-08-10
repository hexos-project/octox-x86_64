#include <initrd.h>
#include <tar.h>

initrd_t _initrd;

void initrd_init(BOOTBOOT bootboot)
{
    _initrd = (initrd_t)bootboot.initrd_ptr;
}

void *initrd_get(initrd_t initrd, char *fp)
{
    // if exception, it will be passed through this function
    return (void*)tar_getptr(initrd, fp);
}
