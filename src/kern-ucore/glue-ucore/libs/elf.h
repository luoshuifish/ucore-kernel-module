#ifndef __LIBS_ELF_H__
#define __LIBS_ELF_H__

#include <types.h>

#ifdef __BIG_ENDIAN__
#define ELF_MAGIC   0x7F454C46U         // "\x7FELF" in big endian
#else
#define ELF_MAGIC   0x464C457FU         // "\x7FELF" in little endian
#endif

#ifdef __UCORE_64__

/* file header */
struct elfhdr {
    uint32_t e_magic;     // must equal ELF_MAGIC
    uint8_t e_elf[12];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
}__attribute__((packed));

/* program section header */
struct proghdr {
    uint32_t p_type;
    uint32_t p_flags;
    uint64_t p_offset;
    uint64_t p_va;
    uint64_t p_pa;
    uint64_t p_filesz;
    uint64_t p_memsz;
    uint64_t p_align;
};

struct secthdr {
     uint32_t sh_name;
     uint32_t sh_type;
     uint64_t sh_flags;
     uint64_t sh_addr;
     uint64_t sh_offset;
     uint64_t sh_size;
     uint32_t sh_link;
     uint32_t sh_info;
     uint64_t sh_addralign;
     uint64_t sh_entsize;
}__attribute__((packed));

struct reloc_s {
    uint64_t rl_offset;         /* Location at which to apply the action */
    uint64_t rl_info;           /* index and type of relocation */
} __attribute__((packed));

struct reloc_a_s {
    uint64_t rl_offset;         /* Location at which to apply the action */
    uint64_t rl_info;           /* index and type of relocation */
    int64_t rl_addend;          /* Constant addend used to compute value */
} __attribute__((packed));

struct symtab_s {
    uint32_t sym_name;
    uint8_t  sym_info;
    uint8_t  sym_other;
    uint16_t sym_shndx;
    uint64_t sym_address;
    uint64_t sym_size;
} __attribute__((packed));

#define SH_TYPE_NULL   0
#define SH_TYPE_PROGBITS 1
#define SH_TYPE_SYMTAB 2
#define SH_TYPE_STRTAB 3
#define SH_TYPE_RELA   4
#define SH_TYPE_HASH   5
#define SH_TYPE_DYNAMIC 6
#define SH_TYPE_NOTE   7
#define SH_TYPE_NOBITS 8
#define SH_TYPE_REL  9

#define SHN_UNDEF 0
#define SHN_COMMON 0xfff2

#define GET_RELOC_SYM(i) ((i)>>32)
#define GET_RELOC_TYPE(i) ((i)&0xffffffff)

#define GET_SYMTAB_BIND(i) ((i) >> 4)
#define GET_SYMTAB_TYPE(i) ((i) & 0xf)

// symbol table bindings
#define STB_LOCAL 0
#define STB_GLOBAL 1
#define STB_WEAK 2
#define STB_LOPROC 13
#define STB_HIPROC 15

// symbol table type
#define STT_NOTYPE 0
#define STT_OBJECT 1
#define STT_FUNC   2
#define STT_SECTION 3
#define STT_FILE   4
#define STT_LOPROC 13
#define STT_HIPROC 15

/* values for Proghdr::p_type */
#define ELF_PT_LOAD                     1

/* flag bits for Proghdr::p_flags */
#define ELF_PF_X                        1
#define ELF_PF_W                        2
#define ELF_PF_R                        4

#else /* __UCORE_64__ not defined */

struct elfhdr {
    uint32_t e_magic;     // must equal ELF_MAGIC
    uint8_t e_elf[12];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint32_t e_entry;
    uint32_t e_phoff;
    uint32_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
};

/* program section header */
struct proghdr {
    uint32_t p_type;
    uint32_t p_offset;
    uint32_t p_va;
    uint32_t p_pa;
    uint32_t p_filesz;
    uint32_t p_memsz;
    uint32_t p_flags;
    uint32_t p_align;
};

#endif /* __UCORE_64__ */

/* values for Proghdr::p_type */
#define ELF_PT_LOAD                     1

/* flag bits for Proghdr::p_flags */
#define ELF_PF_X                        1
#define ELF_PF_W                        2
#define ELF_PF_R                        4

#endif /* !__LIBS_ELF_H__ */

