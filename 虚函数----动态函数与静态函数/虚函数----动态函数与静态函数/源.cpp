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
        cout << "我是Animal类的虚函数" << endl;
    }
    void Fun2()
    {
        cout << "我是Animal类的Fun2函数" << endl;
    }

};
class CFox :public CAnimal
{
public:
    virtual void Fun1()
    {
        cout << "我是Fox的fun1虚函数" << endl;
    }
    virtual void Fun3()
    {
        cout << "我是Fox的fun3虚函数" << endl;
    }
    void Fun4()
    {
        cout << "我是Fox的fun4普通函数" << endl;
    }
    void Fun2()
    {
        cout << "我是Fox的fun2普通函数" << endl;
    }
};
class CWolf:public CAnimal
{
public:
    virtual void Fun1()
    {
        cout << "我是Fox的fun1虚函数" << endl;
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