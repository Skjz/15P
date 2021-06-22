#define _CRT_SECURE_NO_WARNINGS
#include"CSTUDENT.h"

int main()
{
    CSTUDENT stu1;
    CSTUDENT stu2("liming", 3, 97);
    CSTUDENT stu3(stu2);


    return 0;
}