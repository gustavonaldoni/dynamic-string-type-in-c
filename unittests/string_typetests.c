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


