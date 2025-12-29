/* 
code name:Address book
date:29/12/2025
*/
#include <stdio.h>
#include "contact.h"

int main()
{
    int choice, sortChoice,str[MAX_CONTACTS];
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do
    {
        printf("\n\tAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Save contacts\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();                //to take one character from buffer eg:enter(\n)
        switch (choice)
        {
        case 1:
            createContact(&addressBook);
            break;
        case 2:
            searchContact(&addressBook,str);
            break;
        case 3:
            editContact(&addressBook);
            break;
        case 4:
            deleteContact(&addressBook);
            break;
        case 5:
            printf("Sort by\n1.name\t2.phone\t3.email\n");
            scanf("%d",&sortChoice);
            listContacts(&addressBook, sortChoice);         //list contact function
            break;
        case 6:
            printf("Saving...\n");
            saveContactsToFile(&addressBook);               //save contact function
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("❌ Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
