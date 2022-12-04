#include "criterion/criterion.h"
#include "string_type.h"

Test(stringTests, create)
{
    String baseString = stringCreate("Base string!");
    cr_expect(strcmp(baseString.content, "Base string!") == 0);
    stringDestroy(&baseString);
}

Test(stringTests, destroy)
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
    cr_expect(stringCharAt(string, 49) == -1);

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

Test(stringTests, toLower)
{
    String s1 = stringCreate("aBcDeFg134");
    String s2 = stringCreate("adcvf");
    String s3 = stringCreate("1ç^S");

    String t1 = stringToLower(s1);
    String t2 = stringToLower(s2);
    String t3 = stringToLower(s3);

    cr_expect(strcmp(t1.content, "abcdefg134") == 0);
    cr_expect(strcmp(t2.content, "adcvf") == 0);
    cr_expect(strcmp(t3.content, "1ç^s") == 0);

    stringDestroy(&s1);
    stringDestroy(&s2);
    stringDestroy(&s3);
    stringDestroy(&t1);
    stringDestroy(&t2);
    stringDestroy(&t3);
}

Test(stringTests, toUpper)
{
    String s1 = stringCreate("aBcDeFg134");
    String s2 = stringCreate("ADC43");
    String s3 = stringCreate("1ç^sab");

    String t1 = stringToUpper(s1);
    String t2 = stringToUpper(s2);
    String t3 = stringToUpper(s3);

    cr_expect(strcmp(t1.content, "ABCDEFG134") == 0);
    cr_expect(strcmp(t2.content, "ADC43") == 0);
    cr_expect(strcmp(t3.content, "1ç^SAB") == 0);

    stringDestroy(&s1);
    stringDestroy(&s2);
    stringDestroy(&s3);
    stringDestroy(&t1);
    stringDestroy(&t2);
    stringDestroy(&t3);
}

Test(stringTests, cut)
{
    String s1 = stringCreate("This is a string!");
    String s2 = stringCreate("AaBbCcDdEeFfGg");

    String c1 = stringCut(s1, 0, 16);
    String c2 = stringCut(s1, 10, 13);
    String c3 = stringCut(s2, 2, 13);
    String c4 = stringCut(s2, 1, 1);
    String c5 = stringCut(s2, 0, 0);
    String c6 = stringCut(s2, 13, 13);

    String err1 = stringCut(s1, 10, 8);
    String err2 = stringCut(s1, -1, 8);
    String err3 = stringCut(s1, 4, 49);

    cr_expect(strcmp(c1.content, "This is a string!") == 0);
    cr_expect(strcmp(c2.content, "stri") == 0);
    cr_expect(strcmp(c3.content, "BbCcDdEeFfGg") == 0);
    cr_expect(strcmp(c4.content, "a") == 0);
    cr_expect(strcmp(c5.content, "A") == 0);
    cr_expect(strcmp(c6.content, "g") == 0);

    cr_expect(err1.content == NULL);
    cr_expect(err2.content == NULL);
    cr_expect(err3.content == NULL);

    stringDestroy(&s1);
    stringDestroy(&s2);
    stringDestroy(&c1);
    stringDestroy(&c2);
    stringDestroy(&c3);
    stringDestroy(&c4);
    stringDestroy(&c5);
    stringDestroy(&c6);
    stringDestroy(&err1);
    stringDestroy(&err2);
    stringDestroy(&err3);
}

Test(stringTests, trim)
{
    String s1 = stringCreate(" AaBb    ");
    String s2 = stringCreate("AaBb ");
    String s3 = stringCreate("   AaBb");
    String s4 = stringCreate("AaBb");

    String t1 = stringTrim(s1);
    String t2 = stringTrim(s2);
    String t3 = stringTrim(s3);
    String t4 = stringTrim(s4);

    cr_expect(strcmp(t1.content, "AaBb") == 0);
    cr_expect(strcmp(t2.content, "AaBb") == 0);
    cr_expect(strcmp(t3.content, "AaBb") == 0);
    cr_expect(strcmp(t4.content, "AaBb") == 0);

    stringDestroy(&s1);
    stringDestroy(&s2);
    stringDestroy(&s3);
    stringDestroy(&s4);
    stringDestroy(&t1);
    stringDestroy(&t2);
    stringDestroy(&t3);
    stringDestroy(&t4);
}

