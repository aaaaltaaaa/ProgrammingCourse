#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	FILE *fp1, *fp2;													  //文件指针
	char fileName1[100], fileName2[100];								  //文件名
	printf("程序功能：比较两个文本文件并打印出他们第一个不相同的行。\n"); //功能说明
	printf("请输入需要比较的两个文件文件名。本程序样例文件为1.txt和2.txt。\n");
	scanf("%s%s", fileName1, fileName2);
	if ((fp1 = fopen(fileName1, "r")) != NULL && (fp2 = fopen(fileName2, "r")) != NULL) //判断文件是否成功打开
	{
		char ch1[80], ch2[80]; //临时存储每行的字符
		for (int i = 1; !feof(fp1) && !feof(fp2); i++)
		{
			//读入每行
			fgets(ch1, 100, fp1);
			fgets(ch2, 100, fp2);
			//比较并打印首个不同行
			if (strcmp(ch1, ch2))
			{
				printf("文件第%d行不一样\n", i);
				printf("文件%s中为%s\n", fileName1, ch1);
				printf("文件%s中为%s\n", fileName2, ch2);
				break; //找到第一个不同的行后跳出循环
			}
		}
		//关闭文件
		fclose(fp1);
		fclose(fp2);
	}
	else
		printf("打开文件失败。\n");
	return 0;
}
