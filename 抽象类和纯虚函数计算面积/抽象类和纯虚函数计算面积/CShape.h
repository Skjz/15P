#pragma once
//抽象类Shape
class CShape
{
public:
    virtual void Area() = 0; //纯虚函数
    virtual void GetArea() = 0;
    virtual void GetName() = 0;
    virtual ~CShape() = 0; //无用虚析构，这个项目不需要虚析构
};

