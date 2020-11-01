#include "json_define.h"

Json *newJson() {
    Json *json;
    json = malloc(sizeof(Json));
    json->category = 
    return json;
}

Member *newMember() {
    Member *member;
    member = malloc(sizeof(Member));
    return member;
}

Array *newArray() {
    Array *array;
    array = malloc(sizeof(Array));
    return array;
}

