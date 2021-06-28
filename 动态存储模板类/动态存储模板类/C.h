#pragma once
#include<stdio.h>
#include<stdlib.h>

template<class T>
class CArray
{
public:
    T* m_Arr;
    int m_nMaxsize;
    int m_nCount;

private:
    //数组初始化
    CArray();
    //增
    void Add(T Data, int nLoc);
    //删
    void Dele(int nLoc);

    //查
    int Find(T Data);

    //改
    void Change(int nLoc, T Data);
    //排序

    void BubbleSort();

};

//数组初始化
template<class T>
CArray<T>::CArray() :m_nMaxsize(5), m_nCount(0)
{
    m_Arr = new T[m_nMaxsize];
}
//增
template<class T>
void CArray<T>::Add(T Data, int nLoc)
{

    if (m_nCount == m_nMaxsize)
    {
        T* temp = new T[m_nMaxsize * 2];
        for (int i = 0; i <= m_nCount; i++)
        {
            temp[i] = m_Arr[i];
        }
        delete[]m_Arr;
        m_Arr = temp;
    }
    if (nLoc > m_nCount)
    {
        return;
    }
    //增加中间的数据
    for (int i = m_nCount - 1; i >= nLoc; i--)
    {
        m_Arr[i + 1] = m_Arr[i];
    }

    //在末尾增加数据
    m_Arr[nLoc] = Data;
    m_nCount++;

}
//删
template<class T>
void CArray<T>::Dele(int nLoc)
{

    if (nLoc > m_nCount || nLoc < 0)
    {
        return;
    }


    for (int i = nLoc; i < m_nCount; i++)
    {
        m_Arr[i] = m_Arr[i + 1];
    }
    m_nCount--;

}

//查
template<class T>
int CArray<T>::Find(T Data)
{
    for (int i = 0; i < m_nCount; i++)
    {
        if (m_Arr[i] == Data)
        {
            return i;
        }
    }
    return -1;
    
}

//改
template<class T>
void CArray<T>::Change(int nLoc,T Data)
{
    if (nLoc > m_nCount || nLoc < 0)
    {
        return;

    }
    m_Arr[nLoc] = Data;
}
//排序
template<class T>
void CArray<T>::BubbleSort()
{
    for (int i = 0; i < m_nCount - 1; i++)
    {
        for (int j = 0; j < m_nCount - 1 - i; j++)
        {
            T temp = m_Arr[i];
            m_Arr[i] = m_Arr[i+1];
            m_Arr[i + 1] = temp;


        }
    }


}