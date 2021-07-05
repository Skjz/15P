#include "CTeacher.h"
#include<stdio.h>
#include<stdlib.h>
CTeacher::CTeacher() :szTitle{0},szDepartment{0}
{

}
void CTeacher::SetTitle()
{
    printf("请输入教师职称:>");
    scanf_s("%s", szTitle);
}
void CTeacher::GetTitle()
{
    printf("教师职称：%s", szTitle);
}
void CTeacher::SetDepartment()
{
    printf("请输入教师部门：%s", szDepartment);
    scanf_s("%s", szDepartment);
}
void CTeacher::GetDepartment()
{
    printf("教师部门是：%s", szDepartment);
}