#ifndef ACCOUNT_H
#define ACCOUNT_H

#define NAME_LEN 100

typedef enum {
    SAVINGS,
    CURRENT
} AccountType;

typedef struct {
    int accountNumber;
    char accountHolder[NAME_LEN];
    double balance;
    AccountType type;
    double interestRate;
} Account;

void createAccount(Account *account, int accountNumber, const char *accountHolder, AccountType type, double interestRate);
void deposit(Account *account, double amount);
void withdraw(Account *account, double amount);
void checkBalance(const Account *account);
void calculateInterest(Account *account);

#endif // ACCOUNT_H
