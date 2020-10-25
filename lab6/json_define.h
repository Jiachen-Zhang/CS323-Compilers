typedef struct Json {
    struct Value *value;
    char *name;
    enum {OBJECT, ARRAY, STRING, INT, DOUBLE, BOOLEAN, VNULL} category;
} Json;

typedef struct Value {
    union value
    {
        struct Object *object;
        struct Array *arrayl;
        char *string;
        int intNum;
        double floatNum;
        enum {True, False} boolean;
        enum {NULL} null;
    };
} Value;

typedef struct Object {
    struct Member **member;
    int size;
} Object;

typedef struct Member {
    char *key;
    struct Value *value;
} Member;

typedef struct Array {
    struct Value **base;
    int size;
} Array;
