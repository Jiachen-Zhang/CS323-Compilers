#ifndef JSON_DEF
#define JSON_DEF
#endif
#include <stddef.h>
#include <stdbool.h>

enum Category {_OBJECT, _ARRAY, _STRING, _NUMBER, _BOOLEAN, _VNULL} Category;

typedef struct Json {
    enum Category category;
    union Value {
        struct Member *member;
        struct Array *values;
        char *string;
        double number;
        bool boolean;
    } value;
} Json;

typedef struct Member {
    char *key;
    struct Json *json;
    struct Member *next;
} Member;

typedef struct Array {
    struct Json *json;
    struct Array *next;
} Array;
