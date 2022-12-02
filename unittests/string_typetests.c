#include "criterion/criterion.h"
#include "string_type.h"

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
