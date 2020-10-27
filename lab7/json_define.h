#ifndef JSON_DEF
#define JSON_DEF
#endif
#include <stddef.h>
#include <stdbool.h>

typedef enum CategoryEnum {
    OBJECT, ARRAY, STRING, NUMBER, BOOLEAN, VNULL
} CategoryEnum;

typedef union JsonValue {
        struct ObjectMember *member;
        struct ArrayValue *values;
        char *string;
        double number;
        bool boolean;
} JsonValue;

typedef struct JsonObject {
    enum CategoryEnum category;
    union JsonValue jsonValue;
} JsonObject;

typedef struct ObjectMember {
    char *key;
    struct JsonObject *value;
    struct ObjectMember *next;
} ObjectMember;

typedef struct ArrayObject {
    struct JsonObject *value;
    struct ArrayObject *next;
} ArrayObject;
