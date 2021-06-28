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
    //�����ʼ��
    CArray();
    //��
    void Add(T Data, int nLoc);
    //ɾ
    void Dele(int nLoc);

    //��
    int Find(T Data);

    //��
    void Change(int nLoc, T Data);
    //����

    void BubbleSort();

};

//�����ʼ��
template<class T>
CArray<T>::CArray() :m_nMaxsize(5), m_nCount(0)
{
    m_Arr = new T[m_nMaxsize];
}
//��
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
    //�����м������
    for (int i = m_nCount - 1; i >= nLoc; i--)
    {
        m_Arr[i + 1] = m_Arr[i];
    }

    //��ĩβ��������
    m_Arr[nLoc] = Data;
    m_nCount++;

}
//ɾ
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

//��
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

//��
template<class T>
void CArray<T>::Change(int nLoc,T Data)
{
    if (nLoc > m_nCount || nLoc < 0)
    {
        return;

    }
    m_Arr[nLoc] = Data;
}
//����
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