#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	FILE *fp1, *fp2;													  //�ļ�ָ��
	char fileName1[100], fileName2[100];								  //�ļ���
	printf("�����ܣ��Ƚ������ı��ļ�����ӡ�����ǵ�һ������ͬ���С�\n"); //����˵��
	printf("��������Ҫ�Ƚϵ������ļ��ļ����������������ļ�Ϊ1.txt��2.txt��\n");
	scanf("%s%s", fileName1, fileName2);
	if ((fp1 = fopen(fileName1, "r")) != NULL && (fp2 = fopen(fileName2, "r")) != NULL) //�ж��ļ��Ƿ�ɹ���
	{
		char ch1[80], ch2[80]; //��ʱ�洢ÿ�е��ַ�
		for (int i = 1; !feof(fp1) && !feof(fp2); i++)
		{
			//����ÿ��
			fgets(ch1, 100, fp1);
			fgets(ch2, 100, fp2);
			//�Ƚϲ���ӡ�׸���ͬ��
			if (strcmp(ch1, ch2))
			{
				printf("�ļ���%d�в�һ��\n", i);
				printf("�ļ�%s��Ϊ%s\n", fileName1, ch1);
				printf("�ļ�%s��Ϊ%s\n", fileName2, ch2);
				break; //�ҵ���һ����ͬ���к�����ѭ��
			}
		}
		//�ر��ļ�
		fclose(fp1);
		fclose(fp2);
	}
	else
		printf("���ļ�ʧ�ܡ�\n");
	return 0;
}
