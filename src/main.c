#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char name[50];
    char author[50];
    int issued; 
};

struct Book library[MAX];
int count = 0;  


void addBook() {
    printf("\nEnter Book ID: ");
    scanf("%d", &library[count].id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]s", library[count].name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]s", library[count].author);

    library[count].issued = 0;
    count++;

    printf("\nBook Added Successfully\n");
}

void displayBooks() {
    if (count == 0) {
        printf("\nNo Books Available\n");
        return;
    }

    printf("\n--- List of Books ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nBook ID: %d", library[i].id);
        printf("\nName: %s", library[i].name);
        printf("\nAuthor: %s", library[i].author);
        printf("\nStatus: %s\n", library[i].issued ? "Issued" : "Available");
    }
}

void searchBook() {
    int choice, id;
    char name[50];

    printf("\nSearch By:\n1. Book ID\n2. Book Name\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nEnter Book ID: ");
        scanf("%d", &id);

        for (int i = 0; i < count; i++) {
            if (library[i].id == id) {
                printf("\nBook Found");
                printf("\nName: %s", library[i].name);
                printf("\nAuthor: %s", library[i].author);
                printf("\nStatus: %s\n", library[i].issued ? "Issued" : "Available");
                return;
            }
        }
        printf("\nBook Not Found\n");
    }

    else if (choice == 2) {
        printf("\nEnter Book Name: ");
        scanf(" %[^\n]s", name);

        for (int i = 0; i < count; i++) {
            if (strcmp(library[i].name, name) == 0) {
                printf("\nBook Found");
                printf("\nBook ID: %d", library[i].id);
                printf("\nAuthor: %s", library[i].author);
                printf("\nStatus: %s\n", library[i].issued ? "Issued" : "Available");
                return;
            }
        }
        printf("\nBook Not Found\n");
    }
    else {
        printf("\nInvalid Choice\n");
    }
}

void issueBook() {
    int id;
    printf("\nEnter Book ID to Issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            if (library[i].issued == 0) {
                library[i].issued = 1;
                printf("\nBook Issued Successfully\n");
            } else {
                printf("\nBook Already Issued\n");
            }
            return;
        }
    }
    printf("\nInvalid Book ID\n");
}

void returnBook() {
    int id;
    printf("\nEnter Book ID to Return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            if (library[i].issued == 1) {
                library[i].issued = 0;
                printf("\nBook Returned Successfully\n");
            } else {
                printf("\nThis Book Was Not Issued\n");
            }
            return;
        }
    }
    printf("\nInvalid Book ID\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n----- Library Management System -----\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: printf("\nThank You\n"); return 0;
            default: printf("\nInvalid Choice! Try Again\n");
        }
    }
}