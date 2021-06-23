#define _CRT_SECURE_NO_WARNINGS
#include"CStudent.h"
#include"CSpider.h"

int main()
{
    CStudent s;
    char szName[20] = "liming";
    s.SetName(szName);
    s.SetAge(18);
    s.SetScore(22);
    s.Ablity();
    s.ShowEye();
    return 0;
}