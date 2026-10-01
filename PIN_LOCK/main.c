#include <stdio.h>
#include <stdlib.h>

int main()
{
    // if...else

    int correctPin = 1234;
    int enteredPin;

    printf("ENTER PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin == correctPin)
    {
        printf("Access Granted! Welcome.\n");
    }

    else
    {
        printf("Access Denied! Incorrect PIN.\n");
    }


    // if...else if

    int userPin;
    int correctPin = 1234;

    printf("ENTER PIN: ");
    scanf("%d", &userPin);

    if (userPin == correctPin)
    {
        printf("Access Granted!");
    }
    else if (userPin<1000)
    {
        printf("Pin is too short\n");
    }
    else if (userPin>9999)
    {
        printf("Pin is too long\n");
    }
    else
    {
        printf("Access Denied! Incorrect Pin\n");
    }


    // Pin door lock system counting 0 at the beginning and having number of attempt limit

      char userPin[10];
      char correctPin[10];
      int maxAttempts = 3;
      int attempts = 0;


      while (1)
      {
        printf("Enter your userPin:\n");
        scanf("%s", userPin);


        int length = 0;
        while (userPin[length] != 0) {
            length = length + 1;
        }

        if (length < 4) {
            printf("PIN is too short! Enter 4 Digits\n");
        }
        else if (length > 4) {
            printf("PIN is too long! Enter 4 Digits\n");
        }
        else {
            printf("PIN is set kindly do not forget!\n");
            break;
        }
      }


      while (attempts < maxAttempts)
      {
        printf("Enter the correctPin:\n");
        scanf("%s", correctPin);

        int enteredLength = 0;
        while (correctPin[enteredLength] != 0) {
            enteredLength = enteredLength + 1;
        }

        if (enteredLength < 4) {
            printf("PIN is too short! Enter 4 Digits\n");
            continue;
        }
        else if (enteredLength > 4) {
            printf("PIN is too long! Enter 4 Digits\n");
            continue;
        }
        else {
            int mismatches = 0;
            for (int i = 0; i < 4; i++) {
                if (correctPin[i] != userPin[i]) {
                    mismatches = mismatches + 1;
                }
            }

            if (mismatches == 0) {
                printf("Correct Pin. Access Granted\n");
                return 0;
            }
            else {
                attempts = attempts + 1;
                int remaining = maxAttempts - attempts;
                printf("Incorrect! %d more attempts remaining\n", remaining);
            }
        }
      }

    printf("Incorrect! 0 attempts remaining. Kindly Contact Admin\n");


    return 0;
}
