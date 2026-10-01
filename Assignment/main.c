#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a;
    double b;
    double sum, subtract, multiplication, divide;

    printf("Please input a\n");
    scanf("%lf",&a);

    printf("Please input b\n");
    scanf("%lf",&b);

    sum = a + b;
    subtract = a - b;
    multiplication = a * b;
    divide = a / b;

    printf("\nSum is %lf\n",sum);
    printf("\nSubtract is %lf\n",subtract);
    printf("\nMultiplacaion is %lf\n",multiplication);
    printf("\nDivision is %lf\n",divide);


    return 0;
}
