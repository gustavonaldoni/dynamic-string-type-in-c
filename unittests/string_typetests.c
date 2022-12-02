#include "criterion/criterion.h"
#include "string_type.h"

/*
String stringCreate(char *); OK
int stringDestroy(String *); OK
size_t stringLength(String); OK
char stringCharAt(String, unsigned int); OK
String stringConcat(String, String); OK
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
int stringCounts(String, String);
String stringReverse(String);
int stringFirstIndexOf(String, char);
int stringLastIndexOf(String, char);
*/

Test(stringTests, creation)
{
    String baseString = stringCreate("Base string!");
    cr_expect(strcmp(baseString.content, "Base string!") == 0);
    stringDestroy(&baseString);
}

Test(stringTests, destruction)
{
    String string = stringCreate("Some string");
    int res = stringDestroy(&string);
    cr_expect(res == 1);
}

Test(stringTests, length)
{
    String string1 = stringCreate("AAAAAA");
    String string2 = stringCreate("");
    String string3 = stringCreate("A");

    cr_expect(stringLength(string1) == 6);
    cr_expect(stringLength(string2) == 0);
    cr_expect(stringLength(string3) == 1);

    stringDestroy(&string1);
    stringDestroy(&string2);
    stringDestroy(&string3);
}

Test(stringTests, charAt)
{
    String string = stringCreate("ABC DE.");

    cr_expect(stringCharAt(string, 0) == 'A');
    cr_expect(stringCharAt(string, 1) == 'B');
    cr_expect(stringCharAt(string, 2) == 'C');
    cr_expect(stringCharAt(string, 3) == ' ');
    cr_expect(stringCharAt(string, 4) == 'D');
    cr_expect(stringCharAt(string, 5) == 'E');
    cr_expect(stringCharAt(string, 6) == '.');

    stringDestroy(&string);
}

Test(stringTests, concat)
{
    String string1 = stringCreate("AAAA");
    String string2 = stringCreate("BB");
    String empty = stringCreate("");

    String c1 = stringConcat(string2, string1);
    String c2 = stringConcat(string1, string2);
    String c3 = stringConcat(string1, empty);
    String c4 = stringConcat(empty, empty);

    cr_expect(strcmp(c1.content, "AAAABB") == 0);
    cr_expect(strcmp(c2.content, "BBAAAA") == 0);
    cr_expect(strcmp(c3.content, "AAAA") == 0);
    cr_expect(strcmp(c4.content, "") == 0);

    stringDestroy(&string1);
    stringDestroy(&string2);
    stringDestroy(&empty);
    stringDestroy(&c1);
    stringDestroy(&c2);
    stringDestroy(&c3);
    stringDestroy(&c4);
}

Test(stringTests, replace)
{
    String s1 = stringCreate("American");
    String s2 = stringCreate("eri");

    String s3 = stringCreate("XXX");
    String s4 = stringCreate("XXXX");
    String s5 = stringCreate("X");
    String empty = stringCreate("");
    String end = stringCreate("an");

    String r1 = stringReplace(s1, s2, s3);
    String r2 = stringReplace(s1, s2, s4);
    String r3 = stringReplace(s1, s2, s5);
    String r4 = stringReplace(s1, s2, empty);
    String r5 = stringReplace(s1, s1, empty);
    String r6 = stringReplace(s1, end, empty);

    cr_expect(strcmp(r1.content, "AmXXXcan") == 0);
    cr_expect(strcmp(r2.content, "AmXXXXcan") == 0);
    cr_expect(strcmp(r3.content, "AmXcan") == 0);
    cr_expect(strcmp(r4.content, "Amcan") == 0);
    cr_expect(strcmp(r5.content, "") == 0);
    cr_expect(strcmp(r6.content, "Americ") == 0);

    stringDestroy(&s1);
    stringDestroy(&s2);
    stringDestroy(&s3);
    stringDestroy(&s4);
    stringDestroy(&s5);
    stringDestroy(&empty);
    stringDestroy(&end);
    stringDestroy(&r1);
    stringDestroy(&r2);
    stringDestroy(&r3);
    stringDestroy(&r4);
    stringDestroy(&r5);
    stringDestroy(&r6);
}