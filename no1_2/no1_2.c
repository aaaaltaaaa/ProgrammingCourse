#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fp1, *fp2, *fp3;//�ļ�ָ��
    int num[100] = {0};//������ʱ�洢����������
    printf("�����ܣ����ı��ļ�num1��num2���ÿո�ֿ���������������󱣴���num3��\n");
    if ((fp1 = fopen("num1.txt", "r")) != NULL && (fp2 = fopen("num2.txt", "r")) != NULL)
    {
        int n = 0;//��¼��������
        int t;//���ڽ���������
        //���num1����¼num1�е�����
        printf("num1:");
        for (int i = 0; !feof(fp1); i++)
        {
            fscanf(fp1, "%d", &num[n] );
            printf("%d ", num[n++]);
        }
        printf("\n");
        //���num2����¼num2�е�����
        printf("num2:");
        for (int i = 0; !feof(fp2); i++)
        {
            fscanf(fp2, "%d", &num[n] );
            printf("%d ", num[n++]);
        }
        printf("\n");
        //ð������
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
        //����������num3�У������num3
        fp3 = fopen("num3.txt", "w+");
        printf("num3:");
        for (int i = 0; i < n ; ++i)
        {
            fprintf(fp3, "%d", num[i] );
            printf("%d ", num[i] );
        }
        //�ر��ļ�
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
    }
    else
        printf("���ļ�ʧ�ܡ�\n");
    return 0;
}

