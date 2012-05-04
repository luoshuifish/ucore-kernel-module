#include <types.h>
#include <sfatfs.h>
#include <error.h>
#include <assert.h>
#include <mod.h>
#include <vfs.h>
#include <kio.h>

/*
void
sfatfs_init(void) {
    int ret;
    if ((ret = sfatfs_mount("disk1")) != 0) {
        panic("failed: sfatfs: sfatfs_mount: %e.\n", ret);
    }
}
*/

void init_module() {
	int ret;
    kprintf("[ MM ] init mod-sfatfs\n");
    if ((ret = register_filesystem("sfatfs", sfatfs_mount)) != 0) {
    	panic("failed: sfatfs: register_filesystem: %e.\n", ret);
    }
    kprintf("[ MM ] init mod-sfatfs done\n");
}

void cleanup_module() {
	int ret;
    kprintf("[ MM ] cleanup mod-sfatfs\n");
    if ((ret = unregister_filesystem("sfatfs")) != 0) {
    	panic("failed: sfatfs: unregister_filesystem: %e.\n", ret);
    }
    kprintf("[ MM ] cleanup mod-sfatfs done\n");
}
