#define _CRT_SECURE_NO_WARNINGS
#include"mypassword.h"
int  Login(char* Account, char* ThisPassword)
{   
    char account[20] = { 0 };
    char password[20] = "0";
    printf("ÇëÊäÈëÕËºÅ:>");
    scanf_s("%s",account,20 );
    printf("ÇëÊäÈëÃÜÂë:>");
    scanf_s("%s", password,20);
    int ret = 0;
    ret = strcmp(Account, account);
    if (ret == 0)
    {
        ret = strcmp(ThisPassword, password);
    }
    return ret;

}
