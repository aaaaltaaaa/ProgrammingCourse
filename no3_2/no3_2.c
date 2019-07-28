#include <stdio.h>
//����
typedef struct
{
    float realPart;
    float imaginaryPart;
} complex;
//���
complex summation(complex a, complex b)
{
    complex result;
    result.realPart = a.realPart + b.realPart;
    result.imaginaryPart = a.imaginaryPart + b.imaginaryPart;
    return result;
}
//���
complex subtract(complex a, complex b)
{
    complex result;
    result.realPart = a.realPart - b.realPart;
    result.imaginaryPart = a.imaginaryPart - b.imaginaryPart;
    return result;
}
//���
complex multiply(complex a, complex b)
{
    complex result;
    result.realPart = a.realPart * b.realPart - a.imaginaryPart * b.imaginaryPart;
    result.imaginaryPart =
        a.realPart * b.imaginaryPart + a.imaginaryPart * b.realPart;
    return result;
}
int main(int argc, char const *argv[])
{
    complex a = {0, 0}, b = {0, 0}; //����������
    complex result;                 //���
    int type;                       //��������
    printf("������:"
           "���һ���������ͣ�����ʵ�����鲿����һ���������ɽ�������������͡���"
           "����������������������㡣\n"); //����˵��
    //����������
    printf("�������һ��������ʵ��\n");
    scanf("%f", &a.realPart);
    printf("�������һ���������鲿\n");
    scanf("%f", &a.imaginaryPart);
    printf("��һ������Ϊ��%f%+fi\n", a.realPart, a.imaginaryPart);
    printf("������ڶ���������ʵ��\n");
    scanf("%f", &b.realPart);
    printf("������ڶ����������鲿\n");
    scanf("%f", &b.imaginaryPart);
    printf("�ڶ�������Ϊ��%f%+fi\n", b.realPart, b.imaginaryPart);
    //ѡ����������
    printf("��ѡ����������:1.���\t2.���\t3.���\n");
    scanf("%d", &type);
    switch (type)
    {
    case 1:
        result = summation(a, b);
        break;
    case 2:
        result = subtract(a, b);
        break;
    case 3:
        result = multiply(a, b);
        break;
    default:
        printf("�������Ͳ����ڡ�");
        return 1;
    }
    printf("������Ϊ��%f%+fi", result.realPart,
           result.imaginaryPart); //������
    return 0;
}
