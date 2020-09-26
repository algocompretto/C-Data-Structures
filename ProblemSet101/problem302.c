#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    puts("Digite a data no formato dd/mm/yyyy");
    char date[20];
    int days,months, years;
    scanf("%d/%d/%d",&days,&months,&years);

    printf("%d",days + months * 30 + years * 360);
}
