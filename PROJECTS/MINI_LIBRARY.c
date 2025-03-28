#include <stdio.h>
#include <string.h>

#define MAX_B 20  
#define MAX_L 50  

char books[MAX_B][MAX_L] = {
    "C Programming", "Data Structures", "Algorithms", "Operating Systems", "Computer Networks",
    "Database Systems", "Artificial Intelligence", "Machine Learning", "Software Engineering", "Cyber Security",
    "Web Development", "Embedded Systems", "Cryptography", "Digital Logic Design", "Quantum Computing",
    "Mobile App Development", "Computer Graphics", "Game Development", "Cloud Computing", "Internet of Things"
};

void searchB() {
    char q[MAX_L];
    printf("Enter book name to search: ");
    scanf(" %[^\n]", q);  

    for (int i = 0; i < MAX_B; i++) {
        if (strcmp(books[i], q) == 0) {
            printf("Book found: %s\n", books[i]);
            return;
        }
    }
    printf("Book not found!\n");
}

void showB() {
    printf("\n=== Available Books ===\n");
    for (int i = 0; i < MAX_B; i++) {
        printf("%d. %s\n", i + 1, books[i]);
    }
}

void menu() {
    printf("\n=== LIBRARY MENU ===\n");
    printf("1. Show Books\n2. Search Book\n3. Exit\nChoice: ");
}

int main() {
    int ch;
    while (1) {
        menu();
        scanf("%d", &ch);
        switch (ch) {
            case 1: showB(); break;
            case 2: searchB(); break;
            case 3: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