Test(stringTests, contains)
{
    String s1 = stringCreate("Abbccdefg13^");

    String c1 = stringCreate("Abbc");
    String c2 = stringCreate("Abc");
    String c3 = stringCreate("13^");
    String c4 = stringCreate("");
    String c5 = stringCreate("defg13");

    cr_expect(stringContains(s1, c1) == 0);
    cr_expect(stringContains(s1, c2) == -1);
    cr_expect(stringContains(s1, c3) == 9);
    cr_expect(stringContains(s1, c4) == -1);
    cr_expect(stringContains(s1, c5) == 5);

    stringDestroy(&s1);
    stringDestroy(&c1);
    stringDestroy(&c2);
    stringDestroy(&c3);
    stringDestroy(&c4);
    stringDestroy(&c5);
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

Test(stringTests, startsWith)
{
    String s1 = stringCreate("Abbccdefg13^");

    String i1 = stringCreate("Abbc");
    String i2 = stringCreate("123");
    String i3 = stringCreate("13^");
    String i4 = stringCreate("Ab");
    String i5 = stringCreate("Abbccdefg13^");
    String i6 = stringCreate("Abbccdefg13^9999");
    String i7 = stringCreate("");

    cr_expect(stringStartsWith(s1, i1) == 1);
    cr_expect(stringStartsWith(s1, i2) == 0);
    cr_expect(stringStartsWith(s1, i3) == 0);
    cr_expect(stringStartsWith(s1, i4) == 1);
    cr_expect(stringStartsWith(s1, i5) == 1);
    cr_expect(stringStartsWith(s1, i6) == 0);
    cr_expect(stringStartsWith(s1, i7) == 0);
    cr_expect(stringStartsWith(i7, s1) == 0);

    stringDestroy(&s1);
    stringDestroy(&i1);
    stringDestroy(&i2);
    stringDestroy(&i3);
    stringDestroy(&i4);
    stringDestroy(&i5);
    stringDestroy(&i6);
}

Test(stringTests, endsWith)
{
    String s1 = stringCreate("Abbccdefg13^");

    String e1 = stringCreate("Abbc");
    String e2 = stringCreate("123");
    String e3 = stringCreate("fg13^");
    String e4 = stringCreate("^");
    String e5 = stringCreate("Abbccdefg13^");
    String e6 = stringCreate("Abbccdefg13^9999");
    String e7 = stringCreate("");

    cr_expect(stringEndsWith(s1, e1) == 0);
    cr_expect(stringEndsWith(s1, e2) == 0);
    cr_expect(stringEndsWith(s1, e3) == 1);
    cr_expect(stringEndsWith(s1, e4) == 1);
    cr_expect(stringEndsWith(s1, e5) == 1);
    cr_expect(stringEndsWith(s1, e6) == 0);
    cr_expect(stringEndsWith(s1, e7) == 0);
    cr_expect(stringEndsWith(e7, s1) == 0);

    stringDestroy(&s1);
    stringDestroy(&e1);
    stringDestroy(&e2);
    stringDestroy(&e3);
    stringDestroy(&e4);
    stringDestroy(&e5);
    stringDestroy(&e6);
}

Test(stringTests, areEqual)
{
    String s1 = stringCreate("Ab12^cça*)");
    String s2 = stringCreate("Ab12^cça*)");
    String s3 = stringCreate("Ab^cça*");
    String s4 = stringCreate("ghhgdehgaaaaaaaaaaa");
    String s5 = stringCreate("");
    String s6 = stringCreate("");

    cr_expect(stringAreEqual(s1, s2) == 1);
    cr_expect(stringAreEqual(s1, s3) == 0);
    cr_expect(stringAreEqual(s1, s4) == 0);
    cr_expect(stringAreEqual(s1, s5) == 0);
    cr_expect(stringAreEqual(s5, s6) == 1);

    stringDestroy(&s1);
    stringDestroy(&s2);
    stringDestroy(&s3);
    stringDestroy(&s4);
    stringDestroy(&s5);
    stringDestroy(&s6);
}

Test(stringTests, createEmpty)
{
    String s1 = stringCreate("");
    String s2 = stringCreateEmpty();

    cr_expect(s2.content != NULL);
    cr_expect(stringAreEqual(s1, s2) == 1);

    stringDestroy(&s1);
    stringDestroy(&s2);
}

Test(stringTests, isEmpty)
{
    String s1 = stringCreate("");
    String s2 = stringCreate("Aa457643^vfcv");
    String s3 = stringCreate("&");

    cr_expect(stringIsEmpty(s1) == 1);
    cr_expect(stringIsEmpty(s2) == 0);
    cr_expect(stringIsEmpty(s3) == 0);

    stringDestroy(&s1);
    stringDestroy(&s2);
    stringDestroy(&s3);
}