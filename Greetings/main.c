#include <stdio.h>
#include <stdlib.h>

int main()
{
    char userName[50];
    double area;
    double PI = 3.142;
    double r;

    printf("Please enter Username: ");
    scanf("%s", userName);
    printf("Hello %s\n", userName);

    printf("Please provide the radius: ");
    scanf("%lf", &r);

    area = PI * r * r;
    printf("Your area is %lf\n", area);


    return 0;
}

