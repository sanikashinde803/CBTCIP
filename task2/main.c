#include <stdio.h>
#include "account.h"
#include "account.c"

#define MAX_ACCOUNTS 100

void printMenu() {
    printf("Bank Account Management System\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Check Balance\n");
    printf("5. Calculate Interest\n");
    printf("6. Exit\n");
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice, accountNumber;
    double amount, interestRate;
    char accountHolder[NAME_LEN];
    AccountType type;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter account holder name: ");
                scanf("%s", accountHolder);
                printf("Enter account type (0 for SAVINGS, 1 for CURRENT): ");
                scanf("%d", &type);
                printf("Enter interest rate: ");
                scanf("%lf", &interestRate);

                createAccount(&accounts[accountCount], accountNumber, accountHolder, type, interestRate);
                accountCount++;
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter deposit amount: ");
                scanf("%lf", &amount);
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].accountNumber == accountNumber) {
                        deposit(&accounts[i], amount);
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter withdrawal amount: ");
                scanf("%lf", &amount);
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].accountNumber == accountNumber) {
                        withdraw(&accounts[i], amount);
                        break;
                    }
                }
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].accountNumber == accountNumber) {
                        checkBalance(&accounts[i]);
                        break;
                    }
                }
                break;
            case 5:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].accountNumber == accountNumber) {
                        calculateInterest(&accounts[i]);
                        break;
                    }
                }
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
