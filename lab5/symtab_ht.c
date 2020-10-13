#include "symtab.h"

/*
 * symbol table type, hash table (close addressing) impl
 */
#define TABLE_SIZE 0xFFFFFFFF
struct _node {
    entry entry;
    struct _node *next;
};
#ifndef SYMTAB
typedef struct _node *symtab[TABLE_SIZE];
#define SYMTAB
#endif

// ************************************************************
//    Your implementation goes here
// ************************************************************
uint pjw_hash(const char* key) {
    uint bits_in_uint = (uint)(sizeof(uint) * 8);
    fprintf(stdout, "bits_in_uint = %d\n", bits_in_uint);
    uint three_quarters     = (uint)((bits_in_uint  * 3) / 4);
    uint one_eights         = (uint)(bits_in_uint / 8);
    uint high_bits          = (uint)(0xFFFFFFFF) << (bits_in_uint - one_eights);
    uint hash              = 0;
    uint test              = 0;

    for(size_t i = 0; i < strlen(key); i++)
    {
        hash = (hash << one_eights) + key[i];
        if((test = hash & high_bits)  != 0)
        {
            hash = (( hash ^ (test >> three_quarters)) & (~high_bits));
        }
    }
   return hash;
}


symtab *symtab_init(){
    // symtab *self = malloc(sizeof(symtab));
    // memset(self, '\0', sizeof(symtab));
    // return self;
}

int symtab_insert(symtab *self, char *key, VAL_T value){

}

VAL_T symtab_lookup(symtab *self, char *key){

}

int symtab_remove(symtab *self, char *key){

}

int main(int argc, char **argv) {
    fprintf(stdout, "hash for %s = %d\n", argv[1], pjw_hash(argv[1]));
    return 0;
}
