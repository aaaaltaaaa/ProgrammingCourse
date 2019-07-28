#include <conio.h>
#include <stdio.h>
#include <string.h>
//读者信息
typedef struct
{
    int number;        //编号
    char name[20];     //名字
    char bookName[30]; //所借图书
} Reader;
//图书信息
typedef struct
{
    int number;        //编号
    char bookName[30]; //名字
    int amount;        //剩余数量
} Book;

//图书列表
void bookList()
{
    int bookNumber; //书本个数
    FILE *fp = fopen("book.txt", "r");
    Book book; //临时存储书籍信息
    fscanf(fp, "%d", &bookNumber);
    printf("共有%d本书。\n", bookNumber);
    printf("编号\t名称\t剩余数量\n");
    for (int i = 0; i < bookNumber; i++)
    { //读取并打印书籍
        fscanf(fp, "%d%s%d", &book.number, book.bookName, &book.amount);
        printf("%d\t%s\t%d\n", book.number, book.bookName, book.amount);
    }
    fclose(fp);
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
}
//借书
int borrow(Reader reader)
{
    Reader tempReader = {0, {'\0'}, {'\0'}};
    int readerNumber;  //读者数
    char bookName[30]; //所借书名
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
            { //判断是否有借书
                printf("您已借阅书籍，请归还后再借阅其他书籍。");
                fclose(fpReader);
                fclose(bufferReader);
                printf("按任意键返回至操作界面。\n");
                getch();
                system("cls");
                return -1;
            }
            printf("请输入需要借阅的图书名称：");
            scanf("%s", bookName);
            strcpy(tempReader.bookName, bookName);
            //借书
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
            //文件替换
            remove("book.txt");
            rename("bufferBook.txt", "book.txt");
            if (exist == 0)
            {
                printf("书籍不存在。");
                printf("按任意键返回至操作界面。\n");
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
    //文件替换
    remove("reader.txt");
    rename("bufferReader.txt", "reader.txt");
    printf("借书成功。");
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
    return 0;
}
//还书
int sendBack(Reader reader)
{
    Reader tempReader = {0, {'\0'}, {'\0'}};
    int readerNumber; //读者个数
    FILE *fpReader = fopen("reader.txt", "r");
    FILE *bufferReader = fopen("bufferReader.txt", "w");
    fscanf(fpReader, "%d", &readerNumber);
    fprintf(bufferReader, "%d\n", readerNumber);
    for (int i = 0; i < readerNumber; i++)
    {
        fscanf(fpReader, "%d %s %s", &tempReader.number, tempReader.name,
               tempReader.bookName);
        if (reader.number == tempReader.number || reader.name == tempReader.name) //是否借书
        {
            if (!strcmp(tempReader.bookName, "none"))
            {
                printf("您未借阅书籍。");
                fclose(fpReader);
                fclose(bufferReader);
                printf("按任意键返回至操作界面。\n");
                getch();
                system("cls");
                return -1;
            }
            //借书
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

            strcpy(tempReader.bookName, "none"); //修改借书信息
        }
        fprintf(bufferReader, "%d %s %s\n", tempReader.number, tempReader.name,
                tempReader.bookName);
    }
    fclose(fpReader);
    fclose(bufferReader);
    remove("reader.txt");
    rename("bufferReader.txt", "reader.txt");
    printf("还书成功。\n");
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
    return 0;
}
//按照编号找书
int seekByNum()
{
    int exist = 0;  //是否存在
    int seekNum;    //要找的书书籍编号
    int bookNumber; //书籍总数
    Book tempBook;  //临时存放书籍信息
    printf("请输入需要查询的书籍编号：");
    scanf("%d", &seekNum);
    FILE *fpBook = fopen("book.txt", "r");
    fscanf(fpBook, "%d", &bookNumber);
    for (int i = 0; i < bookNumber; i++) //查找图书
    {
        fscanf(fpBook, "%d%s%d", &tempBook.number, tempBook.bookName,
               &tempBook.amount);
        if (seekNum == tempBook.number)
        {
            exist = 1;
            printf("编号\t名称\t剩余数量\n");
            printf("%d\t%s\t%d\n", tempBook.number, tempBook.bookName,
                   tempBook.amount);
            break;
        }
    }
    if (!exist)
    {
        printf("书籍不存在。");
    }
    fclose(fpBook);
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
    return 0;
}
//按名字查找
int seekByName()
{
    int exist = 0;     //是否存在
    char seekName[30]; //查找书名
    int bookNumber;    //书籍总数
    Book tempBook;     //临时信息
    printf("请输入需要查询的书籍名称：");
    scanf("%s", seekName);
    FILE *fpBook = fopen("book.txt", "r");
    fscanf(fpBook, "%d", &bookNumber);
    for (int i = 0; i < bookNumber; i++) //查找书籍
    {
        fscanf(fpBook, "%d%s%d", &tempBook.number, tempBook.bookName,
               &tempBook.amount);
        if (!strcmp(seekName, tempBook.bookName))
        {
            exist = 1;
            printf("编号\t名称\t剩余数量\n");
            printf("%d\t%s\t%d\n", tempBook.number, tempBook.bookName,
                   tempBook.amount);
            break;
        }
    }
    if (!exist)
    {
        printf("书籍不存在。");
    }
    fclose(fpBook);
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
    return 0;
}
//查找
int seek()
{
    int function;
    do
    {
        printf("请选择查询方式：\n");
        printf("1.按书籍编号查询\n2.按书籍名字查询\n3.返回\n");
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
            printf("输入有误，请重新输入。\n");
            scanf("%d", &function);
        }
    } while (function > 3 || function <= 0);
    return 0;
}
//读者界面
void reader()
{
    Reader reader, tempReader; //临时信息
    int exist;                 //是否存在读者信息
    int readerNumber;          //读者总数
    int function;              //功能选择
    //输入读者信息
    do
    {
        printf("读者模式\n");
        FILE *fp = fopen("reader.txt", "r");
        exist = 0;
        printf("请输入您的编号：");
        scanf("%d", &reader.number);
        printf("请输入您的姓名：");
        scanf("%s", reader.name);
        fscanf(fp, "%d", &readerNumber);
        for (int i = 0; i < readerNumber; i++)
        {
            fscanf(fp, "%d%s", &tempReader.number, tempReader.name);
            if (reader.number == tempReader.number &&
                !strcmp(reader.name, tempReader.name))
            {
                printf("登陆成功。\n");
                fclose(fp);
                exist = 1;
                printf("按任意键进入用户界面。\n");
                getch();
                system("cls");
                break;
            }
        }
        if (!exist)
        {
            printf("编号与姓名不匹配。请重新输入。\n");
        }
    } while (!exist);
    //选择功能
    do
    {
        printf("请选择功能：\n");
        printf("1.书籍列表\n2.书籍查询\n3.书籍借阅\n4.书籍归还\n5.返回\n");
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
            printf("输入有误，请重新输入。\n");
            break;
        }
    } while (function != 5);
}
//添加读者
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
        printf("请输入需要加入的读者编号：");
        scanf("%d", &reader.number);
        printf("请输入需要加入的读者姓名：");
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
                printf("读者编号或姓名已存在，请修改信息。\n");
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
    printf("读者添加成功。\n");
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
    return 0;
}
//删除读者
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
        printf("请输入需要删除的读者编号(编号姓名之间至少填一个)：");
        scanf("%d", &reader.number);
        printf("请输入需要删除的读者姓名(编号姓名之间至少填一个)：");
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
            printf("读者信息不存在。请重新输入。\n");
            fclose(fpReader);
            fclose(bufferReader);
        }
        else
        {
            printf("删除读者成功。\n");
        }
    } while (!exist);
    fclose(fpReader);
    fclose(bufferReader);
    remove("reader.txt");
    rename("bufferReader.txt", "reader.txt");
    printf("按任意键返回至操作界面。\n");
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
        printf("请输入需要修改的读者编号(编号姓名之间至少填一个)：");
        scanf("%d", &reader.number);
        printf("请输入需要修改的读者姓名(编号姓名之间至少填一个)：");
        scanf("%s", reader.name);
        printf("请输入修改后的读者编号：");
        scanf("%d", &intention.number);
        printf("请输入修改后的读者姓名：");
        scanf("%s", intention.name);
        printf("请输入修改后的读者借阅情况(若无借阅则填写none)：");
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
            printf("读者信息不存在。请重新输入。\n");
            fclose(fpReader);
            fclose(bufferReader);
        }
        else
        {
            printf("修改读者信息成功。\n");
        }
    } while (!exist);
    fclose(fpReader);
    fclose(bufferReader);
    remove("reader.txt");
    rename("bufferReader.txt", "reader.txt");
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
    return 0;
}
//添加书籍
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
        printf("请输入需要加入的书籍编号：");
        scanf("%d", &Book.number);
        printf("请输入需要加入的书籍名称：");
        scanf("%s", Book.bookName);
        printf("请输入需要加入的书籍数量：");
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
                printf("书籍已存在，请修改信息。\n");
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
    printf("添加书籍成功。\n");
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
    return 0;
}
//删除书籍
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
        printf("请输入需要删除的书籍编号(编号姓名之间至少填一个)：");
        scanf("%d", &Book.number);
        printf("请输入需要删除的书籍名称(编号姓名之间至少填一个)：");
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
            printf("书籍信息不存在。请重新输入。\n");
            fclose(fpBook);
            fclose(bufferBook);
        }
        else
        {
            printf("删除书籍成功。\n");
        }
    } while (!exist);
    fclose(fpBook);
    fclose(bufferBook);
    remove("Book.txt");
    rename("bufferBook.txt", "Book.txt");
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
    return 0;
}
//修改书籍信息
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
        printf("请输入需要修改的书籍编号(编号姓名之间至少填一个)：");
        scanf("%d", &Book.number);
        printf("请输入需要修改的书籍名称(编号姓名之间至少填一个)：");
        scanf("%s", Book.bookName);
        printf("请输入修改后的书籍编号：");
        scanf("%d", &intention.number);
        printf("请输入修改后的书籍名称：");
        scanf("%s", intention.bookName);
        printf("请输入修改后的书籍数量：");
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
            printf("书籍信息不存在。请重新输入。\n");
            fclose(fpBook);
            fclose(bufferBook);
        }
        else
        {
            printf("修改书籍信息成功。\n");
        }
    } while (!exist);
    fclose(fpBook);
    fclose(bufferBook);
    remove("Book.txt");
    rename("bufferBook.txt", "Book.txt");
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
    return 0;
}
//读者信息列表
int readerList()
{
    int readerNumber;
    Reader tempReader;
    FILE *fpReader = fopen("reader.txt", "r");
    fscanf(fpReader, "%d", &readerNumber);
    printf("共有%d位读者。\n", readerNumber);
    printf("编号\t姓名\t所借书籍\n");
    for (int i = 0; i < readerNumber; i++)
    {
        fscanf(fpReader, "%d\t%s\t%s", &tempReader.number, tempReader.name,
               tempReader.bookName);
        printf("%d\t%s\t%s\n", tempReader.number, tempReader.name,
               tempReader.bookName);
    }
    fclose(fpReader);
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
    return 0;
}
//管理员界面
int manager()
{
    int function;
    do
    {
        printf("管理员模式\n");
        printf("请选择功能：\n");
        printf("1.书籍列表\n2.添加书籍\n3.删除书籍\n4.修改书籍信息\n5.读者列表\n6."
               "添加读者\n7.删除读者\n8.修改读者信息\n9.返回\n");
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
            printf("输入有误，请重新输入。");
            break;
        }
    } while (function != 9);
    return 0;
}
//主函数
int main()
{
    int function;
    do
    {
        printf("图书馆管理系统\n");
        printf("请选择功能：\n");
        printf("1.读者模式\n2.管理员模式\n3.返回\n");
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
            printf("输入有误，请重新输入。\n");
            break;
        }
    } while (function != 3);
    return 0;
}
