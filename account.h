#ifndef ACCOUNT_H
#define ACCOUNT_H

// Structure for Account
struct Account
{
    int accountNumber;
    char name[50];
    char mobile[15];
    int pin;
    float balance;
};

// Function Prototypes
void createAccount();
void login();
void dashboard(struct Account *user);
void checkBalance(struct Account *user);
void deposit(struct Account *user);
void withdraw(struct Account *user);

#endif