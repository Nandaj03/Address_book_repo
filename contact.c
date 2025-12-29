#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria
    
    if(sortCriteria==1)
        sort_contacts_name(addressBook);
    else if(sortCriteria==2)
        sort_contact_phone(addressBook);
    else if(sortCriteria==3)
        sort_contact_email(addressBook);

    printf("--------------------------------------------------------------------------\n");
    printf("%-20s %-20s %-30s\n", "Name", "Phone", "Email");
    printf("--------------------------------------------------------------------------\n");
    for(int i=0;i<addressBook->contactCount;i++){
        printf("%-20s %-20s %-30s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    printf("--------------------------------------------------------------------------\n");
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    int sortChoice;
    char name[20],phone[20],email[20];
    printf("-----------------------------\n");
    printf("%20s\n","CREATE MENU");
    printf("-----------------------------\n");
    printf("Enter the name:");
    scanf(" %[^\n]",name);
    is_valid_name(addressBook,name);                //validate name
    strcpy(addressBook->contacts[addressBook->contactCount].name,name);

    printf("Enter the phone:");
    scanf(" %[^\n]",phone);
    is_valid_phone(addressBook,phone);              //validate phone
    strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);

    printf("Enter the email:");
    scanf(" %[^\n]",email);
    is_valid_email(addressBook,email);              //validate email
    strcpy(addressBook->contacts[addressBook->contactCount].email,email);
    addressBook->contactCount++;
    printf("\n✅ SUCCESSFULLY EDITED\n");
    listContacts(addressBook,sortChoice);
    
}
//function for searching contact
int searchContact(AddressBook *addressBook,int *arr) 
{
    /* Define the logic for search */
    int choice;
    printf("\n-----------------------------\n");
    printf("%20s\n","SEARCH MENU");
    printf("-----------------------------\n");
    printf("Search by :\n");
    printf("1.name\n2.phone\n3.email\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        char str[20];
        int flag1=0,count1=1;
        printf("enter the name:");
        scanf(" %[^\n]",str);
        printf("------------------------------------------------------------------------------\n");
        printf("%-5s %-20s %-15s %-30s\n", "S.No", "Name", "Phone", "Email");        
        printf("------------------------------------------------------------------------------\n");
        for(int i=0;i<addressBook->contactCount;i++){
            
            if(strcasestr(addressBook->contacts[i].name,str) != NULL){
                printf("%-5d %-20s %-15s %-30s\n",count1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                flag1++;
                arr[count1]=i;
                count1++;
            }
        }
        if(flag1==1){
            printf("-----------------------------------------------------------------------------------\n");
            return flag1;
        }
        if(flag1==0){
            printf("No contact found\n");
            printf("-----------------------------------------------------------------------------------\n");
            return flag1;

        }
            printf("-----------------------------------------------------------------------------------\n");
        break;
    case 2:
        char str1[20];
        int flag2=0,count2=1;
        printf("enter the number:");
        scanf(" %[^\n]",str1);
        printf("------------------------------------------------------------------------------\n");
        for(int i=0;i<addressBook->contactCount;i++){
            int flag=strcmp(addressBook->contacts[i].phone,str1);
            if(flag  ==  0){
                printf("%-5d %-20s %-15s %-30s\n",count2,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                flag2++;
                arr[count2]=i;
                count2++;
        }
    }
    if(flag2==1){
        printf("------------------------------------------------------------------------------\n");
        return flag2;
    }

    if(flag2==0){
        printf("No contact found\n");
        printf("------------------------------------------------------------------------------\n");
        return flag2;
        }
        printf("------------------------------------------------------------------------------\n");
    break;

      case 3:
        char str2[20];
        int flag3=0,count3=0;
        printf("enter the email:");
        scanf(" %[^\n]",str2);
        printf("------------------------------------------------------------------------------\n");
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(addressBook->contacts[i].email,str2)  ==  0){
                printf("%-5d %-20s %-15s %-30s\n",count3,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                flag3++;
                arr[count3]=i;
                count3++;
        }
    }
    if(flag3==1)
    {
        printf("------------------------------------------------------------------------------\n");
        return flag3;
    }

        if(flag3==0){
        printf("No contact found\n");
        printf("------------------------------------------------------------------------------\n");
        return flag3;
        }
        printf("------------------------------------------------------------------------------\n");

    break;
    
    default:
        printf("❌ Invalid Output\n");
        break;
    }


}

//To edit a contact
void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int sortChoice,arr[MAX_CONTACTS]={0};
    printf("Edit the contact through ");
    int flag=searchContact(addressBook,arr);
    if(flag==0)
        return;
    int index_value,choice_contact;
    if(flag==1){
        index_value=1;
    }
    else{
    printf("enter the index of the contact to edit:");
    scanf("%d",&index_value);
    if(arr[index_value]==0){
        printf("❌ Invalid choice\n");
        return;
    }
    }
    choice_contact=arr[index_value];
    int choice;
    printf("Edit:\n1.name\n2.phone\n3.email\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        char new_name[20];
        printf("To->");
        scanf(" %[^\n]",new_name);
        is_valid_name(addressBook,new_name);
        strcpy(addressBook->contacts[choice_contact].name,new_name);
        listContacts(addressBook, sortChoice);
        printf("✅ SUCCESSFULLY EDITED\n");
        break;
    case 2:
        char new_phone[20];
        printf("To->");
        scanf(" %[^\n]",new_phone);
        is_valid_phone(addressBook,new_phone);
        strcpy(addressBook->contacts[choice_contact].phone,new_phone);
        listContacts(addressBook, sortChoice);
        printf("✅ SUCCESSFULLY EDITED\n");
        break;
    
    case 3:
        char new_email[20];
        printf("To->");
        scanf(" %[^\n]",new_email);
        is_valid_email(addressBook,new_email);
        strcpy(addressBook->contacts[choice_contact].email,new_email);
        listContacts(addressBook, sortChoice);
        printf("✅ SUCCESSFULLY EDITED\n");
        break;
    default:
        printf("❌ Invalid Output\n");
    }  
}

