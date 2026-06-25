#include <stdio.h>

int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("        ATM SIMULATOR\n");
        printf("====================================\n");

        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nCreate Account Selected.\n");
                break;

            case 2:
                printf("\nLogin Selected.\n");
                break;

            case 3:
                printf("\nThank you for using ATM Simulator!\n");
                break;

            default:
                printf("\nInvalid Choice! Please try again.\n");
        }

    } while(choice != 3);

    return 0;
}