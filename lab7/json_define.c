#include "json_define.h"

JsonValue *newJsonValue() {
    union JsonValue *value;
    value = malloc(sizeof(JsonValue));
    return value;
}

JsonObject *newJsonObject(CategoryEnum category, JsonValue jsonValue) {
    enum CategoryEnum category = VNULL;
    JsonObject *jsonObject;
    jsonObject = malloc(sizeof(JsonObject));
    jsonObject->category = category;
    jsonObject->jsonValue = jsonValue;


    
    return jsonObject;
}

ObjectMember *newObjectMember(char *key, JsonObject *jsonObject) {
    union JsonValue *value = newJsonValue();
    ObjectMember *objectMember;
    objectMember = malloc(sizeof(ObjectMember));
    objectMember->key = key;
    objectMember->value = jsonObject;
    objectMember->next = NULL;
    return objectMember;
}

ArrayObject *newArrayObject(JsonObject *value) {
    ArrayObject *arrayObject;
    arrayObject = malloc(sizeof(ArrayObject));
    arrayObject->value = value;
    arrayObject->next = NULL;
    return arrayObject;
}

