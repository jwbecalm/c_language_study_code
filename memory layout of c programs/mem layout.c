


#include <stdio.h>
#include <stdlib.h>

int ga_i = 0;   // global initialized segment


char *p1;     // global uninitialized segment

int main(int argc, char const *argv[])
{
    int i = 0;          // stack

    char s[] = "abc";   //stack

    char *p2;           //stack

    static int a = 0;   //golbal initialized segment

    p2 = malloc(100);     
    printf("&p2: %p\n", &p2);   // p2 as the pointer variable, it address is in the stack;
    printf("p2: %p\n", p2);     // but the allocated memory by malloc,it's address is in heap.

    return 0;
}
