#include <conio.h>
#include <stdio.h>
#include <string.h>
#define MAXNUM 100
//���ַ���ת��Ϊ�ļ���
int toFilename(char *type, char *name)
{
    char temp[MAXNUM] = {'\0'};
    if (!strcmp(type, "singer"))
    {
        sprintf(temp, "./singer/%s.txt", name);
    }
    else if (!strcmp(type, "song"))
    {
        sprintf(temp, "./song/%s.txt", name);
    }
    strcpy(name, temp);
    return 0;
}
int add() //����Ա��Ӹ�������
{
    FILE *fp;
    char singer[MAXNUM] = {'\0'}, song[MAXNUM] = {'\0'}, ch;
    //�������
    printf("��������Ӹ����ĸ�����:");
    scanf("%s", singer);
    toFilename("singer", singer);
    fp = fopen(singer, "a");
    //��Ӹ�������
    printf("��������Ӹ�����");
    scanf("%s", song);
    fputs(song, fp);
    fputs("\n", fp);
    fclose(fp);
    //��Ӹ��
    toFilename("song", song);
    fp = fopen(song, "w");
    printf("�������ʣ���������eof��\n");
    while ((ch = getchar()) && ch != EOF)
    {
        fputc(ch, fp);
    }
    fclose(fp);
    printf("��Ӹ����ɹ�������������ء�\n");
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}

int del() //����Աɾ�������Ĺ���
{
    FILE *fp, *buffer;
    char song[MAXNUM] = {'\0'}, singer[MAXNUM] = {'\0'}, ch[MAXNUM];
    //������Ϣ
    printf("������ɾ���ĸ�����:");
    scanf("%s", singer);
    toFilename("singer", singer);
    fp = fopen(singer, "r+");
    if (fp == NULL)
    {
        printf("�����ڴ˸���\n");
        printf("��������������������档\n");
        getch();
        system("cls");
        return 0;
    }
    buffer = fopen("./song/buffer.txt", "w+");
    printf("������ɾ���ĸ�����");
    scanf("%s", song);
    //��������Ϣ���Ƶ������ļ��в�ɾ����Ӧ�ĸ�����Ϣ
    while (!feof(fp))
    {
        fscanf(fp, "%s", ch);
        if (strcmp(ch, song))
        {
            fprintf(buffer, "%s", ch);
        }
    }
    //�ر��ļ�
    fclose(fp);
    fclose(buffer);
    //�޸��ļ� 
    remove(singer);
    rename("./song/buffer.txt",singer);
    //ɾ�����
    toFilename("song", song);
    remove(song);
    printf("ɾ�������ɹ���");
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}
//ͨ���������
int chooseBySong()
{
    FILE *fp;
    char song[MAXNUM] = {'\0'}; //������
    printf("�����������:");
    scanf("%s", song);
    toFilename("song", song);
    fp = fopen(song, "r");
    if (fp == NULL)
    {
        printf("���������ڡ�\n");
        printf("��������������������档\n");
        getch();
        system("cls");
        return -1;
    }
    printf(" >>���\n");
    while (!feof(fp)) //��ӡ���
    {
        printf("%c", fgetc(fp));
    }
    fclose(fp);
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}
//ͨ�����ֵ��
int chooseBySinger()
{
    FILE *fp;
    char singer[MAXNUM] = {'\0'}; //������
    char song[MAXNUM] = {'\0'};   //������
    printf("�������������");
    scanf("%s", singer);
    toFilename("singer", singer);
    fp = fopen(singer, "r");
    if (fp == NULL)
    {
        printf("���ֲ����ڡ�\n");
        printf("��������������������档\n");
        getch();
        system("cls");
        return -1;
    }
    printf("����ȫ����������:\n");
    while (!feof(fp)) //��ӡ�������и���
    {
        printf("%c", fgetc(fp));
    }
    fclose(fp);
    printf("�����������:");
    scanf("%s", song);
    toFilename("song", song);
    fp = fopen(song, "r");
    if (fp == NULL)
    {
        printf("���������ڡ�\n");
        printf("��������������������档\n");
        getch();
        system("cls");
        return -1;
    }

    printf(">>���\n");
    while (!feof(fp)) //��ӡ���
    {
        printf("%c", fgetc(fp));
    }
    fclose(fp);
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}
//�û�����ѡ��
void user()
{
    int function;
    do
    {
        printf(" KTV���ϵͳ\n��ѡ���跽ʽ��\n1.�������\n2.���ֵ��\n3.�˳�\n");
        scanf("%d", &function);
        system("cls");
        while (function != 1 && function != 2 && function != 3)
        {
            printf("������������������:");
            scanf("%d", &function);
            system("cls");
        }
        switch (function)
        {
        case 1:
            chooseBySong();
            break;
        case 2:
            chooseBySinger();
            break;
        case 3:
            break;
        default:
            break;
        }
    } while (function != 3);
}
//����Ա����ѡ��
void manager()
{
    int function;
    do
    {
        printf(" KTV ����Աϵͳ \n1.��Ӹ���\n2.ɾ������\n3.�˳�\n");
        scanf("%d", &function);
        system("cls");
        while (function != 1 && function != 2 && function != 3)
        {
            printf("������������������:");
            scanf("%d", &function);
            system("cls");
        }
        switch (function)
        {
        case 1:
            add();
            break;
        case 2:
            del();
            break;
        default:
            break;
        }
    } while (function != 3);
}
//������
int main(int argc, char const *argv[])
{
    int function;
    do
    {
        printf(" KTVϵͳ\n1.����Ա����\n2.�û�����\n3.�˳�\n");
        scanf("%d", &function);
        system("cls");
        while (function != 1 && function != 2 && function != 3)
        {
            printf("������������������:");
            scanf("%d", &function);
            system("cls");
        }
        if (function == 1)
        {
            manager();
        }
        else if (function == 2)
        {
            user();
        }
    } while (function != 3);
    return 0;
}
