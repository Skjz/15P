#pragma once
//������Shape
class CShape
{
public:
    virtual void Area() = 0; //���麯��
    virtual void GetArea() = 0;
    virtual void GetName() = 0;
    virtual ~CShape() = 0; //�����������������Ŀ����Ҫ������
};

