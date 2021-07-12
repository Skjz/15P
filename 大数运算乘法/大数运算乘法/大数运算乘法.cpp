#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<string.h>
int main()
{
    //首先使用两个字符串数组，防止数字本身超出了int型数据的存储大小极限
    //参与运算的数字1
    char Num1[] = "12345678";
    //参与运算的数字2
    char Num2[] = "87654321";


    //用来存放每一个数字1整型元素的数组。
    int TurnNum1[100] = { 0 };
    //用来存放每一个数字2整型元素的数组。
    int TurnNum2[100] = { 0 };

    //用来存放（逆置的）运算结果的数组
    int TurnMul[100] = { 0 };

    
    int nLenth1 = 0;
    int nLenth2 = 0;
    //计算结果的长度
    int nLenth = 16;

    //数字1(字符串数组)的长度
    nLenth1 = strlen(Num1);
    //数字2(字符串数组)的长度
    nLenth2 = strlen(Num2);

    int j = 0;
    for (int i = nLenth1 - 1; i >= 0; i--)
    {
        //将数字1的每一个字符元素变为数字存入整型数组1中(逆置)
        //之所以逆置是为了方便运算，因为手算时也是从低位像高位运算
        TurnNum1[j] = Num1[i] - '0';
        j++;
    }
    j = 0;
    for (int i = nLenth2 - 1; i >= 0; i--)
    {
        //将数字2的每一个字符元素变为数字存入整型数组2中（逆置）
        TurnNum2[j] = Num2[i] - '0';
        j++;
    }
    for (int i = 0; i < nLenth1; i++)
    {
        for (int j = 0; j < nLenth2; j++)
        {   //在乘法计算时有一个规律，那就是数字1的第i个元素和数字2的第j个元素相乘会加到结果的i+j位上
            //为了方便写流程，先运算，再考虑进位
            TurnMul[i + j] = TurnMul[i+j]+TurnNum1[i] * TurnNum2[j];
        }
    }
    for (int i = 0; i < nLenth; i++)
    {
        //如果计算结果数组那一位大于10，代表需要进位
        if (TurnMul[i] >= 10)
        {
            //相当于下一位的数字应该加上上一位需要进位的数字的10位上的数字
            TurnMul[i + 1] = TurnMul[i + 1] + TurnMul[i] / 10;
            //然后上一位需要进位的数字仅留下个位数
            TurnMul[i] = TurnMul[i] % 10;
        }
    }

    //此时可能会在数组的末尾留下0，所以需要去0
    for (int i = 0; i < nLenth; i++)
    {
        if (TurnMul[nLenth] == 0)
        {
            nLenth--;
        }
        else
        {
            break;
        }
    }
    //将被逆置的结果进行逆序打印
    for (int i = nLenth; i >= 0; i--)
    {
        printf("%d", TurnMul[i]);
    }

    return 0;
}