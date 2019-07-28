#include <conio.h>
#include <stdio.h>
#include <string.h>
#define MAXNUM 100
//将字符串转换为文件名
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
int add() //管理员添加歌曲功能
{
    FILE *fp;
    char singer[MAXNUM] = {'\0'}, song[MAXNUM] = {'\0'}, ch;
    //输入歌手
    printf("请输入添加歌曲的歌手名:");
    scanf("%s", singer);
    toFilename("singer", singer);
    fp = fopen(singer, "a");
    //添加歌曲索引
    printf("请输入添加歌曲：");
    scanf("%s", song);
    fputs(song, fp);
    fputs("\n", fp);
    fclose(fp);
    //添加歌词
    toFilename("song", song);
    fp = fopen(song, "w");
    printf("请输入歌词，结束输入eof。\n");
    while ((ch = getchar()) && ch != EOF)
    {
        fputc(ch, fp);
    }
    fclose(fp);
    printf("添加歌曲成功。按任意键返回。\n");
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
    return 0;
}

int del() //管理员删除歌曲的功能
{
    FILE *fp, *buffer;
    char song[MAXNUM] = {'\0'}, singer[MAXNUM] = {'\0'}, ch[MAXNUM];
    //输入信息
    printf("请输入删除的歌手名:");
    scanf("%s", singer);
    toFilename("singer", singer);
    fp = fopen(singer, "r+");
    if (fp == NULL)
    {
        printf("不存在此歌手\n");
        printf("按任意键返回至操作界面。\n");
        getch();
        system("cls");
        return 0;
    }
    buffer = fopen("./song/buffer.txt", "w+");
    printf("请输入删除的歌曲：");
    scanf("%s", song);
    //将歌手信息复制到缓冲文件中并删除相应的歌曲信息
    while (!feof(fp))
    {
        fscanf(fp, "%s", ch);
        if (strcmp(ch, song))
        {
            fprintf(buffer, "%s", ch);
        }
    }
    //关闭文件
    fclose(fp);
    fclose(buffer);
    //修改文件 
    remove(singer);
    rename("./song/buffer.txt",singer);
    //删除歌词
    toFilename("song", song);
    remove(song);
    printf("删除歌曲成功。");
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
    return 0;
}
//通过歌曲点歌
int chooseBySong()
{
    FILE *fp;
    char song[MAXNUM] = {'\0'}; //歌曲名
    printf("请输入歌曲名:");
    scanf("%s", song);
    toFilename("song", song);
    fp = fopen(song, "r");
    if (fp == NULL)
    {
        printf("歌曲不存在。\n");
        printf("按任意键返回至操作界面。\n");
        getch();
        system("cls");
        return -1;
    }
    printf(" >>歌词\n");
    while (!feof(fp)) //打印歌词
    {
        printf("%c", fgetc(fp));
    }
    fclose(fp);
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
    return 0;
}
//通过歌手点歌
int chooseBySinger()
{
    FILE *fp;
    char singer[MAXNUM] = {'\0'}; //歌手名
    char song[MAXNUM] = {'\0'};   //歌曲名
    printf("请输入歌手名：");
    scanf("%s", singer);
    toFilename("singer", singer);
    fp = fopen(singer, "r");
    if (fp == NULL)
    {
        printf("歌手不存在。\n");
        printf("按任意键返回至操作界面。\n");
        getch();
        system("cls");
        return -1;
    }
    printf("歌手全部歌曲如下:\n");
    while (!feof(fp)) //打印歌手所有歌曲
    {
        printf("%c", fgetc(fp));
    }
    fclose(fp);
    printf("请输入歌曲名:");
    scanf("%s", song);
    toFilename("song", song);
    fp = fopen(song, "r");
    if (fp == NULL)
    {
        printf("歌曲不存在。\n");
        printf("按任意键返回至操作界面。\n");
        getch();
        system("cls");
        return -1;
    }

    printf(">>歌词\n");
    while (!feof(fp)) //打印歌词
    {
        printf("%c", fgetc(fp));
    }
    fclose(fp);
    printf("按任意键返回至操作界面。\n");
    getch();
    system("cls");
    return 0;
}
//用户功能选择
void user()
{
    int function;
    do
    {
        printf(" KTV点歌系统\n请选择点歌方式。\n1.歌名点歌\n2.歌手点歌\n3.退出\n");
        scanf("%d", &function);
        system("cls");
        while (function != 1 && function != 2 && function != 3)
        {
            printf("输入有误，请重新输入:");
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
//管理员功能选择
void manager()
{
    int function;
    do
    {
        printf(" KTV 管理员系统 \n1.添加歌曲\n2.删除歌曲\n3.退出\n");
        scanf("%d", &function);
        system("cls");
        while (function != 1 && function != 2 && function != 3)
        {
            printf("输入有误，请重新输入:");
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
//主函数
int main(int argc, char const *argv[])
{
    int function;
    do
    {
        printf(" KTV系统\n1.管理员界面\n2.用户界面\n3.退出\n");
        scanf("%d", &function);
        system("cls");
        while (function != 1 && function != 2 && function != 3)
        {
            printf("输入有误，请重新输入:");
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
