#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);                    //declaration of each function used.
int searchContact(AddressBook *addressBook,int *arr);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
void is_valid_name(AddressBook *addressBook,char *str);
void is_valid_phone(AddressBook *addressBook,char *str);
void is_valid_email(AddressBook *addressBook,char *str);
void sort_contacts_name(AddressBook *addressBook);
void sort_contact_phone(AddressBook *addressBook);
void sort_contact_email(AddressBook *addressBook);


#endif
