#include <conio.h>
#include <stdio.h>
#include <string.h>
//������Ϣ
typedef struct
{
    int number;        //���
    char name[20];     //����
    char bookName[30]; //����ͼ��
} Reader;
//ͼ����Ϣ
typedef struct
{
    int number;        //���
    char bookName[30]; //����
    int amount;        //ʣ������
} Book;

//ͼ���б�
void bookList()
{
    int bookNumber; //�鱾����
    FILE *fp = fopen("book.txt", "r");
    Book book; //��ʱ�洢�鼮��Ϣ
    fscanf(fp, "%d", &bookNumber);
    printf("����%d���顣\n", bookNumber);
    printf("���\t����\tʣ������\n");
    for (int i = 0; i < bookNumber; i++)
    { //��ȡ����ӡ�鼮
        fscanf(fp, "%d%s%d", &book.number, book.bookName, &book.amount);
        printf("%d\t%s\t%d\n", book.number, book.bookName, book.amount);
    }
    fclose(fp);
    printf("��������������������档\n");
    getch();
    system("cls");
}
//����
int borrow(Reader reader)
{
    Reader tempReader = {0, {'\0'}, {'\0'}};
    int readerNumber;  //������
    char bookName[30]; //��������
    FILE *fpReader = fopen("reader.txt", "r");
    FILE *bufferReader = fopen("bufferReader.txt", "w");
    fscanf(fpReader, "%d", &readerNumber);
    fprintf(bufferReader, "%d\n", readerNumber);
    for (int i = 0; i < readerNumber; i++)
    {
        fscanf(fpReader, "%d %s %s", &tempReader.number, tempReader.name,
               tempReader.bookName);
        if (reader.number == tempReader.number || reader.name == tempReader.name)
        {
            if (strcmp(tempReader.bookName, "none"))
            { //�ж��Ƿ��н���
                printf("���ѽ����鼮����黹���ٽ��������鼮��");
                fclose(fpReader);
                fclose(bufferReader);
                printf("��������������������档\n");
                getch();
                system("cls");
                return -1;
            }
            printf("��������Ҫ���ĵ�ͼ�����ƣ�");
            scanf("%s", bookName);
            strcpy(tempReader.bookName, bookName);
            //����
            int exist = 0;
            int bookNumber;
            Book tempBook;
            FILE *fpBook = fopen("book.txt", "r");
            FILE *bufferBook = fopen("bufferBook.txt", "w");
            fscanf(fpBook, "%d", &bookNumber);
            fprintf(bufferBook, "%d\n", bookNumber);
            for (int i = 0; i < bookNumber; i++)
            {
                fscanf(fpBook, "%d%s%d", &tempBook.number, tempBook.bookName,
                       &tempBook.amount);
                if (!strcmp(bookName, tempBook.bookName))
                {
                    tempBook.amount--;
                    exist = 1;
                }
                fprintf(bufferBook, "%d %s %d\n", tempBook.number, tempBook.bookName,
                        tempBook.amount);
            }
            fclose(fpBook);
            fclose(bufferBook);
            //�ļ��滻
            remove("book.txt");
            rename("bufferBook.txt", "book.txt");
            if (exist == 0)
            {
                printf("�鼮�����ڡ�");
                printf("��������������������档\n");
                getch();
                system("cls");
                return -1;
            }
        }
        fprintf(bufferReader, "%d %s %s\n", tempReader.number, tempReader.name,
                tempReader.bookName);
    }
    fclose(fpReader);
    fclose(bufferReader);
    //�ļ��滻
    remove("reader.txt");
    rename("bufferReader.txt", "reader.txt");
    printf("����ɹ���");
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}
//����
int sendBack(Reader reader)
{
    Reader tempReader = {0, {'\0'}, {'\0'}};
    int readerNumber; //���߸���
    FILE *fpReader = fopen("reader.txt", "r");
    FILE *bufferReader = fopen("bufferReader.txt", "w");
    fscanf(fpReader, "%d", &readerNumber);
    fprintf(bufferReader, "%d\n", readerNumber);
    for (int i = 0; i < readerNumber; i++)
    {
        fscanf(fpReader, "%d %s %s", &tempReader.number, tempReader.name,
               tempReader.bookName);
        if (reader.number == tempReader.number || reader.name == tempReader.name) //�Ƿ����
        {
            if (!strcmp(tempReader.bookName, "none"))
            {
                printf("��δ�����鼮��");
                fclose(fpReader);
                fclose(bufferReader);
                printf("��������������������档\n");
                getch();
                system("cls");
                return -1;
            }
            //����
            int bookNumber;
            Book tempBook;
            FILE *fpBook = fopen("book.txt", "r");
            FILE *bufferBook = fopen("bufferBook.txt", "w");
            fscanf(fpBook, "%d", &bookNumber);
            fprintf(bufferBook, "%d\n", bookNumber);
            for (int i = 0; i < bookNumber; i++)
            {
                fscanf(fpBook, "%d%s%d", &tempBook.number, tempBook.bookName,
                       &tempBook.amount);
                if (!strcmp(tempReader.bookName, tempBook.bookName))
                {
                    tempBook.amount++;
                }
                fprintf(bufferBook, "%d %s %d\n", tempBook.number, tempBook.bookName,
                        tempBook.amount);
            }
            fclose(fpBook);
            fclose(bufferBook);
            remove("book.txt");
            rename("bufferBook.txt", "book.txt");

            strcpy(tempReader.bookName, "none"); //�޸Ľ�����Ϣ
        }
        fprintf(bufferReader, "%d %s %s\n", tempReader.number, tempReader.name,
                tempReader.bookName);
    }
    fclose(fpReader);
    fclose(bufferReader);
    remove("reader.txt");
    rename("bufferReader.txt", "reader.txt");
    printf("����ɹ���\n");
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}
//���ձ������
int seekByNum()
{
    int exist = 0;  //�Ƿ����
    int seekNum;    //Ҫ�ҵ����鼮���
    int bookNumber; //�鼮����
    Book tempBook;  //��ʱ����鼮��Ϣ
    printf("��������Ҫ��ѯ���鼮��ţ�");
    scanf("%d", &seekNum);
    FILE *fpBook = fopen("book.txt", "r");
    fscanf(fpBook, "%d", &bookNumber);
    for (int i = 0; i < bookNumber; i++) //����ͼ��
    {
        fscanf(fpBook, "%d%s%d", &tempBook.number, tempBook.bookName,
               &tempBook.amount);
        if (seekNum == tempBook.number)
        {
            exist = 1;
            printf("���\t����\tʣ������\n");
            printf("%d\t%s\t%d\n", tempBook.number, tempBook.bookName,
                   tempBook.amount);
            break;
        }
    }
    if (!exist)
    {
        printf("�鼮�����ڡ�");
    }
    fclose(fpBook);
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}
//�����ֲ���
int seekByName()
{
    int exist = 0;     //�Ƿ����
    char seekName[30]; //��������
    int bookNumber;    //�鼮����
    Book tempBook;     //��ʱ��Ϣ
    printf("��������Ҫ��ѯ���鼮���ƣ�");
    scanf("%s", seekName);
    FILE *fpBook = fopen("book.txt", "r");
    fscanf(fpBook, "%d", &bookNumber);
    for (int i = 0; i < bookNumber; i++) //�����鼮
    {
        fscanf(fpBook, "%d%s%d", &tempBook.number, tempBook.bookName,
               &tempBook.amount);
        if (!strcmp(seekName, tempBook.bookName))
        {
            exist = 1;
            printf("���\t����\tʣ������\n");
            printf("%d\t%s\t%d\n", tempBook.number, tempBook.bookName,
                   tempBook.amount);
            break;
        }
    }
    if (!exist)
    {
        printf("�鼮�����ڡ�");
    }
    fclose(fpBook);
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}
//����
int seek()
{
    int function;
    do
    {
        printf("��ѡ���ѯ��ʽ��\n");
        printf("1.���鼮��Ų�ѯ\n2.���鼮���ֲ�ѯ\n3.����\n");
        scanf("%d", &function);
        system("cls");
        if (function == 1)
        {
            seekByNum();
        }
        else if (function == 2)
        {
            seekByName();
        }
        else if (function > 3 && function < 0)
        {
            printf("�����������������롣\n");
            scanf("%d", &function);
        }
    } while (function > 3 || function <= 0);
    return 0;
}
//���߽���
void reader()
{
    Reader reader, tempReader; //��ʱ��Ϣ
    int exist;                 //�Ƿ���ڶ�����Ϣ
    int readerNumber;          //��������
    int function;              //����ѡ��
    //���������Ϣ
    do
    {
        printf("����ģʽ\n");
        FILE *fp = fopen("reader.txt", "r");
        exist = 0;
        printf("���������ı�ţ�");
        scanf("%d", &reader.number);
        printf("����������������");
        scanf("%s", reader.name);
        fscanf(fp, "%d", &readerNumber);
        for (int i = 0; i < readerNumber; i++)
        {
            fscanf(fp, "%d%s", &tempReader.number, tempReader.name);
            if (reader.number == tempReader.number &&
                !strcmp(reader.name, tempReader.name))
            {
                printf("��½�ɹ���\n");
                fclose(fp);
                exist = 1;
                printf("������������û����档\n");
                getch();
                system("cls");
                break;
            }
        }
        if (!exist)
        {
            printf("�����������ƥ�䡣���������롣\n");
        }
    } while (!exist);
    //ѡ����
    do
    {
        printf("��ѡ���ܣ�\n");
        printf("1.�鼮�б�\n2.�鼮��ѯ\n3.�鼮����\n4.�鼮�黹\n5.����\n");
        scanf("%d", &function);
        system("cls");
        switch (function)
        {
        case 1:
            bookList();
            break;
        case 2:
            seek();
            break;
        case 3:
            borrow(reader);
            break;
        case 4:
            sendBack(reader);
        case 5:
            break;
        default:
            printf("�����������������롣\n");
            break;
        }
    } while (function != 5);
}
//��Ӷ���
int addReader()
{
    int exist;
    int readerNumber;
    Reader tempReader, reader;
    FILE *fpReader;
    FILE *bufferReader;
    do
    {
        fpReader = fopen("reader.txt", "r");
        bufferReader = fopen("bufferReader.txt", "w");
        exist = 0;
        printf("��������Ҫ����Ķ��߱�ţ�");
        scanf("%d", &reader.number);
        printf("��������Ҫ����Ķ���������");
        scanf("%s", reader.name);
        fscanf(fpReader, "%d", &readerNumber);
        fprintf(bufferReader, "%d\n", readerNumber + 1);
        for (int i = 0; i < readerNumber; i++)
        {
            fscanf(fpReader, "%d %s %s", &tempReader.number, tempReader.name,
                   tempReader.bookName);
            if (tempReader.number == reader.number ||
                !strcmp(tempReader.name, reader.name))
            {
                printf("���߱�Ż������Ѵ��ڣ����޸���Ϣ��\n");
                fclose(fpReader);
                fclose(bufferReader);
                exist = 1;
                break;
            }
            fprintf(bufferReader, "%d %s %s\n", tempReader.number, tempReader.name,
                    tempReader.bookName);
        }
    } while (exist);
    fclose(fpReader);
    fclose(bufferReader);
    bufferReader = fopen("bufferReader.txt", "a");
    fprintf(bufferReader, "%d %s none\n", reader.number, reader.name);
    fclose(bufferReader);
    remove("reader.txt");
    rename("bufferReader.txt", "reader.txt");
    printf("������ӳɹ���\n");
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}
//ɾ������
int delReader()
{
    int exist;
    int readerNumber;
    Reader tempReader, reader;
    FILE *fpReader;
    FILE *bufferReader;

    do
    {
        exist = 0;
        fpReader = fopen("reader.txt", "r");
        bufferReader = fopen("bufferReader.txt", "w");
        printf("��������Ҫɾ���Ķ��߱��(�������֮��������һ��)��");
        scanf("%d", &reader.number);
        printf("��������Ҫɾ���Ķ�������(�������֮��������һ��)��");
        scanf("%s", reader.name);
        fscanf(fpReader, "%d", &readerNumber);
        fprintf(bufferReader, "%d\n", readerNumber - 1);
        for (int i = 0; i < readerNumber; i++)
        {
            fscanf(fpReader, "%d %s %s", &tempReader.number, tempReader.name,
                   tempReader.bookName);
            if (tempReader.number == reader.number ||
                !strcmp(tempReader.name, reader.name))
            {
                exist = 1;
            }
            else
            {
                fprintf(bufferReader, "%d %s %s\n", tempReader.number, tempReader.name,
                        tempReader.bookName);
            }
        }
        if (exist == 0)
        {
            printf("������Ϣ�����ڡ����������롣\n");
            fclose(fpReader);
            fclose(bufferReader);
        }
        else
        {
            printf("ɾ�����߳ɹ���\n");
        }
    } while (!exist);
    fclose(fpReader);
    fclose(bufferReader);
    remove("reader.txt");
    rename("bufferReader.txt", "reader.txt");
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}

