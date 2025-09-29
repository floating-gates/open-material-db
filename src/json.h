#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Type of JSON values
typedef enum {
    TYPE_STRING,
    TYPE_NUMBER,
    TYPE_BOOL,
    TYPE_NULL,
    TYPE_OBJECT
} JsonType;

// Forward declaration
struct JsonValue;

typedef struct {
    char* key;
    struct JsonValue* value;
} JsonPair;

// JSON value structure
typedef struct JsonValue {
    JsonType type;
    union {
        char* stringValue;
        double numberValue;
        int boolValue;
        struct {
            JsonPair* pairs;
            int count;
        } objectValue;
    };
} JsonValue;


//////////////// Functions API

// Skip spaces and tabs
void skipSpaces(const char** text);

// Read string like "name"
char *readString(const char **text);

// Read number like 123
double readNumber(const char **text);

// Read true/false
int readBool(const char **text);

// Read value (string, number, bool, null, object)
JsonValue* readValue(const char** text);

// Read object like { "key": value, ... }
JsonValue *readObject(const char **text);

// Read any value
JsonValue *readValue(const char **text);

// Get value by path like "details.name"
JsonValue *getValue(JsonValue *root, const char *path);


char* loadFile(const char* filename);

// Get value by path like "details.name"
JsonValue* getValue(JsonValue* root, const char* path);

// Print value
void printValue(JsonValue* value); 
