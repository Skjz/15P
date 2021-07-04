#pragma once

class CCircle
{
private:
    double m_dblCircular_Area;
    double m_dblR;
    double m_dblD;
public:

    CCircle(double dblR = 0,double dblD = 0,double pi = 9.8);
    double Count_Area(double pi = 9.8);
    
};