int modifyReader()
{
    int exist;
    int readerNumber;
    Reader tempReader, reader, intention;
    FILE *fpReader;
    FILE *bufferReader;
    do
    {
        exist = 0;
        fpReader = fopen("reader.txt", "r");
        bufferReader = fopen("bufferReader.txt", "w");
        printf("��������Ҫ�޸ĵĶ��߱��(�������֮��������һ��)��");
        scanf("%d", &reader.number);
        printf("��������Ҫ�޸ĵĶ�������(�������֮��������һ��)��");
        scanf("%s", reader.name);
        printf("�������޸ĺ�Ķ��߱�ţ�");
        scanf("%d", &intention.number);
        printf("�������޸ĺ�Ķ���������");
        scanf("%s", intention.name);
        printf("�������޸ĺ�Ķ��߽������(���޽�������дnone)��");
        scanf("%s", intention.bookName);

        fscanf(fpReader, "%d", &readerNumber);
        fprintf(bufferReader, "%d\n", readerNumber);
        for (int i = 0; i < readerNumber; i++)
        {
            fscanf(fpReader, "%d %s %s", &tempReader.number, tempReader.name,
                   tempReader.bookName);
            if (tempReader.number == reader.number ||
                !strcmp(tempReader.name, reader.name))
            {
                fprintf(bufferReader, "%d %s %s\n", intention.number, intention.name,
                        intention.bookName);
                exist = 1;
            }
            else
            {
                fprintf(bufferReader, "%d %s %s\n", tempReader.number, tempReader.name,
                        tempReader.bookName);
            }
        }
        if (exist == 0)
        {
            printf("������Ϣ�����ڡ����������롣\n");
            fclose(fpReader);
            fclose(bufferReader);
        }
        else
        {
            printf("�޸Ķ�����Ϣ�ɹ���\n");
        }
    } while (!exist);
    fclose(fpReader);
    fclose(bufferReader);
    remove("reader.txt");
    rename("bufferReader.txt", "reader.txt");
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}
//����鼮
int addBook()
{
    int exist;
    int BookNumber;
    Book tempBook, Book;
    FILE *fpBook;
    FILE *bufferBook;
    do
    {
        fpBook = fopen("Book.txt", "r");
        bufferBook = fopen("bufferBook.txt", "w");
        exist = 0;
        printf("��������Ҫ������鼮��ţ�");
        scanf("%d", &Book.number);
        printf("��������Ҫ������鼮���ƣ�");
        scanf("%s", Book.bookName);
        printf("��������Ҫ������鼮������");
        scanf("%d", &Book.amount);
        fscanf(fpBook, "%d", &BookNumber);
        fprintf(bufferBook, "%d\n", BookNumber + 1);
        for (int i = 0; i < BookNumber; i++)
        {
            fscanf(fpBook, "%d %s %d", &tempBook.number, tempBook.bookName,
                   &tempBook.amount);
            if (tempBook.number == Book.number ||
                !strcmp(tempBook.bookName, Book.bookName))
            {
                printf("�鼮�Ѵ��ڣ����޸���Ϣ��\n");
                fclose(fpBook);
                fclose(bufferBook);
                exist = 1;
                break;
            }
            fprintf(bufferBook, "%d %s %d\n", tempBook.number, tempBook.bookName,
                    tempBook.amount);
        }
    } while (exist);
    fclose(fpBook);
    fclose(bufferBook);
    bufferBook = fopen("bufferBook.txt", "a");
    fprintf(bufferBook, "%d %s %d\n", Book.number, Book.bookName, Book.amount);
    fclose(bufferBook);
    remove("Book.txt");
    rename("bufferBook.txt", "Book.txt");
    printf("����鼮�ɹ���\n");
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}
//ɾ���鼮
int delBook()
{
    int exist;
    int BookNumber;
    Book tempBook, Book;
    FILE *fpBook;
    FILE *bufferBook;
    do
    {
        exist = 0;
        fpBook = fopen("Book.txt", "r");
        bufferBook = fopen("bufferBook.txt", "w");
        printf("��������Ҫɾ�����鼮���(�������֮��������һ��)��");
        scanf("%d", &Book.number);
        printf("��������Ҫɾ�����鼮����(�������֮��������һ��)��");
        scanf("%s", Book.bookName);
        fscanf(fpBook, "%d", &BookNumber);
        fprintf(bufferBook, "%d\n", BookNumber - 1);
        for (int i = 0; i < BookNumber; i++)
        {
            fscanf(fpBook, "%d %s %d", &tempBook.number, tempBook.bookName,
                   &tempBook.amount);
            if (tempBook.number == Book.number ||
                !strcmp(tempBook.bookName, Book.bookName))
            {
                exist = 1;
            }
            else
            {
                fprintf(bufferBook, "%d %s %d\n", tempBook.number, tempBook.bookName,
                        tempBook.amount);
            }
        }
        if (exist == 0)
        {
            printf("�鼮��Ϣ�����ڡ����������롣\n");
            fclose(fpBook);
            fclose(bufferBook);
        }
        else
        {
            printf("ɾ���鼮�ɹ���\n");
        }
    } while (!exist);
    fclose(fpBook);
    fclose(bufferBook);
    remove("Book.txt");
    rename("bufferBook.txt", "Book.txt");
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}
//�޸��鼮��Ϣ
int modifyBook()
{
    int exist;
    int BookNumber;
    Book tempBook, Book, intention;
    FILE *fpBook;
    FILE *bufferBook;
    do
    {
        exist = 0;
        fpBook = fopen("Book.txt", "r");
        bufferBook = fopen("bufferBook.txt", "w");
        printf("��������Ҫ�޸ĵ��鼮���(�������֮��������һ��)��");
        scanf("%d", &Book.number);
        printf("��������Ҫ�޸ĵ��鼮����(�������֮��������һ��)��");
        scanf("%s", Book.bookName);
        printf("�������޸ĺ���鼮��ţ�");
        scanf("%d", &intention.number);
        printf("�������޸ĺ���鼮���ƣ�");
        scanf("%s", intention.bookName);
        printf("�������޸ĺ���鼮������");
        scanf("%d", &intention.amount);

        fscanf(fpBook, "%d", &BookNumber);
        fprintf(bufferBook, "%d\n", BookNumber);
        for (int i = 0; i < BookNumber; i++)
        {
            fscanf(fpBook, "%d %s %d", &tempBook.number, tempBook.bookName,
                   &tempBook.amount);
            if (tempBook.number == Book.number ||
                !strcmp(tempBook.bookName, Book.bookName))
            {
                fprintf(bufferBook, "%d %s %d\n", intention.number, intention.bookName,
                        intention.amount);
                exist = 1;
            }
            else
            {
                fprintf(bufferBook, "%d %s %d\n", tempBook.number, tempBook.bookName,
                        tempBook.amount);
            }
        }
        if (exist == 0)
        {
            printf("�鼮��Ϣ�����ڡ����������롣\n");
            fclose(fpBook);
            fclose(bufferBook);
        }
        else
        {
            printf("�޸��鼮��Ϣ�ɹ���\n");
        }
    } while (!exist);
    fclose(fpBook);
    fclose(bufferBook);
    remove("Book.txt");
    rename("bufferBook.txt", "Book.txt");
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}
//������Ϣ�б�
int readerList()
{
    int readerNumber;
    Reader tempReader;
    FILE *fpReader = fopen("reader.txt", "r");
    fscanf(fpReader, "%d", &readerNumber);
    printf("����%dλ���ߡ�\n", readerNumber);
    printf("���\t����\t�����鼮\n");
    for (int i = 0; i < readerNumber; i++)
    {
        fscanf(fpReader, "%d\t%s\t%s", &tempReader.number, tempReader.name,
               tempReader.bookName);
        printf("%d\t%s\t%s\n", tempReader.number, tempReader.name,
               tempReader.bookName);
    }
    fclose(fpReader);
    printf("��������������������档\n");
    getch();
    system("cls");
    return 0;
}
//����Ա����
int manager()
{
    int function;
    do
    {
        printf("����Աģʽ\n");
        printf("��ѡ���ܣ�\n");
        printf("1.�鼮�б�\n2.����鼮\n3.ɾ���鼮\n4.�޸��鼮��Ϣ\n5.�����б�\n6."
               "��Ӷ���\n7.ɾ������\n8.�޸Ķ�����Ϣ\n9.����\n");
        scanf("%d", &function);
        system("cls");
        switch (function)
        {
        case 1:
            bookList();
            break;
        case 2:
            addBook();
            break;
        case 3:
            delBook();
            break;
        case 4:
            modifyBook();

            break;
        case 5:
            readerList();
            break;
        case 6:
            addReader();
            break;
        case 7:
            delReader();
            break;
        case 8:
            modifyReader();
            break;
        case 9:
            break;
        default:
            printf("�����������������롣");
            break;
        }
    } while (function != 9);
    return 0;
}
//������
int main()
{
    int function;
    do
    {
        printf("ͼ��ݹ���ϵͳ\n");
        printf("��ѡ���ܣ�\n");
        printf("1.����ģʽ\n2.����Աģʽ\n3.����\n");
        scanf("%d", &function);
        system("cls");
        switch (function)
        {
        case 1:
            reader();
            break;
        case 2:
            manager();
            break;
        default:
            printf("�����������������롣\n");
            break;
        }
    } while (function != 3);
    return 0;
}
