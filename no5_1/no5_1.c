#include <stdio.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int target; //�����
    int guess;  //�²���
    printf("������:"
           "�����Զ�����һ��λ��99�ڵ��������Ҫ���û�����������û�����һ������"
           "������������Ӧ��too big��too small��you win��\n"); //����˵��
    srand(time(NULL));                                           //����ʱ������
    target = rand() % 100;                                       //���������
    printf("Please guess what the target number is.\n");
    //�²Ⲣ������
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
    } while (!(guess == target)); //�¶Ժ�����ѭ��
    printf("You win.\n");
    return 0;
}
