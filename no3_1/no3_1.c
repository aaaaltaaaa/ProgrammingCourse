#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char ch[100] = {'\0'};
    int sum = 0;
    int i;

    printf("程序功能:"
           "将输入的2进制字符串转换为10进制数输出。\n"); //功能说明
    //输入
    printf("请输入需要转换的二进制字符串。\n");
    gets(ch);
    //判断输入是否合法
    do
    {
        for (i = 0; i < strlen(ch); i++)
        {
            if (ch[i] != '0' && ch[i] != '1')
            {
                break;
            }
        }
        if (i != strlen(ch))
        {
            printf("输入有误，请重新输入。");
            gets(ch);
        }
    } while (i != strlen(ch));
    //转化为十进制
    for (int i = 0; i < strlen(ch); i++)
    {
        sum = sum * 2 + (ch[i] - '0');
    }
    //输出结果
    printf("相对应的十进制数为：%d", sum);
    return 0;
}
