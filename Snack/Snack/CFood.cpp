
#include<time.h>
#include "CFood.h"
#include"DrawBase.h"
CFood::CFood():Food_Exist(0),Food_Type(0)
{

}
void CFood::Creat_Food()
{
    //随机数种子
    srand((unsigned int)time(NULL));

    //判断食物是否需要生成，如果Food_Exist是0，则应该生成食物
    if (Food_Exist == 0)
    {
        //无限循环，直到能够生成食物才退出
        while(true)
      { 
        //随机获得一个坐标
        int Food_X = rand() % 28 + 1;
        int Food_Y = rand() % 28 + 1;
        Food_Type = rand() % 70;

        //如果确认这个坐标是空地且是增速的食物
        if (Map[Food_X][Food_Y] == EMPTYAREA && Food_Type>=15)
        {
            Write_Char(Food_X, Food_Y, "★");  //在图像上显示食物
            Map[Food_X][Food_Y] = FOOD;       //将这个位置的地图信息编辑为食物
            Food_Exist = 1;  
            break;                            //跳出循环
        }
        //如果确认这个坐标是空地且是减速食物
        else if (Map[Food_X][Food_Y] == EMPTYAREA && Food_Type <15)
        {

            Write_Char(Food_X, Food_Y, "☆");
            Map[Food_X][Food_Y] = SPEEDDOWNFOOD;
            Food_Exist = 1;
            break;
        }
      }

    }
}

//设置食物是否存在
void CFood::Set_Food_Exist(int Is_Exist)
{
    Food_Exist = Is_Exist;

}

//得到食物是否存在
int CFood::Get_Food_Exist()
{
    return  Food_Exist;
}

//设置食物是否存在
//void CFood::Set_Food_Exist(int Temp_Food_Exist)
//{
//    Food_Exist = Temp_Food_Exist;
//}
