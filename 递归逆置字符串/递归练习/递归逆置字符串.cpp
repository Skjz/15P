#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int My_Strlen(char* chArr)
{
    if (*chArr != '\0')
    {
        return 1 + My_Strlen(chArr + 1);
    }
    else
    {
        return 0;
    }
}
void Reverse_Str(char* chArr)
{
    char temp = 0;
    temp = chArr[0];
    int lenth = My_Strlen(chArr);
    chArr[0] = chArr[ lenth -1];
    chArr[lenth - 1] = '\0';
    if (My_Strlen(chArr+1) >= 2)
    {
        Reverse_Str(chArr + 1);
    }
    chArr[lenth - 1] = temp;

}
int main()
{
    char chArr[6] = { "abcde" };
    Reverse_Str(chArr);
    printf("%s",chArr);



    return 0;
}