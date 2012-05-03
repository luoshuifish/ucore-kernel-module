E_ENCODE = $(shell echo $(1) | sed -e 's!_!_1!g' -e 's!/!_2!g')
E_DECODE = $(shell echo $(1) | sed -e 's!_1!_!g' -e 's!_2!/!g')

.PHONY: all

include ${T_BASE}/mk/compk.mk

SRCFILES := $(shell find . '(' '!' -regex '.*/_.*' ')' -and -iname "*.c"  | sed -e 's!\./!!g')
OBJFILES := $(addprefix ${T_OBJ}/user-sfs/kern-module/, ${SRCFILES:/mod_main.c=.ko})

INC := glue-ucore glue-ucore/libs libs debug driver mm sync schedule process fs \
				fs/swap fs/vfs fs/pipe fs/sfs fs/devs syscall module glue-ucore/libs/x86

C_FLAGS := $(addprefix -I../kern-ucore/, ${INC})

all: ${T_OBJ}/user-sfs/kern-module ${OBJFILES}

${T_OBJ}/user-sfs/kern-module/%.ko:
	@echo CC $@
	${V}${CC} ${C_FLAGS} -c $*/mod_main.c -o$@

${T_OBJ}/user-sfs/kern-module:
	${V}mkdir -p $@
	${V}cp mod.dep $@/