//To delete a contact
void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int sortChoice,choice,arr[MAX_CONTACTS];
    int flag=searchContact(addressBook,arr);
    if(flag==0)
        return;
    int index_value,choice_contact;
    if(flag==1){
        index_value=1;
    }
    else{
    printf("enter the index of the contact to delete:");
    scanf("%d",&index_value);
    if(arr[index_value]==0){
        printf("❌ Invalid choice\n");
        return;
    }
    }
    choice_contact=arr[index_value];
    char ch;
    printf("Do you want to delete:Y|y\n");
    scanf(" %c",&ch);
    if(ch=='Y'|| ch=='y')
    {
       for(int i=choice_contact;i<addressBook->contactCount-1;i++){
        addressBook->contacts[i]=addressBook->contacts[i+1];
       } 
       addressBook->contactCount=addressBook->contactCount-1;
    listContacts(addressBook,  sortChoice);
    printf("SUCCESSFULLY DELETED\n");
    return;
    }
    else{
        printf("❌ Invalid input. Contact not deleted.\n");
        return;
    }
}

//validate name function
void is_valid_name(AddressBook *addressBook,char *str){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='!' && str[i]<='?')
        {
            printf("❌ Invalid input\n");
            printf("Enter the name:");
            char str1[100];
            scanf(" %[^\n]",str1);
            is_valid_name(addressBook,str1);
            strcpy(str,str1);
        }
    }
}


//validate phone function
void is_valid_phone(AddressBook *addressBook,char *str){
    for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(addressBook->contacts[i].phone,str)==0){
            printf("The phone is already there,Enter another phone number:");
            char str1[20];
            scanf(" %[^\n]",str1);
            is_valid_phone(addressBook,str1);
            strcpy(str,str1);
        }

    }
    for(int i=0;str[i]!='\0';i++){
         if(!(str[i]>='0' && str[i]<='9')){
            printf("❌ Invalid phone number:\n");
            printf("Enter the number:");
            char str1[20];
            scanf(" %[^\n]",str1);
            is_valid_phone(addressBook,str1);
            strcpy(str,str1);
        }
    }
    if(strlen(str)!=10){
        printf("❌ Invalid phone number:\n");
        printf("Enter the number:");
        char str1[20];
        scanf(" %[^\n]",str1);
        is_valid_phone(addressBook,str1);
        strcpy(str,str1);
    }
}


//validate email function
void is_valid_email(AddressBook *addressBook,char *str){
    int count1=0,count2=0;
 for(int i=0;i<addressBook->contactCount;i++){
        if(strstr(addressBook->contacts[i].email,str)!=NULL){
            printf("The email is already there,Enter another email:");
            char str1[100];
            scanf(" %[^\n]",str1);
            is_valid_email(addressBook,str1);
            strcpy(str,str1);
        }

    }
    for(int i=0;str[i]!='\0';i++){
         if(!((str[i]>='a' && str[i]<='z') ||  (str[i]>='A' && str[i]<='Z') || str[i]=='@' || str[i]=='.')){
            printf("❌ Invalid email id:\n");
            printf("Enter the email:");
            char str1[100];
            scanf(" %[^\n]",str1);
            is_valid_email(addressBook,str1);
            strcpy(str,str1);
        }
        if(str[i]=='@')
            count1++;
        if(str[i]=='.')
            count2++;
        
    }
    if(!(count1==1 && count2==1))
            {
             printf("❌ Invalid email number:\n");
            printf("Enter the email:");
            char str1[100];
            scanf(" %[^\n]",str1);
            is_valid_email(addressBook,str1);
            strcpy(str,str1);   
            }


}


//sort contact based on name
void sort_contacts_name(AddressBook *addressBook){
    int n=addressBook->contactCount;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(strcasecmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0){
                Contact temp= addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;
            }
        }
    }
}

//sort contact based on phone number
void sort_contact_phone(AddressBook *addressBook){
    int n=addressBook->contactCount;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone)>0){
                Contact temp= addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;
            }
        }
    }
}


//sort contact based on email
void sort_contact_email(AddressBook *addressBook){
    int n=addressBook->contactCount;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email)>0){
                Contact temp= addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;
            }
        }
    }
}
