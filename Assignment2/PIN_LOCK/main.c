#include <stdio.h>
#include <unistd.h>

int main()
{
    char userPin[10];
    char confirmPin[10];
    char correctPin[10];
    int maxAttempts = 3;
    int attempts = 0;
    int authenticated = 0;

    printf("PIN SETUP\n\n");


    while (1) {
        printf("Enter your new PIN: ");
        scanf("%s", userPin);

        printf("Confirm your PIN: ");
        scanf("%s", confirmPin);


        int match = 1;
        int i = 0;
        while (userPin[i] != '\0' || confirmPin[i] != '\0') {
            if (userPin[i] != confirmPin[i]) {
                match = 0;
                break;
            }
            i++;
        }

        if (match == 1) {
            printf("PIN successfully set!\n\n");
            break;
        } else {
            printf("PINs do not match. Please try setting up your PIN again.\n\n");
        }
    }


    printf("=== PIN-Based Door Lock System ===\n\n");

    while (attempts < maxAttempts) {
        printf("Enter PIN to unlock: ");
        scanf("%s", correctPin);


        int enteredLength = 0;
        while (correctPin[enteredLength] != '\0') {
            enteredLength = enteredLength + 1;
        }


        if (enteredLength < 4) {
            printf("PIN is too short (must be 4 digits)\n\n");
            continue;
        }
        else if (enteredLength > 4) {
            printf("PIN is too long (must be 4 digits)\n\n");
            continue;
        }
        else {
            printf("PIN is exactly 4 digits\n");
        }


        int mismatches = 0;
        for (int i = 0; i < 4; i++) {
            if (correctPin[i] != userPin[i]) {
                mismatches = mismatches + 1;
            }
        }

        if (mismatches == 0) {
            printf("Correct PIN. Access Granted!\n");
            authenticated = 1;
            break;
        } else {
            attempts = attempts + 1;
            int remaining = maxAttempts - attempts;
            if (remaining > 0) {
                printf("Incorrect! %d more attempts remaining\n\n", remaining);
            }
        }
    }


    if (!authenticated) {
        printf("\nSystem locked! Wait for 5 seconds...\n");
        for (int i = 5; i >= 1; i--) {
            printf("%d...\n", i);
            sleep(1);
        }
        printf("You can try again now.\n");
        return 0;
    }


    int choice;
    printf("\n--- Device Menu ---\n");
    printf("1. Open Door\n");
    printf("2. Change Username\n");
    printf("3. Change PIN\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);


    switch (choice) {
        case 1:
            printf("Access granted. Door unlocked\n");
            break;
        case 2:
            printf("Change username feature coming soon.\n");
            break;
        case 3:
            printf("Change PIN feature coming soon.\n");
            break;
        case 4:
            printf("Exiting system.\n");
            break;
        default:
            printf("Invalid option! Please try again.\n");
            break;
    }

    return 0;
}
