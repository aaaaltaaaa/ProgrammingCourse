#include <stdio.h>
//复数
typedef struct
{
    float realPart;
    float imaginaryPart;
} complex;
//求和
complex summation(complex a, complex b)
{
    complex result;
    result.realPart = a.realPart + b.realPart;
    result.imaginaryPart = a.imaginaryPart + b.imaginaryPart;
    return result;
}
//求差
complex subtract(complex a, complex b)
{
    complex result;
    result.realPart = a.realPart - b.realPart;
    result.imaginaryPart = a.imaginaryPart - b.imaginaryPart;
    return result;
}
//求积
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
    complex a = {0, 0}, b = {0, 0}; //两个运算数
    complex result;                 //结果
    int type;                       //运算类型
    printf("程序功能:"
           "设计一个复数类型，输入实部和虚部生成一个复数，可进行两个复数求和、两"
           "个复数求差、两个复数求积运算。\n"); //功能说明
    //输入运算数
    printf("请输入第一个复数的实部\n");
    scanf("%f", &a.realPart);
    printf("请输入第一个复数的虚部\n");
    scanf("%f", &a.imaginaryPart);
    printf("第一个复数为：%f%+fi\n", a.realPart, a.imaginaryPart);
    printf("请输入第二个复数的实部\n");
    scanf("%f", &b.realPart);
    printf("请输入第二个复数的虚部\n");
    scanf("%f", &b.imaginaryPart);
    printf("第二个复数为：%f%+fi\n", b.realPart, b.imaginaryPart);
    //选择运算类型
    printf("请选择运算类型:1.求和\t2.求差\t3.求积\n");
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
        printf("运算类型不存在。");
        return 1;
    }
    printf("运算结果为：%f%+fi", result.realPart,
           result.imaginaryPart); //输出结果
    return 0;
}
