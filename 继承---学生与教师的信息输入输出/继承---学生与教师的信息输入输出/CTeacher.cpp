#include "CTeacher.h"
#include<stdio.h>
#include<stdlib.h>
CTeacher::CTeacher() :szTitle{0},szDepartment{0}
{

}
void CTeacher::SetTitle()
{
    printf("�������ʦְ��:>");
    scanf_s("%s", szTitle);
}
void CTeacher::GetTitle()
{
    printf("��ʦְ�ƣ�%s", szTitle);
}
void CTeacher::SetDepartment()
{
    printf("�������ʦ���ţ�%s", szDepartment);
    scanf_s("%s", szDepartment);
}
void CTeacher::GetDepartment()
{
    printf("��ʦ�����ǣ�%s", szDepartment);
}