#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char *content;
} String;

String stringCreate(char *);
int stringDestroy(String *);
size_t stringLength(String);
String stringConcat(String, String);
String stringReplace(String, String, String);
String stringToLower(String);
String stringToUpper(String);
String stringCut(String, int, int);
String stringTrim(String);
int stringContains(String, String);
int stringStartsWith(String, String);
int stringEndsWith(String, String);
int stringAreEqual(String, String);
String stringCopy(String);
