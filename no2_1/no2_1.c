/*
�����ܣ����Ϸ�CԴ����ÿ��ǰ�����кŲ�ɾ��������ע�͡�
*/
#include <stdio.h>
int main(int argc, char const *argv[])
{
  FILE *fpIn, *fpOut; //�ļ�ָ��
  char ch, ch1;
  char fileName[100];
  printf(
      "�����ܣ����Ϸ�CԴ����ÿ��ǰ�����кŲ�ɾ��������ע�͡�\n"); //����˵��
  printf("��������Ҫ���б�������Դ�ļ�����\n");
  scanf("%s", fileName);
  if ((fpIn = fopen(fileName, "r")) != NULL) //�ж��ļ��Ƿ�ɹ���
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
    //�ر��ļ�
    fclose(fpIn);
    fclose(fpOut);
    printf("�������ļ��ѱ�������ǰĿ¼�µ�no2_1.txt��");
  }
  else
    printf("���ļ�ʧ�ܡ�\n");
  return 0;
}
