#include <stdio.h>

char ga[] = {'j','w','b'};

void func_1(char ca[])
{
    printf("-----in func_1()---------------\n");
    printf("ca = %p\n", ca);
    printf("&ca = %p\n",&ca);
    printf("&(ca[0]) = %p\n", &(ca[0]) );
    printf("&(ca[1]) = %p\n", &(ca[1]) );

}

void func_2(char *pa)
{
    printf("-----in func_2()---------------\n");
    printf("pa =  %p\n",pa);
    printf("&pa = %p\n",&pa);
    printf("&(pa[0]) = %p\n", &(pa[0]) );
    printf("&(pa[1]) = %p\n", &(pa[1]) );
    printf("++pa = %p\n",++pa);

}

int main(int argc, char const *argv[])
{
    printf("-----in main()-----------------\n");

    char charArray[] = {'t','e','s','t'};
    printf("charArray = %p\n",charArray);
    printf("&charArry = %p\n",&charArray);

    printf("ga = %p\n",ga);
    printf("&ga = %p\n", &ga);
    printf("&(ga[0]) = %p\n&(ga[1]) = %p\n",  &(ga[0]), &(ga[1]));

    func_1(ga);
    func_2(ga);

    return 0;
}

/*
运行结果：
-----in main()-----------------
ga = 0x10a009018
&ga = 0x10a009018
&(ga[0]) = 0x10a009018
&(ga[1]) = 0x10a009019
-----in func_1()---------------
ca = 0x10a009018
&ca = 0x7ffee5bf7ab8
&(ca[0]) = 0x10a009018
&(ca[1]) = 0x10a009019
-----in func_2()---------------
pa =  0x10a009018
&pa = 0x7ffee5bf7ab8
&(pa[0]) = 0x10a009018
&(pa[1]) = 0x10a009019
++pa = 0x10a009019

说明：
1、首先不管在main函数中，还是在func_1和func_2中打印数组0号、1号元素的地址，都一样。
这样确保不同的函数调用方式下，访问到的数组内容都一致。

2、在main函数中打印&ga, 因为ga是字符数组名，根据规则1“表达式中的数组名，被编译器当做一个指向该数组第一个元素的指针”，
所以&ga即为第一个元素的地址

3、


*/
