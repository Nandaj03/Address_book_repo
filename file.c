#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {

FILE *fp;
 if((fp=fopen("contact.csv","w"))==NULL)
 {
    fprintf(stderr,"file can't open\n");            //to check fopen worked properly
    return;
 }

 for(int i=0;i<addressBook->contactCount;i++){
    fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
 }

}

void loadContactsFromFile(AddressBook *addressBook) {
    
    
    FILE *fp;
    if((fp=fopen("contact.csv","r"))==NULL){
        fprintf(stderr,"file not found");           //to check file is found or not
        return;
    }

    while((fscanf(fp,"%[^,],%[^,],%[^\n] ",addressBook->contacts[addressBook->contactCount].name,addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[addressBook->contactCount].email))==3)
    {
        addressBook->contactCount++;
    }
    fclose(fp);
}
