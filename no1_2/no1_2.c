#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fp1, *fp2, *fp3;//文件指针
    int num[100] = {0};//用于临时存储整数的数组
    printf("程序功能：将文本文件num1和num2中用空格分开的整数联合排序后保存在num3中\n");
    if ((fp1 = fopen("num1.txt", "r")) != NULL && (fp2 = fopen("num2.txt", "r")) != NULL)
    {
        int n = 0;//记录整数个数
        int t;//用于交换两个数
        //输出num1并记录num1中的整数
        printf("num1:");
        for (int i = 0; !feof(fp1); i++)
        {
            fscanf(fp1, "%d", &num[n] );
            printf("%d ", num[n++]);
        }
        printf("\n");
        //输出num2并记录num2中的整数
        printf("num2:");
        for (int i = 0; !feof(fp2); i++)
        {
            fscanf(fp2, "%d", &num[n] );
            printf("%d ", num[n++]);
        }
        printf("\n");
        //冒泡排序
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (num[j] > num[j + 1])
                {
                    t = num[j + 1];
                    num[j + 1] = num[j];
                    num[j] = t;
                }
            }
        }
        //排序结果存入num3中，并输出num3
        fp3 = fopen("num3.txt", "w+");
        printf("num3:");
        for (int i = 0; i < n ; ++i)
        {
            fprintf(fp3, "%d", num[i] );
            printf("%d ", num[i] );
        }
        //关闭文件
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
    }
    else
        printf("打开文件失败。\n");
    return 0;
}

