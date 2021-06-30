#include<stdio.h>
#include "CRectangle.h"

void CRectangle::Area()
{
    printf("请输入长度:>");
    scanf_s("%d", &m_nLenth);
    printf("请输入宽度:>");
    scanf_s("%d", &m_nWidth);
    m_nRectArea = m_nLenth * m_nWidth;
}
//void CRectangle::SetLenth(int nLenth)
//{
//    m_nLenth = nLenth;
//}
//void CRectangle::SetWidth(int nWidth)
//{
//
//    m_nWidth = nWidth;
//}
CRectangle::CRectangle() :m_szName{ "方形" }
{

}
void CRectangle::GetName()
{
    printf("%s\n", m_szName);
}
void CRectangle::GetArea()
{
    printf("%d\n", m_nRectArea);

}
CRectangle::~CRectangle()
{
 
}