#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age;

    printf("What is your age?");
    scanf("%d",&age);

    if (age>18){
        printf("This is an adult\n");
    }

    return 0;
}
