#include <initrd.hh>
#include <tar.hh>

initrd_t _initrd;

void initrd::init(BOOT::BOOTBOOT bootboot)
{
    _initrd = (initrd_t)bootboot.initrd_ptr;
}

void *initrd::get(initrd_t initrd, char *fp)
{
    // if exception, it will be passed through this function
    return (void*)tar::getptr(initrd, fp);
}
