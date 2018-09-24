// 规则1、表达式中的数组名，被编译器当做一个指向该数组第一个元素的指针（ANSI C标准6.2.2.1节）
/*
但在下列情况下，对数组的引用不能用指向该数组的第一个元素的指针来代替：
1、数组作为sizeof()的操作数。显然此时需要的是整个数组的大小，而不是指针所指向的第一个元素的大小
2、使用&操作符取数组的地址
3、数组是一个字符串常量的初始值
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[10] = {0,1,2,3};
    int *p = NULL;

    // asign a array name to a pointer（rule 1）
    p = a;
    printf("a[0]=%d\n",a[0]);
    printf("*p=%d\n",*p);

    int i = 2;
    printf("a[i]=%d\n",a[i]);
    printf("*(p+i)=%d\n",*(p+i));

    //在对起始地址a执行加法时，编译器会按照数组元素的大小来计算每次增加的步长
    p = a + i;
    printf("*p=%d, after p = a + i\n",*p);


    return 0;
}





/*
运行结果
a[0]=0
*p=0
a[i]=2
*(p+i)=2
*p=2, after p = a + i

*/
