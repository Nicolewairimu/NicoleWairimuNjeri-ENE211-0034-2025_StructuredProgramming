#include <stdio.h>

int main()
{
    int numStudents;

    printf("Enter number of students (N): ");
    scanf("%d", &numStudents);
    printf("\n");

    for (int i = 1; i <= numStudents; i++) {
        char regNum[50];
        char name[50];
        int marks;
        char grade;

        printf("=== Input Details for Student %d ===\n", i);
        printf("Enter Registration Number: ");
        scanf("%s", regNum);

        printf("Enter Name: ");
        scanf("%s", name);

        printf("Enter Marks (0-100): ");
        scanf("%d", &marks);


        if (marks < 0 || marks > 100) {
            grade = '?';
        } else {
            switch (marks / 10) {
                case 10:
                case 9:
                case 8:
                case 7:
                    grade = 'A';
                    break;
                case 6:
                    grade = 'B';
                    break;
                case 5:
                    grade = 'C';
                    break;
                case 4:
                    grade = 'D';
                    break;
                default:
                    grade = 'F';
                    break;
            }
        }


        printf("       STUDENT INFORMATION        \n");
        printf("Registration No: %s\n", regNum);
        printf("Name:            %s\n", name);
        printf("Marks:           %d\n", marks);
        printf("Grade:           %c\n", grade);
        if (marks >= 40) {
            printf("Status:          Passed\n");
        } else {
            printf("Status:          Failed\n");
        }
    }

    return 0;
}
