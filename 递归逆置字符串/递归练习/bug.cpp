//#define _crt_secure_no_warnings
//#include<stdio.h>
//#include<stdlib.h>
//int my_strlen(char* charr)
//{
//    if (*charr != '\0')
//    {
//        return 1 + my_strlen(charr + 1);
//    }
//    else
//    {
//        return 0;
//    }
//}
//void reverse_str(char* charr)
//{
//    char temp = 0;
//    temp = charr[0];
//    //int lenth = my_strlen(charr);
//    charr[0] = charr[my_strlen(charr) - 1];
//    charr[my_strlen(charr)- 1] = '\0';//��������ÿ�ζ������һ�γ���-1�����㣬�����ñ�������
//    if (my_strlen(charr + 1) >= 2)
//    {
//        reverse_str(charr + 1);
//    }
//    charr[lenth - 1] = temp;
//
//}
//int main()
//{
//    char charr[6] = { "abcde" };
//    reverse_str(charr);
//    printf("%s", charr);
//
//
//
//    return 0;
//}