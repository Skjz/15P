#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int nYear = 0;
    int nMonth = 0;
    int nDate = 0;
    printf("请输入年份、月份和具体日期,中间用空格隔开:>");
    scanf("%d%d%d", &nYear, &nMonth, &nDate);
    int nCmp_Year = 0;
    int nCmp_Month = 0;
    int nCmp_Date = 0;
    printf("请输入对比年份、月份和具体日期,中间用空格隔开:>");
    scanf("%d%d%d", &nCmp_Year, &nCmp_Month, &nCmp_Date);
    int Count_Year = 0;
    Count_Year = nCmp_Year - nYear;//计算目标年和当年差的年份
    int Count_EXtreday = 0;//用来计数每一次的闰年多的那一天
    int Year_day = 0;
    for (int nTempYear =nYear; nTempYear <= nCmp_Year; nTempYear++)//用一个临时的数据来统计离目标年有几个闰年
    {
        if ((nTempYear % 4 == 0 && nTempYear% 100 != 0 )|| (nTempYear % 400 == 0))
        {
            if ((nCmp_Year != nTempYear) || (nCmp_Month > 2))
            {
                Count_EXtreday++;
            }
        }

    }
    if (nCmp_Year - nYear == 1 || nMonth <= nCmp_Month)
    {
        if (nMonth > 2)
        {
            Year_day = Count_EXtreday + Count_Year * 365;
        }
        else
        {
           Year_day = (Count_EXtreday - 1) + Count_Year * 365;
        }
    }
    else if( nMonth>nCmp_Month)
        
    {
        if (nCmp_Month > 2)
        {
            Year_day = Count_EXtreday + (Count_Year - 1) * 365;
        }
        else
        {
             Year_day = (Count_EXtreday-1) + (Count_Year - 1) * 365;

        }
    }
    printf("%d", Year_day);
    //此时年产生的日期差已经计算完成。(已考虑闰年平年)

    //月份日期差
    int Month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int Count_Month = 0;
    int Sum_Month = 0;
    int Sum_CmpMonth = 0;
  
    for (int i = 0; i < nMonth - 1; i++)
    {
        Sum_Month += Month[i];
    }
  
    for (int i = 0; i < nCmp_Month - 1; i++)
    {
        Sum_CmpMonth += Month[i];
    }
    /*  if (nMonth >= nCmp_Month)
      {
          Count_Month = Sum_Month - Sum_CmpMonth;
      }*/
   /* else if (nMonth < nCmp_Month)
    {
        if(nYear !=nCmp_Year)
        Count_Month = (Sum_Month+365)  - Sum_CmpMonth;
        else
        {
            Count_Month = Sum_CmpMonth - Sum_Month;
        }
    }*/

    int Count_Day = 0;
    Count_Day = Sum_Month + nDate;
    int Count_CmpDay = Sum_CmpMonth + nCmp_Date;
    int Tempday = 0;
    if (Count_CmpDay > Count_Day)
    {
     Tempday =  Count_CmpDay - Count_Day;
    }
    else
    {
        int Tempday =  Count_Day - Count_CmpDay;
    }
    int Count_All_Day = Year_day + Tempday;
    if (nYear == nCmp_Year)
    {
        Count_All_Day--;
    }

    printf("相差%d天", Count_All_Day);

    return 0;
}