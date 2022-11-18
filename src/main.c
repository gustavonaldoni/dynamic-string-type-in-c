#include <stdio.h>
#include <string_type.h>

int main(void)
{
    String s1 = stringCreate("String test!");
    String s2 = stringCopy(s1);
    String s3 = stringCut(s2, 0, 7);

    printf("s1 = %s\n", s1.content);
    printf("s2 = %s\n", s2.content);
    printf("s3 = %s\n", s3.content);

    return 0;
}