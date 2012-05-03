
#include "mod.h"
#include <syscall.h>

void init_module(const char *name) {
    sys_init_module(name);
}

void cleanup_module(const char *name) {
    sys_cleanup_module(name);
}
