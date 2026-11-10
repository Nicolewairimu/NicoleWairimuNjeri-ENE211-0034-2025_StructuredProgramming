#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int amount;
int mpesaBalance = 50000;
int newMpesaBalance;
int dailyAmount = 500000;
int newDailyAmount;

int createPin();
void sendMoney(int correctPin);
void withdrawCash();
void buyAirtime();
void loansAndSavings();
void lipaNaMpesa();
void myAccount();


int main() {
    int systemPin = createPin();

    int mainMenuOption;
    int mpesaOption;

    printf("======WELCOME TO SAFARICOM SERVICES=====\n");
    printf("Choose an option(1 or 2)\n");
    printf("1. SAFARICOM+ \n2. MPESA\n");

    if (scanf("%d", &mainMenuOption) != 1) {
        while (getchar() != '\n');
        return 0;
    }

    if (mainMenuOption == 1) {
        printf("Welcome to SAFARICOM+\n");
    }
    else {
        printf("Welcome to MPESA\n");
        printf("1. Send Money\n2. Withdraw Cash\n3. Buy Airtime\n4. Loans and Savings\n5. Lipa na Mpesa\n6. My Account\n(Input 1-6)\n");

        if (scanf("%d", &mpesaOption) != 1) {
            while (getchar() != '\n');
            return 0;
        }

        switch (mpesaOption) {
            case 1:
                sendMoney(systemPin);
                break;
            case 2:
                withdrawCash(systemPin);
                break;
            case 3:
                buyAirtime(systemPin);
                break;
            case 4:
                loansAndSavings(systemPin);
                break;
            case 5:
                lipaNaMpesa(systemPin);
                break;
            case 6:
                myAccount(systemPin);
                break;
            default:
                printf("Invalid input! Input 1-6\n");
                break;
        }
    }

    return 0;
}

int createPin() {
    int confirmPin;
    int isValid = 0;
    int pin;

    printf("=== SYSTEM SETUP: CREATE YOUR PIN ===\n");

    do {
        int pinValid = 0;
        do {
            printf("Enter a 4-digit PIN: ");
            int result = scanf("%d", &pin);

            if (result != 1) {
                printf("Invalid input! Please enter digits only.\n");
                while (getchar() != '\n');
            } else {
                char str[50];
                sprintf(str, "%d", pin);
                if (strlen(str) != 4) {
                    printf("Invalid length! Your PIN must be exactly 4 digits.\n");
                } else {
                    pinValid = 1;
                }
            }
        } while (pinValid == 0);

        int confirmValid = 0;
        do {
            printf("Confirm your 4-digit PIN: ");
            int result = scanf("%d", &confirmPin);

            if (result != 1) {
                printf("Invalid input! Please enter digits only.\n");
                while (getchar() != '\n');
            } else {
                char str[50];
                sprintf(str, "%d", confirmPin);
                if (strlen(str) != 4) {
                    printf("Invalid length! Your PIN must be exactly 4 digits.\n");
                } else {
                    confirmValid = 1;
                }
            }
        } while (confirmValid == 0);

        if (pin == confirmPin) {
            printf("PIN successfully created and verified!\n\n");
            isValid = 1;
        } else {
            printf("PINs do not match! Let's try setting it up again.\n\n");
            isValid = 0;
        }

    } while (isValid == 0);

    return pin;
}

void sendMoney(int correctPin) {
    int phoneNumber;
    int isPhoneValid = 0;
    int isAmountValid = 0;


    do {
        printf("Enter the phone number: ");
        int result = scanf("%d", &phoneNumber);

        if (result != 1) {
            printf("Invalid input! Please enter digits only.\n");
            while (getchar() != '\n');
            isPhoneValid = 0;
        }
        else {
            char str[50];
            sprintf(str, "%d", phoneNumber);
            int length = strlen(str);

            if (length != 9) {
                printf("Invalid length! Must be 9 digits (you entered %d digits).\n", length);
                isPhoneValid = 0;
            }
            else {
                isPhoneValid = 1;
            }
        }
    } while (isPhoneValid == 0);


    do {
        printf("Enter the amount to send: ");
        int result = scanf("%d", &amount);

        if (result != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n');
            isAmountValid = 0;
        }
        else if (amount <= 0) {
            printf("Invalid amount! Amount must be greater than 0.\n");
            isAmountValid = 0;
        }
        else if (amount > mpesaBalance) {
            printf("Insufficient funds! Your current balance is %d.\n", mpesaBalance);
            isAmountValid = 0;
        }
        else if (amount > dailyAmount) {
            printf("Transaction failed! Amount exceeds your remaining daily limit of %d.\n", dailyAmount);
            isAmountValid = 0;
        }
        else {
            isAmountValid = 1;
        }
    } while (isAmountValid == 0);

    int newMpesaBalance = mpesaBalance - amount;
    int newDailyAmount = dailyAmount - amount;

    int userPin;
    printf("Enter your PIN: ");
    int result = scanf("%d", &userPin);

    if (result != 1) {
        printf("Invalid input! Please enter digits only.\n");
        while (getchar() != '\n');
        return;

    char str[50];
    sprintf(str, "%d", userPin);
    if (strlen(str) != 4) {
        printf("Invalid length! Must be 4 digits.\n");
        return;
    }


    if (userPin != correctPin) {
        printf("You have entered the wrong PIN! Transaction cancelled.\n");
        return;
    }


    printf("\n========================================\n");
    printf("         TRANSACTION SUCCESSFUL         \n");
    printf("========================================\n");
    printf("Sent to:              0%d\n", phoneNumber);
    printf("Amount Sent:          %d\n", amount);
    printf("New M-Pesa Balance:   %d\n", newMpesaBalance);
    printf("Remaining Daily Limit:%d\n", newDailyAmount);
    printf("========================================\n");
}

void withdrawCash(){

}
void buyAirtime(){

}
void loansAndSavings(){

}
void lipaNaMpesa(){

}
void myAccount(){

} /*

