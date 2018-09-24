// 规则3，“作为函数参数的数组名”，等同于指针
// 主要是基于效率的考虑，函数调用时不用传递整个数组。编译器会把数组形式改写为指向数组的第一个元素的指针

#include <stdio.h>

void func (int a[])
{
    int size;
    
    //当数组名作为函数参数时，要注意数组到指针的转变。
    //Warning：sizeof on array function parameter will return size of 'int *' instead of 'int []'
    size = sizeof(a);
    printf("in the calling func, array name as func para, has changed to pointer, so sizof(array name)=%d\n",size); 

    //所以建议始终把参数定义为指针，因为这是编译器内部所使用的形式，避免引起误使用。
}

int main(int argc, char const *argv[])
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};

    int size;
    size = sizeof(a);
    printf("in main func, sizof(array name) is the total length of array: %d\n",size);

    func(a);

    //如果要计算数组的长度，可以使用
    int len;
    len = sizeof(a)/sizeof(a[0]);
    printf("length of array is %d\n",len);
    
    return 0;
}
