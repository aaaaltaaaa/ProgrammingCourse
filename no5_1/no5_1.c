#include <stdio.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int target; //随机数
    int guess;  //猜测数
    printf("程序功能:"
           "程序自动生成一个位于99内的随机数，要求用户猜这个数。用户输入一个数后"
           "，程序有三种应答：too big，too small，you win。\n"); //功能说明
    srand(time(NULL));                                           //产生时间种子
    target = rand() % 100;                                       //生成随机数
    printf("Please guess what the target number is.\n");
    //猜测并输出结果
    do
    {
        scanf("%d", &guess);
        if (guess < target)
        {
            printf("Too small.\n");
        }
        else if (guess > target)
        {
            printf("Too big.\n");
        }
    } while (!(guess == target)); //猜对后跳出循环
    printf("You win.\n");
    return 0;
}
