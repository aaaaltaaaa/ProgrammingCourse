/*
程序功能：将合法C源程序每行前加上行号并删除其所有注释。
*/
#include <stdio.h>
int main(int argc, char const *argv[])
{
  FILE *fpIn, *fpOut; //文件指针
  char ch, ch1;
  char fileName[100];
  printf(
      "程序功能：将合法C源程序每行前加上行号并删除其所有注释。\n"); //功能说明
  printf("请输入需要进行本操作的源文件名。\n");
  scanf("%s", fileName);
  if ((fpIn = fopen(fileName, "r")) != NULL) //判断文件是否成功打开
  {
    fpOut = fopen("no2_1.txt", "w");
    for (int i = 1; !feof(fpIn); ++i)
    {
      fprintf(fpOut, "%d: ", i);
      printf("%d: ", i);
      for (int j = 0; fscanf(fpIn, "%c", &ch) && ch != '\n'; ++j)
      {
        if (ch != '/')
        {
          fprintf(fpOut, "%c", ch);
          printf("%c", ch);
        }
        else
        {
          ch1 = ch;
          fscanf(fpIn, "%c", &ch);
          if (ch == '/')
          {
            while (!(fscanf(fpIn, "%c", &ch) && ch == '\n'))
              ;
            break;
          }
          else if (ch == '*')
          {
            while (1)
            {
              ch1 = ch;
              fscanf(fpIn, "%c", &ch);
              if (ch1 == '*' && ch == '/')
              {
                break;
              };
            }
          }
          else
          {
            fprintf(fpOut, "%c", ch1);
            printf("%c", ch1);
            fprintf(fpOut, "%c", ch);
            printf("%c", ch);
          }
        }
      }
      fprintf(fpOut, "\n");
      printf("\n");
    }
    //关闭文件
    fclose(fpIn);
    fclose(fpOut);
    printf("处理后的文件已保存至当前目录下的no2_1.txt。");
  }
  else
    printf("打开文件失败。\n");
  return 0;
}
