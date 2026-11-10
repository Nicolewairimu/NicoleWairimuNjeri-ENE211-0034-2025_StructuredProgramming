#include <stdio.h>
#include <stdlib.h>

int addition(int a, int b){
    int sum = a + b;
    return sum;
}

int main()
{
    int a;
    int b;

    printf("Enter an integer value(0-9)\n");
    scanf("%d", a);
    printf("Enter another integer value(0-9)\n");
    scanf("%d", b);

    int result = addition(a,b);
    printf("Sum = %d", result);

    return 0;
}
