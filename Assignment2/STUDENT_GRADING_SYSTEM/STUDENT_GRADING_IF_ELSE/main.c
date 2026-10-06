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


        if (marks >= 70 && marks <= 100) {
            grade = 'A';
        } else if (marks >= 60) {
            grade = 'B';
        } else if (marks >= 50) {
            grade = 'C';
        } else if (marks >= 40) {
            grade = 'D';
        } else {
            grade = 'F';
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
