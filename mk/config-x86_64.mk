QEMU            		?= qemu-system-x86_64
export HOST_CC_PREFIX	?=
export TARGET_CC_PREFIX	?= x86_64-elf-
export TARGET_CC_FLAGS_COMMON	?=	-ffreestanding \
									-mno-red-zone \
									-mno-mmx -mno-sse -mno-sse2 \
									-mno-sse3 -mno-3dnow \
									-fno-builtin -fno-builtin-function -nostdinc
export TARGET_CC_FLAGS_BL		?=	-m32
export TARGET_CC_FLAGS_KERNEL	?=	-m64 -mcmodel=kernel
export TARGET_CC_FLAGS_SV		?=	-m64 -mcmodel=large
export TARGET_CC_FLAGS_USER		?=	-m64 -mcmodel=small
export TARGET_LD_FLAGS			?=	-m $(shell $(TARGET_CC_PREFIX)ld -V | grep elf_x86_64 2>/dev/null) -nostdlib

qemu: all

	${QEMU} -parallel stdio \
	-smp 4 -m 512 \
	-hda ${T_OBJ}/kernel.img \
	-drive file=${T_OBJ}/swap.img,media=disk,cache=writeback \
	-drive file=${T_OBJ}/sfs.img,media=disk,cache=writeback \
	-drive file=${T_OBJ}/sfatfs.img,media=disk,cache=writeback \
	-drive file=${T_OBJ}/sfs2.img,media=disk,cache=writeback \
	-s 

debug: all
	${V}${TARGET_CC_PREFIX}gdb -q -x gdbinit.${ARCH}
