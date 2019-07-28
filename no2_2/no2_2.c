#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    FILE *fp; //�ļ�ָ��
    char ch;
    int charNum[26] = {0}; //��¼���ִ���
    int num;
    char fileName[100]; //�ļ���
    printf("������:"
           "ͳ��һ��Ӣ���ı��ļ���26��Ӣ����ĸ���ִ�������Ӣ����ĸ�����ͳ�ƽ��"
           "�����Ҳ��滻��Ӣ���ı��ļ���ĳ�ַ�����\n"); //����˵��
    printf("��������Ҫ���б�������Դ�ļ�����\n");
    scanf("%s", fileName);
    if ((fp = fopen(fileName, "r")) != NULL) //�ж��ļ��Ƿ�ɹ���
    {
        //��ȡ���ж��Ƿ�Ϊ��ĸ����¼��ĸ���ִ���
        for (int i = 0; !feof(fp); ++i)
        {
            fscanf(fp, "%c", &ch);
            if ((ch - 'a' >= 0 && ch - 'a' <= 25) ||
                (ch - 'A' >= 0 && ch - 'A' <= 25))
            {
                num = (ch - 'a' + 32) % 32;
                charNum[num]++;
            }
        }
        fclose(fp);
    }
    else
    {
        printf("���ļ�ʧ�ܡ�\n");
        return -1;
    }
    //���ͳ�ƽ��
    for (int i = 0; i < 26; i++)
    {
        printf("%c���ֵĴ���Ϊ%d\n", (i + 'a'), charNum[i]);
    }

    //�����滻����

    char pre[100] = {'\0'}, now[100] = {'\0'}, temp[100] = {'\0'};
    printf("��������Ҫ�滻���ַ�����");
    scanf("%s", pre);
    printf("������Ŀ���ַ�����");
    scanf("%s", now);

    if ((fp = fopen(fileName, "r")) != NULL) //�ж��ļ��Ƿ�ɹ���
    {
        FILE *fpOut;
        long position;
        fpOut = fopen("no2_2.txt", "w");
        for (int i = 0; !feof(fp); ++i)
        {
            position = ftell(fp);
            fgets(temp, strlen(pre) + 1, fp);
            if (!strcmp(temp, pre))
            {
                fputs(now, fpOut);
            }
            else
            {
                fseek(fp, position, 0);
                fputc(fgetc(fp), fpOut);
            }
        }
        fclose(fp);
        printf("�������ı�һ��������ǰĿ¼�µ�no2_2.txt�ļ���");
    }
    else
    {
        printf("���ļ�ʧ�ܡ�\n");
        return -1;
    }
    return 0;
}
