#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
class CAnimal
{
public:
    virtual void Fun1()
    {
        cout << "����Animal����麯��" << endl;
    }
    void Fun2()
    {
        cout << "����Animal���Fun2����" << endl;
    }

};
class CFox :public CAnimal
{
public:
    virtual void Fun1()
    {
        cout << "����Fox��fun1�麯��" << endl;
    }
    virtual void Fun3()
    {
        cout << "����Fox��fun3�麯��" << endl;
    }
    void Fun4()
    {
        cout << "����Fox��fun4��ͨ����" << endl;
    }
    void Fun2()
    {
        cout << "����Fox��fun2��ͨ����" << endl;
    }
};
class CWolf:public CAnimal
{
public:
    virtual void Fun1()
    {
        cout << "����Fox��fun1�麯��" << endl;
    }
};
int main()
{
    CFox f1;
    CWolf w1;
    CAnimal* p = NULL;
    int nSelect = 0;
    
    scanf_s("%d", &nSelect);
    if (nSelect == 1)
    {
       p = &f1;

    }
    else
    {
        p = &w1;

    }

    p->Fun1();
    

    return 0;
}