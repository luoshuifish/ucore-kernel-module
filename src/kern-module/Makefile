E_ENCODE = $(shell echo $(1) | sed -e 's!_!_1!g' -e 's!/!_2!g')
E_DECODE = $(shell echo $(1) | sed -e 's!_1!_!g' -e 's!_2!/!g')

.PHONY: all

include ${T_BASE}/mk/compk.mk

SRCFILES := $(shell ls -F | grep '/$'')
OBJFILES := $(addprefix ${T_OBJ}/user-sfs/kern-module/, ${SRCFILES:/=.ko})

INC := arch/${ARCH}/glue-ucore arch/${ARCH}/driver arch/${ARCH}/debug arch/${ARCH}/glue-ucore/libs glue-ucore glue-ucore/libs libs debug driver mm sync schedule process fs \
	fs/swap fs/vfs fs/pipe fs/sfs fs/devs module glue-ucore/libs/x86

C_FLAGS := $(addprefix -I../kern-ucore/, ${INC})
C_FLAGS += -Imod-sfatfs -Imod-fatfs -I../glue-kern/arch/${ARCH} -Wall -Werror -O2

all: ${T_OBJ}/user-sfs/kern-module ${OBJFILES}

${T_OBJ}/user-sfs/kern-module/mod-add.ko:
	@echo CC $@
	${V}${CC} ${C_FLAGS} -c mod-add/mod_main.c -o $@

${T_OBJ}/user-sfs/kern-module/mod-mul.ko:
	@echo CC $@
	${V}${CC} ${C_FLAGS} -c mod-add/mod_main.c -o $@

${T_OBJ}/user-sfs/kern-module/mod-sfatfs.ko: ${T_OBJ}/user-sfs/kern-module/sfatfs.o ${T_OBJ}/user-sfs/kern-module/sfatfs_fs.o ${T_OBJ}/user-sfs/kern-module/sfatfs_inode.o ${T_OBJ}/user-sfs/kern-module/sfatfs_io.o ${T_OBJ}/user-sfs/kern-module/sfatfs_lock.o  
	@echo LD $@
	${V}${LD} -r -o $@ ${T_OBJ}/user-sfs/kern-module/sfatfs.o ${T_OBJ}/user-sfs/kern-module/sfatfs_fs.o ${T_OBJ}/user-sfs/kern-module/sfatfs_inode.o ${T_OBJ}/user-sfs/kern-module/sfatfs_io.o ${T_OBJ}/user-sfs/kern-module/sfatfs_lock.o

${T_OBJ}/user-sfs/kern-module/mod-fatfs.ko: ${T_OBJ}/user-sfs/kern-module/diskio.o ${T_OBJ}/user-sfs/kern-module/ffs.o ${T_OBJ}/user-sfs/kern-module/ffs_fs.o ${T_OBJ}/user-sfs/kern-module/ffs_inode.o ${T_OBJ}/user-sfs/kern-module/ffs_lock.o ${T_OBJ}/user-sfs/kern-module/ff.o
	@echo LD $@
	${V}${LD} -r -o $@ ${T_OBJ}/user-sfs/kern-module/diskio.o ${T_OBJ}/user-sfs/kern-module/ffs.o ${T_OBJ}/user-sfs/kern-module/ffs_fs.o ${T_OBJ}/user-sfs/kern-module/ffs_inode.o ${T_OBJ}/user-sfs/kern-module/ffs_lock.o ${T_OBJ}/user-sfs/kern-module/ff.o


${T_OBJ}/user-sfs/kern-module/sfatfs.o:
	@echo CC $@
	${V}${CC} ${C_FLAGS} -c mod-sfatfs/sfatfs.c -o $@

${T_OBJ}/user-sfs/kern-module/sfatfs_fs.o:
	@echo CC $@
	${V}${CC} ${C_FLAGS} -c mod-sfatfs/sfatfs_fs.c -o $@

${T_OBJ}/user-sfs/kern-module/sfatfs_inode.o:
	@echo CC $@
	${V}${CC} ${C_FLAGS} -c mod-sfatfs/sfatfs_inode.c -o $@

${T_OBJ}/user-sfs/kern-module/sfatfs_io.o:
	@echo CC $@
	${V}${CC} ${C_FLAGS} -c mod-sfatfs/sfatfs_io.c -o $@

${T_OBJ}/user-sfs/kern-module/sfatfs_lock.o:
	@echo CC $@
	${V}${CC} ${C_FLAGS} -c mod-sfatfs/sfatfs_lock.c -o $@


${T_OBJ}/user-sfs/kern-module/diskio.o:
	@echo CC $@
	${V}${CC} ${C_FLAGS} -c mod-fatfs/diskio.c -o $@

${T_OBJ}/user-sfs/kern-module/ffs.o:
	@echo CC $@
	${V}${CC} ${C_FLAGS} -c mod-fatfs/ffs.c -o $@

${T_OBJ}/user-sfs/kern-module/ffs_fs.o: 
	@echo CC $@
	${V}${CC} ${C_FLAGS} -c mod-fatfs/ffs_fs.c -o $@

${T_OBJ}/user-sfs/kern-module/ffs_inode.o: 
	@echo CC $@
	${V}${CC} ${C_FLAGS} -c mod-fatfs/ffs_inode.c -o $@

${T_OBJ}/user-sfs/kern-module/ffs_lock.o:
	@echo CC $@
	${V}${CC} ${C_FLAGS} -c mod-fatfs/ffs_lock.c -o $@

${T_OBJ}/user-sfs/kern-module/ff.o:
	@echo CC $@
	${V}${CC} ${C_FLAGS} -c mod-fatfs/ff.c -o $@

${T_OBJ}/user-sfs/kern-module:
	${V}mkdir -p $@
	${V}cp mod.dep $@/
