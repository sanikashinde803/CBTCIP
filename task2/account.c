#include <stdio.h>
#include <string.h>
#include "account.h"

void createAccount(Account *account, int accountNumber, const char *accountHolder, AccountType type, double interestRate) {
    account->accountNumber = accountNumber;
    strncpy(account->accountHolder, accountHolder, NAME_LEN);
    account->balance = 0.0;
    account->type = type;
    account->interestRate = interestRate;
}

void deposit(Account *account, double amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Deposited %.2f to account %d\n", amount, account->accountNumber);
    } else {
        printf("Invalid deposit amount\n");
    }
}

void withdraw(Account *account, double amount) {
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrew %.2f from account %d\n", amount, account->accountNumber);
    } else {
        printf("Invalid withdrawal amount\n");
    }
}

void checkBalance(const Account *account) {
    printf("Account %d balance: %.2f\n", account->accountNumber, account->balance);
}

void calculateInterest(Account *account) {
    double interest = account->balance * (account->interestRate / 100);
    account->balance += interest;
    printf("Interest calculated for account %d: %.2f\n", account->accountNumber, interest);
}
