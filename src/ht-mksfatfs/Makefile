.PHONY: all

SRCFILES   := mksfatfs.c

T_CC_FLAGS := -Wall -O2 -D_FILE_OFFSET_BITS=64

include ${T_BASE}/mk/comph.mk
include ${T_BASE}/mk/template.mk

all: ${T_OBJ}/tools-mksfatfs

${T_OBJ}/tools-mksfatfs: ${OBJFILES}
	@echo LD $@
	${V}${CC} -o $@ $^
