#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>

int compute_occ(char c, char str[])
{
    int len = strlen(str);
    int result = 0;
    int i;

    for(i=0;i<len;i++)
    {
        if(str[i] == c)
            result++;
    }
    return result;
}

main ()
{
    char text[101];
    int i, len=strlen(text);

    fgets(text,1001,stdin);

    for(i=0;i<len;i++)
    {
        char c = text[i];
        c=tolower(c);
        text[i]=c;
    }
    bool seen[256];
    for(i=0;i<256;i++)
    {
        seen[i] = false;
    }
    for(i=0;i<len;i++)
    {
        char c=text[i];
        int occs = compute_occ(c,text);
        if(seen[c] == true)
            continue;
        seen[c] = true;
        if (occs>0)
        {
            printf("%c: %d | ",c,occs);
        }
    }

}
