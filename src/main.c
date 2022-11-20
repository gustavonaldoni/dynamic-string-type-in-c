#include <stdio.h>
#include <string_type.h>

int main(void)
{
    String s1 = stringCreate("String test!");
    String s2 = stringCopy(s1);
    String s3 = stringCut(s2, 0, 7);
    String s4 = stringCreate("   AAAAAAAA A     ");
    String trimmed = stringTrim(s4);

    String s5 = stringCreate("STRING BABY!");
    String s6 = stringCreate("BA");

    String s7 = stringCreate("original");
    String s8 = stringCreate("ginal");
    String s9 = stringCreate("");
    String replaced = stringReplace(s7, s8, s9);

    printf("s1 = %s\n", s1.content);
    printf("s2 = %s\n", s2.content);
    printf("s3 = %s\n", s3.content);
    printf("trimmed = %s\n", trimmed.content);
    printf("stringContains(s5, s6) = %d\n\n", stringContains(s5, s6));

    printf("s7 = %s\n", s7.content);
    printf("stringReplace(s7, s8, s9) = %s\n", replaced.content);

    stringDestroy(&s1);
    stringDestroy(&s2);
    stringDestroy(&s3);
    stringDestroy(&s4);
    stringDestroy(&trimmed);
    stringDestroy(&s5);
    stringDestroy(&s6);
    stringDestroy(&s7);
    stringDestroy(&s8);
    stringDestroy(&s9);
    stringDestroy(&replaced);

    return 0;
}