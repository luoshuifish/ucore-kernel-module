#include <types.h>
#include <ffs.h>
#include <error.h>
#include <assert.h>
#include <ffconf.h>
#include <kio.h>
#include <vfs.h>

/*
void
ffs_init(void) {
    int ret;
    if ((ret = ffs_mount("disk0")) != 0) {
        panic("failed: ffs: ffs_mount: %e.\n", ret);
    }
}
*/

void init_module() {
	int ret;
    kprintf("[ MM ] init mod-fatfs\n");
    if ((ret = register_filesystem("fatfs", ffs_mount)) != 0) {
    	panic("failed: fatfs: register_filesystem: %e.\n", ret);
    }
    kprintf("[ MM ] init mod-fatfs done\n");
}

void cleanup_module() {
	int ret;
    kprintf("[ MM ] cleanup mod-fatfs\n");
    if ((ret = unregister_filesystem("fatfs")) != 0) {
    	panic("failed: fatfs: unregister_filesystem: %e.\n", ret);
    }
    kprintf("[ MM ] cleanup mod-fatfs done\n");
}


#if _FS_REENTRANT

bool ff_cre_syncobj(
	BYTE _vol,
	_SYNC_t *sobj
)
{
	bool ret = false;
	return ret;
}

bool ff_del_syncobj(
	_SYNC_t sobj
)
{
	bool ret = false;
	return ret;
}

bool ff_req_grant(
	_SYNC_t sobj
)
{
	bool ret = false;
	return ret;
}

void ff_rel_grant(
	_SYNC_t sobj
)
#endif

#if _USE_LFN == 3
void* ff_memalloc(
	UINT size
)
{
	return malloc(size);
}

void ff_memfree(
	void* mblock
)
{
	free(mblock);
}
#endif
