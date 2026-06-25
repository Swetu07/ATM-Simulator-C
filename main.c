#include <stdio.h>
#include <stdlib.h>
#include "account.h"

int main()
{
    int choice;

    while (1)
    {
        printf("\n=========================================\n");
        printf("         ATM SIMULATOR SYSTEM\n");
        printf("=========================================\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                login();
                break;

            case 3:
                printf("\nThank you for using ATM Simulator!\n");
                exit(0);

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    }

    return 0;
}