#include <stdio.h>
#include <time.h>
#define MAXNUM 100
int main(int argc, char const *argv[])
{
    char number[MAXNUM];
    int max, min;
    int num;
    int random;

    printf(
        "程序功能:"
        "产生一组随机数，要求每个数字不能重复。例如：1，20，3，17，80，4，35，88"
        "符合要求， 3，20，1，17，80，3，35，88不符合要求。\n"); //功能说明
    //输入
    printf("请输入生成随机数的最大值。\n");
    scanf("%d", &max);
    printf("请输入生成随机数的最小值\n");
    scanf("%d", &min);
    printf("请输入生成随机数的个数。\n");
    scanf("%d", &num);
    //判断输入是否合法
    while (num > max + 1 - min)
    {
        printf("随机数个数过多，请重新输入。");
        scanf("%d", &num);
    }
    //产生并记录随机数
    for (int i = 0; i < num;)
    {
        srand(time(NULL));                       //产生时间种子
        random = rand() % (max + 1 - min) + min; //生成随机数
        int j;
        //比较是否有重复
        for (j = 0; j < i; j++)
        {
            if (number[j] == random)
            {
                break;
            }
        }
        //无重复则记录
        if (j == i)
        {
            number[i++] = random;
        }
    }
    //输出
    printf("生成的随机数列为：");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", number[i]);
    }

    return 0;
}
