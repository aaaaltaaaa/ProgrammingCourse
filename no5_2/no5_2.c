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
        "������:"
        "����һ���������Ҫ��ÿ�����ֲ����ظ������磺1��20��3��17��80��4��35��88"
        "����Ҫ�� 3��20��1��17��80��3��35��88������Ҫ��\n"); //����˵��
    //����
    printf("��������������������ֵ��\n");
    scanf("%d", &max);
    printf("�������������������Сֵ\n");
    scanf("%d", &min);
    printf("����������������ĸ�����\n");
    scanf("%d", &num);
    //�ж������Ƿ�Ϸ�
    while (num > max + 1 - min)
    {
        printf("������������࣬���������롣");
        scanf("%d", &num);
    }
    //��������¼�����
    for (int i = 0; i < num;)
    {
        srand(time(NULL));                       //����ʱ������
        random = rand() % (max + 1 - min) + min; //���������
        int j;
        //�Ƚ��Ƿ����ظ�
        for (j = 0; j < i; j++)
        {
            if (number[j] == random)
            {
                break;
            }
        }
        //���ظ����¼
        if (j == i)
        {
            number[i++] = random;
        }
    }
    //���
    printf("���ɵ��������Ϊ��");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", number[i]);
    }

    return 0;
}
