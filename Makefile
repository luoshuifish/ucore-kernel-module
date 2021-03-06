.PHONY: all clean qemu
.DEFAULT_GOAL	:= all

export ARCH				?= x86_64
export V        		:= 
export T_BASE   		?= ${PWD}
export T_OBJ    		?= ${PWD}/obj
export MAKE     		:= make -s

SUPPORTED_ARCH := i386 x86_64 um or32
ifneq (,$(findstring $(ARCH),$(SUPPORTED_ARCH)))
include mk/config-${ARCH}.mk
endif

export OBJDUMP			?= ${TARGET_CC_PREFIX}objdump
export OBJCOPY 			?= ${TARGET_CC_PREFIX}objcopy
export STRIP   			?= ${TARGET_CC_PREFIX}strip

export BRANCH   		?= ucore

HAS_DRIVER_OS   		?= n
ifneq (${HAS_DRIVER_OS},n)
override HAS_DRIVER_OS := y
endif
export HAS_DRIVER_OS

ifeq (${BRANCH},linux-dos-module)
all: ${T_OBJ}
	${V}${MAKE} -f mk/mods.mk all
else
ifeq (,$(findstring $(ARCH),$(SUPPORTED_ARCH)))
all:
	$(V)echo "*** ERROR: No architecture names \""$(ARCH)\"
else
all: ${T_OBJ}
	${V}${MAKE} -f mk/arch-${ARCH}.mk all
endif
endif

${T_OBJ}:
	@mkdir -p ${T_OBJ}

ifeq (${BRANCH},linux-dos-module)
clean:
	${V}${MAKE} -C src/linux-dos-module clean
	${V}rm -rf ${T_OBJ}/dosm.ko
else
clean:
	${V}rm -rf ${T_OBJ}/*
endif

