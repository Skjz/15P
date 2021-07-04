#include "CCircle.h"
CCircle::CCircle(double dblR , double dblD,double pi)
{
    m_dblR = dblR;
    m_dblD = dblD;
}

double CCircle::Count_Area(double pi)
{
   m_dblCircular_Area = pi* m_dblR* m_dblR;
   return m_dblCircular_Area;
}