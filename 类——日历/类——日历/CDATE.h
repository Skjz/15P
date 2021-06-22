#pragma once
class CDATE
{
private:
    int m_nYear;
    int m_nMonth;
    int m_nDay;
    int m_nMonth_Day[12];
public:
    CDATE();
    void SetDate();
    void Run();
    void GetDate();
};

