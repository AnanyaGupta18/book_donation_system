#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store donor details
typedef struct {
    char name[50];
    char author[50];
    char title[100];
    char phone[15];
    char address[100];
    char email[50];
} Donor;

// Define a structure to store receiver details
typedef struct {
    char name[50];
    char author[50];
    char title[100];
    char phone[15];
    char address[100];
    char email[50];
} Receiver;

// Function to add record of a donor
void addDonor() {
    FILE *fp;
    Donor donor;
    fp = fopen("donors.txt", "a");
    if (fp == NULL) {
        printf("Error in opening file\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", donor.name);
    printf("Enter book author: ");
    scanf("%s",donor.author);
    printf("Enter book title: ");
    scanf("%s",donor.title);
    printf("Enter phone: ");
    scanf("%s", donor.phone);
    printf("Enter address: ");
    scanf("%s", donor.address);
    printf("Enter email: ");
    scanf("%s", donor.email);
    fprintf(fp, "%s %s %s %s %s %s\n", donor.name, donor.author, donor.title, donor.phone, donor.address, donor.email);
    fclose(fp);
    printf("Record added successfully\n");
}

// Function to add record of a receiver
void addReceiver() {
    FILE *fp ,*fq;
    Receiver receiver;
    Donor donor;
    fp = fopen("receivers.txt", "a");
    fq = fopen("donors.txt","r");
    int found=0;
    if (fp == NULL) {
        printf("Error in opening file\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", receiver.name);
    printf("Enter book author: ");
    scanf("%s",receiver.author);
    printf("Enter book title: ");
    scanf("%s",receiver.title);
    printf("Enter phone: ");
    scanf("%s", receiver.phone);
    printf("Enter address: ");
    scanf("%s", receiver.address);
    printf("Enter email: ");
    scanf("%s", receiver.email);
    while (fscanf(fq, "%s %s %s %s %s %s\n", donor.name, donor.author, donor.title, donor.phone, donor.address, donor.email) != EOF){
        if(strcmp(donor.title,receiver.title)==0){
            found=1;
            fprintf(fp, "%s %s %s %s %s %s\n", receiver.name, receiver.author, receiver.title, receiver.phone, receiver.address, receiver.email);
            }
    }
    fclose(fp);
    fclose(fq);
    if(found==1){
    printf("Record added successfully\n");}
    else{
        printf("Book not available. Please try again later");
    }
}

// Function to delete record of a donor
void deleteDonor() {
    FILE *fp, *temp;
    Donor donor;
    char name[50];
    int found = 0;
    printf("Enter name of donor to delete: ");
    scanf("%s", name);
    fp = fopen("donors.txt", "r");
    if (fp == NULL) {
        printf("Error in opening file\n");
        return;
    }
    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error in opening file\n");
        return;
    }
    while (fscanf(fp, "%s %s %s %s %s %s\n", donor.name, donor.author, donor.title, donor.phone, donor.address, donor.email) != EOF) {
        if (strcmp(donor.name, name) != 0) {
            fprintf(temp, "%s %s %s %s %s %s\n", donor.name, donor.author, donor.title, donor.phone, donor.address, donor.email);
} else {
found = 1;
}
}
fclose(fp);
fclose(temp);
remove("donors.txt");+
rename("temp.txt", "donors.txt");
if (found == 1) {
printf("Record deleted successfully\n");
} else {
printf("Record not found\n");
}
}
void deleteReceiver() {
FILE *fp, *temp;
Receiver receiver;
char name[50];
int found = 0;
printf("Enter name of receiver to delete: ");
scanf("%s", name);
fp = fopen("receivers.txt", "r");
if (fp == NULL) {
printf("Error in opening file\n");
return;
}
temp = fopen("temp.txt", "w");
if (temp == NULL) {
printf("Error in opening file\n");
return;
}
while (fscanf(fp, "%s %s %s %s %s %s\n", receiver.name, receiver.author, receiver.title, receiver.phone, receiver.address, receiver.email) != EOF) {
if (strcmp(receiver.name, name) != 0) {
fprintf(temp, "%s %s %s %s %s %s\n", receiver.name, receiver.author, receiver.title, receiver.phone, receiver.address, receiver.email);
} else {
found = 1;
}
}
fclose(fp);
fclose(temp);
remove("receivers.txt");
rename("temp.txt", "receivers.txt");
if (found == 1) {
printf("Record deleted successfully\n");
} else {
printf("Record not found\n");
}
}
void updateDonor() {
FILE *fp, *temp;
Donor donor;
char name[50];
int found = 0;
printf("Enter name of donor to update: ");
scanf("%s", name);
fp = fopen("donors.txt", "r");
if (fp == NULL) {
printf("Error in opening file\n");
return;
}
temp = fopen("temp.txt", "w");
if (temp == NULL) {
printf("Error in opening file\n");
return;
}
while (fscanf(fp, "%s %s %s %s %s %s\n", donor.name, donor.author, donor.title, donor.phone, donor.address, donor.email) != EOF) {
if (strcmp(donor.name, name) == 0) {
found = 1;
printf("Enter new name: ");
scanf("%s", donor.name);
printf("Enter new phone: ");
scanf("%s", donor.phone);
printf("Enter new address: ");
scanf("%s", donor.address);
printf("Enter new email: ");
scanf("%s", donor.email);
fprintf(temp, "%s %s %s %s %s %s\n", donor.name, donor.author, donor.title, donor.phone, donor.address, donor.email);
} else {
fprintf(temp, "%s %s %s %s %s %s\n", donor.name, donor.author, donor.title, donor.phone, donor.address, donor.email);
}
}
fclose(fp);
fclose(temp);
remove("donors.txt");
rename("temp.txt", "donors.txt");
if (found == 1) {
    printf("Record updated successfully\n");
} else {
    printf("Record not found\n");
}
}
void updateReceiver() {
FILE *fp, *temp;
Receiver receiver;
char name[50];
int found = 0;
printf("Enter name of receiver to update: ");
scanf("%s", name);
fp = fopen("receivers.txt", "r");
if (fp == NULL) {
printf("Error in opening file\n");
return;
}
temp = fopen("temp.txt", "w");
if (temp == NULL) {
printf("Error in opening file\n");
return;
}
while (fscanf(fp, "%s %s %s %s %s %s\n", receiver.name, receiver.author, receiver.title, receiver.phone, receiver.address, receiver.email) != EOF) {
if (strcmp(receiver.name, name) == 0) {
found = 1;
printf("Enter new name: ");
scanf("%s", receiver.name);
printf("Enter new phone: ");
scanf("%s", receiver.phone);
printf("Enter new address: ");
scanf("%s", receiver.address);
printf("Enter new email: ");
scanf("%s", receiver.email);
fprintf(temp, "%s %d %s %s %s %s\n", receiver.name, receiver.author, receiver.title, receiver.phone, receiver.address, receiver.email);
} else {
fprintf(temp, "%s %d %s %s %s %s\n", receiver.name, receiver.author, receiver.title, receiver.phone, receiver.address, receiver.email);
}
}
fclose(fp);
fclose(temp);
remove("receivers.txt");
rename("temp.txt", "receivers.txt");
if (found == 1) {
printf("Record updated successfully\n");
} else {
printf("Record not found\n");
}
}
void searchDonor() {
FILE *fp;
Donor donor;
char booktitle[50];
int found = 0;
printf("Enter name of book to search: ");
scanf("%s", booktitle);
fp = fopen("donors.txt", "r");
if (fp == NULL) {
printf("Error in opening file\n");
return;
}
while (fscanf(fp, "%s %s %s %s %s %s\n", donor.name, donor.author, donor.title, donor.phone, donor.address, donor.email) != EOF) {
    if (strcmp(donor.title, booktitle) == 0) {
found = 1;
printf("Name: %s\nBook Author: %s\nBook Title: %s\nPhone: %s\nAddress: %s\nEmail: %s\n", donor.name, donor.author, donor.title, donor.phone, donor.address, donor.email);
break;
}
}
fclose(fp);
if (found == 0) {
printf("Record not found\n");
}
}
void searchReceiver() {
FILE *fp;
Receiver receiver;
char booktitle2[50];
int found = 0;
printf("Enter name of book to search: ");
scanf("%s",booktitle2 );
fp = fopen("receivers.txt", "r");
if (fp == NULL) {
    printf("Error in opening file\n");
    return;
}
while (fscanf(fp, "%s %s %s %s %s %s\n", receiver.name, receiver.author, receiver.title, receiver.phone, receiver.address, receiver.email) != EOF) {
    if (strcmp(receiver.title, booktitle2) == 0) {
        found = 1;
        printf("Name: %s\nBook Author: %s\nBook Title: %s\nPhone: %s\nAddress: %s\nEmail: %s\n", receiver.name, receiver.author, receiver.title, receiver.phone, receiver.address, receiver.email);
        break;
    }
}
fclose(fp);
if (found == 0) {
    printf("Record not found\n");
}
} 
void displayDonors() {
FILE *fp;
Donor donor;
fp = fopen("donors.txt", "r");
if (fp == NULL) {
printf("Error in opening file\n");
return;
}
while (fscanf(fp, "%s %s %s %s %s %s\n", donor.name, donor.author, donor.title, donor.phone, donor.address, donor.email) != EOF) {
printf("Name: %s\nBook Author: %s\nBook Title: %s\nPhone: %s\nAddress: %s\nEmail: %s\n\n", donor.name, donor.author, donor.title, donor.phone, donor.address, donor.email);
}
fclose(fp);
}
void displayReceivers() {
FILE *fp;
Receiver receiver;
fp = fopen("receivers.txt", "r");
if (fp == NULL) {
printf("Error in opening file\n");
return;
}
while (fscanf(fp, "%s %s %s %s %s %s\n", receiver.name, receiver.author, receiver.title, receiver.phone, receiver.address, receiver.email) != EOF) {
printf("Name: %s\nBook Author: %s\nBook Title %s\nPhone: %s\nAddress: %s\nEmail: %s\n\n", receiver.name, receiver.author, receiver.title, receiver.phone, receiver.address, receiver.email);
}
fclose(fp);
}
int main() {
int choice;
do {
printf("\n");
printf("1. Add record of donor\n");
printf("2. Add record of receiver\n");
printf("3. Delete record of donor\n");
printf("4. Delete record of receiver\n");
printf("5. Update record of donor\n");
printf("6. Update record of receiver\n");
printf("7. Search record of donor\n");
printf("8. Search record of receiver\n");
printf("9. Display all records of donors\n");
printf("10. Display all records of receivers\n");
printf("11. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
addDonor();
break;
case 2:
addReceiver();
break;
case 3:
deleteDonor();
break;
case 4:
deleteReceiver();
break;
case 5:
updateDonor();
break;
case 6:
updateReceiver();
break;
case 7:
searchDonor();
break;
case 8:
searchReceiver();
break;
case 9:
displayDonors();
break;
case 10:
displayReceivers();
break;
case 11:
printf("Exiting program...\n");
break;
default:
printf("Invalid choice\n");
}
} while (choice != 11);
return 0;
}
