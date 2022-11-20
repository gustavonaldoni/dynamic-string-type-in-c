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

    printf("s1 = %s\n", s1.content);
    printf("s2 = %s\n", s2.content);
    printf("s3 = %s\n", s3.content);
    printf("trimmed = %s\n", trimmed.content);
    printf("stringContains(s5, s6) = %d\n", stringContains(s5, s6));

    stringDestroy(&s1);
    stringDestroy(&s2);
    stringDestroy(&s3);
    stringDestroy(&s4);
    stringDestroy(&trimmed);
    stringDestroy(&s5);
    stringDestroy(&s6);

    return 0;
}