#include "symtab.h"

/*
 * symbol table type, binary tree impl
 */
struct symtab {
    entry entry;
    struct symtab *left, *right;
};

// ************************************************************
//    Your implementation goes here
// ************************************************************

symtab *symtab_init(){
    symtab *root = malloc(sizeof(symtab));
    memset(root, '\0', sizeof(symtab));
    root->left = NULL;
    root->right = NULL;
    return root;
}

int symtab_insert(symtab *self, char *key, VAL_T value){
    if (strcmp(key, self->entry.key) < 0) {
        if (self->left == NULL) {
            symtab *symtab = symtab_init();
            entry_init(&(symtab->entry), key, value);
            self->left = symtab;
        } else {
            return symtab_insert(self->left, key, value);
        }
    } else if (strcmp(key, self->entry.key) > 0) {
        if (self->right == NULL) {
            symtab *symtab = symtab_init();
            entry_init(&(symtab->entry), key, value);
            self->right = symtab;
        } else {
            return symtab_insert(self->right, key, value);
        }
    } else {
        // fail
        return 0;
    }
    // success
    return 1;
}

VAL_T symtab_lookup(symtab *self, char *key){
    if (strcmp(key, self->entry.key) < 0) {
        if (self->left == NULL) {
            return -1;
        } else {
            // printf("search left child\n");
            return symtab_lookup(self->left, key);
        }
    } else if (strcmp(key, self->entry.key) > 0) {
        if (self->right == NULL) {
            return -1;
        } else {
            // printf("search right child\n");
            return symtab_lookup(self->right, key);
        }
    } else {
        // printf("FOUND = %d\n", self->entry.value);
        return self->entry.value;
    }
    return -1;
}

int del_success = 1;

symtab *deleteNode(symtab *self, char *key) {
    if (self == NULL) {
        del_success = 0;
        return NULL; 
    }
    if (strcmp(key, self->entry.key) == 0) {
        // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
        // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
        if (self->left == NULL) 
            return self->right; 
        // 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
        else if (self->right == NULL) 
            return self->left; 
        // 第五种情况：左右孩子节点都不为空，则将删除节点的左孩子放到删除节点的右孩子的最左面节点的左孩子的位置
        // 返回删除节点右孩子为新的根节点。
        else {  
            symtab* cur = self->right;
            while(cur->left != NULL) {
                cur = cur->left;
            }
            cur->left = self->left;
            self = self->right;
            return self;
        }
    }
    if (strcmp(key, self->entry.key) < 0)
        self->left = deleteNode(self->left, key);
    if (strcmp(key, self->entry.key) > 0)
        self->right = deleteNode(self->right, key);
    return self;
}

int symtab_remove(symtab *self, char *key){
    del_success = 1;
    deleteNode(self, key);
    return del_success;
}



int main(void) {
    symtab *root = symtab_init();
    printf("symtab_insert(root, \"10\", 10) = %d\n", symtab_insert(root, "10", 10));
    printf("symtab_insert(root, \"20\", 20) = %d\n", symtab_insert(root, "20", 20));
    printf("symtab_lookup(root, \"10\") = %d\n", symtab_lookup(root, "10"));
    printf("symtab_lookup(root, \"20\") = %d\n", symtab_lookup(root, "20"));
    printf("symtab_insert(root, \"10\", 10) = %d\n", symtab_insert(root, "10", 10));
    printf("symtab_remove(root, \"10\") = %d\n", symtab_remove(root, "10"));
    printf("symtab_remove(root, \"10\") = %d\n", symtab_remove(root, "10"));
    return 0;
}