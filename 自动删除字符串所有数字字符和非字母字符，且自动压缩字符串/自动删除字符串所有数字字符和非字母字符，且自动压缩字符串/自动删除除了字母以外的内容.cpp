#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void Dele(char* str)
{   
    int i = 0;
    int j = 0;
    for (; *(str + i) != '\0'; i++)
    {
        if ((*(str + i) >= 'a' && *(str + i) <= 'z') || (*(str + i) >= 'A' && *(str + i) <= 'Z'))
        {
            *(str + j) = *(str + i);
            j++;
        }
    }
     *(str + j) = '\0';

   
  
    }



int main()
{
    char str[40] = { 0 };
    printf("ÇëÊäÈë×Ö·û´®:>");
    scanf("%s", str);
    Dele(str);
    printf("´¦ÀíºóµÄ×Ö·û´®:>%s",str);



    return 0;
}