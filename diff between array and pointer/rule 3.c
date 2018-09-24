// 规则3，“作为函数参数的数组名”，等同于指针
// 主要是基于效率的考虑，函数调用时不用传递整个数组。编译器会把数组形式改写为指向数组的第一个元素的指针
// 即：只有在把数组名作为函数参数时，声明和定义可以不一致；编译器会做上诉自动修改；在其他所有情况下，定义和申明必须匹配


#include <stdio.h>

// forward declarations
//当吧一个数组定义为函数的参数时，可以把他定义为数组，也可以定义为指针。
void func (int a[]);
void func2 (int *p,int len);

void func (int a[])
{
    int size;
    
    //当数组名作为函数参数时，要注意数组到指针的转变。
    //rule 1, Warning：sizeof on array function parameter will return size of 'int *' instead of 'int []'
    size = sizeof(a);
    printf("in the calling func, array name as func para, has changed to pointer, so sizof(array name) is: %d\n",size); 

    //所以建议始终把参数定义为指针，因为这是编译器内部所使用的形式，避免引起误使用。
}

void func2(int *p,int len)  //rule 3
{
    int i;
    printf("in the calling func2, the parameter is different from the argument. and it works.\n");

    for (i = 0; i < len; i++)
    {
        printf("%d ",*(p+i));   //rule 2
        if (i == len -1)    printf("\n");
    }
}
int main(int argc, char const *argv[])
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};

    int size;
    size = sizeof(a);
    printf("in main func, sizof(array name) is the total length of array: %d\n",size);

    //如果要计算数组的长度，可以使用
    int len;
    len = sizeof(a)/sizeof(a[0]);
    printf("length of array is: %d\n",len);

    func(a);

    func2(a,len);

    
    
    return 0;
}










/*
运行结果：
in main func, sizof(array name) is the total length of array: 40
length of array is: 10
in the calling func, array name as func para, has changed to pointer, so sizof(array name) is: 8
in the calling func2, the parameter is different from the argument. and it works.
0 1 2 3 4 5 6 7 8 9 

*/