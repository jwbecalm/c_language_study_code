// 规则2、数组下标总是与指针的偏移量相同

#include <stdio.h>


int main(int argc, char const *argv[])
{
    int a[10], *p, i;

    // 通过数组下标访问数组元素
    printf("通过数组下标访问数组元素\n");
    for (i = 0; i < 10; i++)
    {
        a[i] = i;
        printf("a[%d]=%d\n",i,a[i]);
    }

    //把指针名当做数组名，并使用下标访问
    p = a;
    printf("把指针名当做数组名，并使用下标访问\n");
    for (i = 0; i < 10; i++)
    {
        p[i] = i;
        printf("p[%d]=%d\n",i,p[i]);
    }

    // 利用指针偏移量访问数组元素，*表示取指针所在地址内容
    printf("利用指针偏移量访问数组元素，*表示取指针所在地址内容\n");
    p = a;
    for (i = 0; i < 10 ;i++)
    {
        *(p+i) = i;
        printf("*(p+%d)=%d\n", i, *(p+i));
    }

    return 0;
}
