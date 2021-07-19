#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
class CTest
{
public:
    CTest()
    {
       
    }
    static void SetObj();
    static void DeleObj();
private:
    static CTest* p;
    static bool Flag;

};
CTest* CTest::p{nullptr};
bool CTest::Flag{ false };
void CTest::SetObj()
{
   if (Flag == false)
   {
       Flag = true;
       p = new CTest;
   }

}
void CTest::DeleObj()
{
    if (Flag == true)
    {
        Flag = false;
        delete[]p;
    }
}
int main()
{
    CTest::SetObj();
    CTest::SetObj();

    return 0;
}