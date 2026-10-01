#include <stdio.h>
#include <stdlib.h>

int main()
{
    //if...else if

    double marks;

    printf("Input the student marks\n");
    scanf("%lf", &marks);

    if (marks >= 70)
    {
    printf("Grade is A");
    }

    else if (marks >= 60)
    {
    printf("Grade is B");
    }

    else if (marks >= 50)
    {
    printf("Grade is C");
    }

    else if (marks >= 40)
    {
    printf("Grade is D");
    }

    else
    {
    printf("Grade is E");
    }


    //Switch case method

    int marks;

    printf("Please enter your marks:\n")
    scanf("%d",%marks);

    switch(marks/10)
    {
        case 10:
        case 9:
        case 8:
        case 7:
            Printf("Grade is an A\n");
            break;
        case 6:
            Printf("Grade is an B\n");
            break;
        case 5:
            Printf("Grade is an C\n");
            break;
        case 4:
            Printf("Grade is an D\n");
            break;
        case 3:
        case 2:
        case 1:
        case 0:
            Printf("Grade is an E\n");
            break;
        default:
            Printf("Invalid marks entered!\n");
            break;


    }

    return 0;
}
