#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    FILE *fp; //文件指针
    char ch;
    int charNum[26] = {0}; //记录出现次数
    int num;
    char fileName[100]; //文件名
    printf("程序功能:"
           "统计一个英文文本文件中26个英文字母出现次数并按英文字母序输出统计结果"
           "，查找并替换此英文文本文件中某字符串。\n"); //功能说明
    printf("请输入需要进行本操作的源文件名。\n");
    scanf("%s", fileName);
    if ((fp = fopen(fileName, "r")) != NULL) //判断文件是否成功打开
    {
        //读取并判断是否为字母，记录字母出现次数
        for (int i = 0; !feof(fp); ++i)
        {
            fscanf(fp, "%c", &ch);
            if ((ch - 'a' >= 0 && ch - 'a' <= 25) ||
                (ch - 'A' >= 0 && ch - 'A' <= 25))
            {
                num = (ch - 'a' + 32) % 32;
                charNum[num]++;
            }
        }
        fclose(fp);
    }
    else
    {
        printf("打开文件失败。\n");
        return -1;
    }
    //输出统计结果
    for (int i = 0; i < 26; i++)
    {
        printf("%c出现的次数为%d\n", (i + 'a'), charNum[i]);
    }

    //进行替换操作

    char pre[100] = {'\0'}, now[100] = {'\0'}, temp[100] = {'\0'};
    printf("请输入需要替换的字符串。");
    scanf("%s", pre);
    printf("请输入目标字符串。");
    scanf("%s", now);

    if ((fp = fopen(fileName, "r")) != NULL) //判断文件是否成功打开
    {
        FILE *fpOut;
        long position;
        fpOut = fopen("no2_2.txt", "w");
        for (int i = 0; !feof(fp); ++i)
        {
            position = ftell(fp);
            fgets(temp, strlen(pre) + 1, fp);
            if (!strcmp(temp, pre))
            {
                fputs(now, fpOut);
            }
            else
            {
                fseek(fp, position, 0);
                fputc(fgetc(fp), fpOut);
            }
        }
        fclose(fp);
        printf("处理后的文本一保存至当前目录下的no2_2.txt文件。");
    }
    else
    {
        printf("打开文件失败。\n");
        return -1;
    }
    return 0;
}
