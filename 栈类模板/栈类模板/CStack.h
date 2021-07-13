#pragma once
#include<stdio.h>
#include<stdlib.h>


template<class T>
class CStack
{
private:
    T* m_Stack;
    int m_nCount;
    int m_nMaxsize;

public:
    CStack();
    void Stack_Push(T Data);
    void Stack_Pop(int nLoc);
    //~CStack();
};

template<class T>
CStack<T>::CStack():m_nCount(0),m_nMaxsize(5)
{
    m_Stack = new T[m_nMaxsize];
}

template<class T>
void CStack<T>::Stack_Push(T Data)
{
    if (m_nCount == m_nMaxsize)
    {
        T* temp = new T[m_nMaxsize * 2];
        for (int i = 0; i < m_nCount; i++)
        {
            temp[i] = m_Stack[i];
        }
        delete[]m_Stack;
        m_Stack = temp;
        m_nMaxsize *= 2;
    }
    m_Stack[m_nCount] = Data;
    m_nCount++;


}
template<class T>
void CStack<T>::Stack_Pop(int nLoc)
{
    if (nLoc > m_nCount || nLoc < 0)
    {
        return;
    }
    for (int i = m_nCount - 1; i >= nLoc; i--)
    {
        m_nCount--;
    }


}