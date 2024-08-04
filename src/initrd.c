#include <initrd.h>
#include <tar.h>

initrd_t initrd_init(tarball_t tarball)
{
    return tarball;
}

void *initrd_get(initrd_t initrd, char *fp)
{
    // if exception, it will be passed through this function
    return (void*)tar_getptr(initrd, fp);
}
