#include <stdio.h>
#include <string.h>
#include <unistd.h>

int login();
void showMenu();
void checkBalance(float balance);
float deposit(float balance);
float withdraw(float balance);
void exitATM();
int anotherTransaction();
float loadBalance();
void saveBalance(float balance);

int main() {
    if (!login()) {
        exitATM();
        return 0;
    }

    float balance = loadBalance();
    int choice;

    do {
        showMenu();
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        int transactionDone = 0;

        switch (choice) {
            case 1:
                checkBalance(balance);
                transactionDone = 1;
                break;
            case 2:
                balance = deposit(balance);
                transactionDone = 1;
                break;
            case 3:
                balance = withdraw(balance);
                transactionDone = 1;
                break;
            case 4:
                exitATM();
                break;
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }

        if (transactionDone) {
            if (!anotherTransaction()) {
                exitATM();
                break;
            }
        }

        if (choice != 4) {
            printf("\n----------------------------------------\n");
        }

    } while (choice != 4);

    return 0;
}

float loadBalance() {
    FILE *file = fopen("balance.txt", "r");
    float defaultBalance = 5000.00;

    if (file == NULL) {
        saveBalance(defaultBalance);
        return defaultBalance;
    }

    fscanf(file, "%f", &defaultBalance);
    fclose(file);
    return defaultBalance;
}

void saveBalance(float balance) {
    FILE *file = fopen("balance.txt", "w");
    if (file != NULL) {
        fprintf(file, "%.2f", balance);
        fclose(file);
    }
}

int login() {
    char correctPin[] = "1234";
    char enteredPin[10];
    int attempts = 0;
    int maxAttempts = 3;
    int authenticated = 0;

    while (attempts < maxAttempts) {
        printf("Enter 4-digit PIN to unlock: ");
        scanf("%s", enteredPin);

        int length = 0;
        while (enteredPin[length] != '\0') {
            length++;
        }

        if (length != 4) {
            printf("Error: PIN must be exactly 4 digits.\n\n");
            continue;
        }

        int mismatches = 0;
        for (int i = 0; i < 4; i++) {
            if (correctPin[i] != enteredPin[i]) {
                mismatches++;
            }
        }

        if (mismatches == 0) {
            printf("Correct PIN. Access Granted!\n\n");
            authenticated = 1;
            break;
        } else {
            attempts++;
            int remaining = maxAttempts - attempts;
            if (remaining > 0) {
                printf("Incorrect PIN. %d attempt(s) remaining.\n\n", remaining);
            }
        }
    }

    if (!authenticated) {
        printf("\nToo many incorrect attempts. System locked!\n");
        for (int i = 5; i >= 1; i--) {
            printf("%d...\n", i);
            sleep(1);
        }
        return 0;
    }

    return 1;
}

void showMenu() {
    printf("========================================\n");
    printf("              ATM MAIN MENU             \n");
    printf("========================================\n");
    printf("1. Balance Inquiry\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("----------------------------------------\n");
}

void checkBalance(float balance) {
    printf("\n--- Balance Inquiry ---\n");
    printf("Your current balance is: KES %.2f\n", balance);
}

float deposit(float balance) {
    float amount;
    printf("\n--- Deposit Funds ---\n");
    printf("Enter amount to deposit (or enter 0 to cancel): KES ");

    if (scanf("%f", &amount) != 1) {
        printf("Invalid input. Transaction cancelled.\n");
        while (getchar() != '\n');
        return balance;
    }

    if (amount == 0) {
        printf("Transaction cancelled. Returning to menu...\n");
        return balance;
    }

    if (amount < 0) {
        printf("Error: Amount must be greater than zero.\n");
    } else {
        balance += amount;
        saveBalance(balance);
        printf("Successfully deposited KES %.2f\n", amount);
        printf("New Balance: KES %.2f\n", balance);
    }
    return balance;
}

float withdraw(float balance) {
    float amount;
    printf("\n--- Withdraw Funds ---\n");
    printf("Enter amount to withdraw (or enter 0 to cancel): KES ");

    if (scanf("%f", &amount) != 1) {
        printf("Invalid input. Transaction cancelled.\n");
        while (getchar() != '\n');
        return balance;
    }

    if (amount == 0) {
        printf("Transaction cancelled. Returning to menu...\n");
        return balance;
    }

    if (amount < 0) {
        printf("Error: Amount must be greater than zero.\n");
    }
    else if (amount > balance) {
        printf("Error: Insufficient balance! You have KES %.2f\n", balance);
    } else {
        balance -= amount;
        saveBalance(balance);
        printf("Successfully withdrew KES %.2f\n", amount);
        printf("Remaining Balance: KES %.2f\n", balance);
    }
    return balance;
}

int anotherTransaction() {
    int choice;
    printf("\nWould you like to perform another transaction?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter choice (1 or 2): ");

    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice. Enter 1 for Yes or 2 for No: ");
        while (getchar() != '\n');
    }

    return (choice == 1);
}

void exitATM() {
    printf("\n========================================\n");
    printf("          SESSION TERMINATED            \n");
    printf("========================================\n");
    printf("-> Please remove your ATM card.\n");
    printf("-> Thank you for banking with us. Goodbye!\n");
    printf("========================================\n");
}
