#pragma once
class CFood
{
public:
    CFood();

    //生成食物
    void Creat_Food();

    //设置食物是否存在
    void Set_Food_Exist(int Is_Exist);

    //得到食物是否存在
    int Get_Food_Exist();

    //设置食物是否存在
    void Set_Food_Exist();

    //获得食物的种类
    int Get_Food_Type();

    //设置食物的种类
    void Set_Food_Type();

private:
    //用来判断是否有食物的变量
    int Food_Exist;
    int Food_Type;
};

