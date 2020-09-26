#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

main ()
{
    char text1[101]="abcdefghijqlmnop";
    char text2[101];
    puts("Digite seu texto: ");
    gets(text1);
    if (strlen(text1)<10)
        return 0;
    strncpy(text2,text1 + 5,5);
    text2[5]='\0';
    puts(text2);
}
