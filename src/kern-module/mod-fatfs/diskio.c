/*-----------------------------------------------------------------------
/  Low level disk interface modlue include file
/-----------------------------------------------------------------------*/

#include "diskio.h"
#include "stdio.h"
#include <fs.h>
#include <ide.h>
#include <inode.h>


/*---------------------------------------*/
/* Prototypes for disk control functions */

int assign_drives (int st, int ed){
#if PRINTFSINFO
	kprintf("[FATFS], assign %d to %d\n", st, ed);
#endif
	return 1;
}
DSTATUS disk_initialize (BYTE drive){
#if PRINTFSINFO
	kprintf("[FATFS], disk_init on drive%d\n", drive);
#endif
	return 0;
}
DSTATUS disk_status (BYTE drive){
	//kprintf("[FATFS], disk_status on drive%d\n", drive);
	return 0;
}
DRESULT disk_read (BYTE drive, BYTE* buffer, DWORD sectorNumber, BYTE sectorCount){
	//kprintf("[FATFS], disk_read on drive%d\n", drive);
	//from dev_diso0.c read_blks
	int ret;
	if ((ret = ide_read_secs(DISK1_DEV_NO, sectorNumber, buffer, sectorCount)) != 0) {
        panic("disk1: read blkno = %d (sectno = %d), nblks = %d (nsecs = %d): 0x%08x.\n",
			  -1, sectorNumber, 0, sectorCount, ret);
    }
	return 0;
}
#if	_READONLY == 0
DRESULT disk_write (BYTE drive, const BYTE* buffer, DWORD sectorNumber, BYTE sectorCount){
	//kprintf("[FATFS], disk_write on drive%d\n", drive);
	int ret;
	if ((ret = ide_write_secs(DISK1_DEV_NO, sectorNumber, buffer, sectorCount)) != 0) {
		panic("disk1: write blkno = %d (sectno = %d), nblks = %d (nsecs = %d): 0x%08x.\n",
			  -1, sectorNumber, 0, sectorCount, ret);
	}
	return 0;
}
#endif
DRESULT disk_ioctl (BYTE drive, BYTE command, void* buffer){
	//kprintf("[FATFS], disk_ioctl on drive%d, command = %d\n", drive, command);
	return 0;
}

DWORD get_fattime (void){
	return ((DWORD)(2011 - 1980) << 25)
		| ((DWORD)3 << 21)
		| ((DWORD)26 << 16)
		| ((DWORD)19 << 11)
		| ((DWORD)28 << 5)
		| ((DWORD)0 << 1);
}


