#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char name[50];
    char author[50];
    float price;
};

struct Book library[MAX];
int count = 0;

// Function to add a book
void addBook() {
    if (count == MAX) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &library[count].id);

    printf("Enter Book Name: ");
    scanf("%s", library[count].name);

    printf("Enter Author Name: ");
    scanf("%s", library[count].author);

    printf("Enter Price: ");
    scanf("%f", &library[count].price);

    count++;
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n--- Library Books ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("ID: %d\n", library[i].id);
        printf("Name: %s\n", library[i].name);
        printf("Author: %s\n", library[i].author);
        printf("Price: %.2f\n", library[i].price);
    }
}

// Function to search book by ID
void searchByID() {
    int id, found = 0;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            printf("\nBook Found!\n");
            printf("ID: %d\n", library[i].id);
            printf("Name: %s\n", library[i].name);
            printf("Author: %s\n", library[i].author);
            printf("Price: %.2f\n", library[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to search book by Name
void searchByName() {
    char name[50];
    int found = 0;

    printf("Enter Book Name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].name, name) == 0) {
            printf("\nBook Found!\n");
            printf("ID: %d\n", library[i].id);
            printf("Name: %s\n", library[i].name);
            printf("Author: %s\n", library[i].author);
            printf("Price: %.2f\n", library[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Search Book by Name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchByID(); break;
            case 4: searchByName(); break;
            case 5: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
