#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char ch[100] = {'\0'};
    int sum = 0;
    int i;

    printf("������:"
           "�������2�����ַ���ת��Ϊ10�����������\n"); //����˵��
    //����
    printf("��������Ҫת���Ķ������ַ�����\n");
    gets(ch);
    //�ж������Ƿ�Ϸ�
    do
    {
        for (i = 0; i < strlen(ch); i++)
        {
            if (ch[i] != '0' && ch[i] != '1')
            {
                break;
            }
        }
        if (i != strlen(ch))
        {
            printf("�����������������롣");
            gets(ch);
        }
    } while (i != strlen(ch));
    //ת��Ϊʮ����
    for (int i = 0; i < strlen(ch); i++)
    {
        sum = sum * 2 + (ch[i] - '0');
    }
    //������
    printf("���Ӧ��ʮ������Ϊ��%d", sum);
    return 0;
}
