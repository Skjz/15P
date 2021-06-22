#pragma once
class CTIME
{
private:
    int m_nHour;
    int m_nMinute;
    int m_nSecond;

public:
    CTIME(int nHour, int nMinute, int nSecond);
    void SetTime();
    void GetHour();
    void GetMinute();
    void GetSecond();

};

