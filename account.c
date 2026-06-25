#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"

void createAccount()
{
    struct Account user;

    FILE *fp = fopen("accounts.dat", "ab");

    if(fp == NULL)
    {
        printf("\nError opening file!\n");
        return;
    }

    printf("\n========== CREATE ACCOUNT ==========\n");

    printf("Enter Account Number : ");
    scanf("%d",&user.accountNumber);

    printf("Enter Name : ");
    scanf(" %[^\n]",user.name);

    printf("Enter Mobile Number : ");
    scanf("%s",user.mobile);

    printf("Create 4 Digit PIN : ");
    scanf("%d",&user.pin);

    printf("Enter Initial Balance : ");
    scanf("%f",&user.balance);

    fwrite(&user,sizeof(struct Account),1,fp);

    fclose(fp);

    printf("\nAccount Created Successfully!\n");
}

void login()
{
    int accNo;
    int pin;

    struct Account user;

    FILE *fp=fopen("accounts.dat","rb");

    if(fp==NULL)
    {
        printf("\nNo Accounts Found!\n");
        return;
    }

    printf("\n========== LOGIN ==========\n");

    printf("Enter Account Number : ");
    scanf("%d",&accNo);

    printf("Enter PIN : ");
    scanf("%d",&pin);

    while(fread(&user,sizeof(struct Account),1,fp))
    {
        if(user.accountNumber==accNo && user.pin==pin)
        {
            fclose(fp);

            printf("\nLogin Successful!\n");

            dashboard(&user);

            return;
        }
    }

    fclose(fp);

    printf("\nInvalid Account Number or PIN!\n");
}

void dashboard(struct Account *user)
{
    int choice;

    do
    {
        printf("\n=================================\n");
        printf("Welcome %s\n", user->name);
        printf("=================================\n");

        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Logout\n");

        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                checkBalance(user);
                break;

            case 2:
                deposit(user);
                break;

            case 3:
                withdraw(user);
                break;

            case 4:
                printf("\nLogged Out Successfully.\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    }while(choice!=4);
}
void checkBalance(struct Account *user)
{
    printf("\n===== ACCOUNT BALANCE =====\n");
    printf("Current Balance : %.2f\n", user->balance);
}

void deposit(struct Account *user)
{
    float amount;

    printf("\nEnter Amount to Deposit : ");
    scanf("%f", &amount);

    if(amount <= 0)
    {
        printf("\nInvalid Amount!\n");
        return;
    }

    user->balance += amount;

    printf("\n₹%.2f Deposited Successfully!\n", amount);
    printf("Current Balance : %.2f\n", user->balance);
}

void withdraw(struct Account *user)
{
    float amount;

    printf("\nEnter Amount to Withdraw : ");
    scanf("%f", &amount);

    if(amount <= 0)
    {
        printf("\nInvalid Amount!\n");
        return;
    }

    if(amount > user->balance)
    {
        printf("\nInsufficient Balance!\n");
        return;
    }

    user->balance -= amount;

    printf("\n₹%.2f Withdrawn Successfully!\n", amount);
    printf("Current Balance : %.2f\n", user->balance);
}