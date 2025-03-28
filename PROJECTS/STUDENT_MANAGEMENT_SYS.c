#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float marks;
    struct Student* next;
};

struct Student* createStudent(int id, char* name, float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}

void insertStudent(struct Student** head, int id, char* name, float marks) {
    struct Student* newStudent = createStudent(id, name, marks);
    if (!*head) {
        *head = newStudent;
        return;
    }
    struct Student* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newStudent;
}

void displayStudents(struct Student* head) {
    if (!head) {
        printf("No students found!\n");
        return;
    }
    printf("\nStudent List:\n");
    while (head) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", head->id, head->name, head->marks);
        head = head->next;
    }
}

void searchStudent(struct Student* head, int id) {
    while (head) {
        if (head->id == id) {
            printf("Student Found: ID: %d, Name: %s, Marks: %.2f\n", head->id, head->name, head->marks);
            return;
        }
        head = head->next;
    }
    printf("Student with ID %d not found!\n", id);
}

void deleteStudent(struct Student** head, int id) {
    struct Student *temp = *head, *prev = NULL;
    if (temp && temp->id == id) {
        *head = temp->next;
        free(temp);
        printf("Student with ID %d deleted successfully.\n", id);
        return;
    }
    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Student with ID %d not found!\n", id);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Student with ID %d deleted successfully.\n", id);
}

void updateStudent(struct Student* head, int id, float newMarks) {
    while (head) {
        if (head->id == id) {
            head->marks = newMarks;
            printf("Marks updated for student ID %d.\n", id);
            return;
        }
        head = head->next;
    }
    printf("Student with ID %d not found!\n", id);
}

void sortStudents(struct Student** head) {
    if (!*head) return;
    struct Student *i, *j;
    int swapped;
    do {
        swapped = 0;
        i = *head;
        while (i->next) {
            if (i->marks < i->next->marks) {
                float tempMarks = i->marks;
                i->marks = i->next->marks;
                i->next->marks = tempMarks;

                int tempID = i->id;
                i->id = i->next->id;
                i->next->id = tempID;

                char tempName[50];
                strcpy(tempName, i->name);
                strcpy(i->name, i->next->name);
                strcpy(i->next->name, tempName);

                swapped = 1;
            }
            i = i->next;
        }
    } while (swapped);
}

int main() {
    struct Student* head = NULL;
    int choice, id;
    char name[50];
    float marks;

    while (1) {
	printf("\n1. Add\n");
	printf("2. Display\n"); printf("3. Search\n");
	printf("4. Delete\n"); printf("5. Update\n"); printf("6. Sort\n");
	printf("7. Exit\n");
	printf("Choice: ");

        scanf("%d", &choice);

        if (choice == 1) { printf("Enter ID, Name, and Marks: "); scanf("%d %s %f", &id, name, &marks); insertStudent(&head, id, name, marks); }
        else if (choice == 2) {displayStudents(head); }
        else if (choice == 3) {printf("Enter ID to search: "); scanf("%d", &id); searchStudent(head, id); }
        else if (choice == 4) {printf("Enter ID to delete: "); scanf("%d", &id); deleteStudent(&head, id); }
        else if (choice == 5) {printf("Enter ID and new Marks: "); scanf("%d %f", &id, &marks); updateStudent(head, id, marks); }
        else if (choice == 6) {sortStudents(&head); printf("Students sorted by marks.\n");}
        else if (choice == 7) {printf("Exiting...\n"); return 0;}
        else printf("Invalid choice! Try again.\n");
    }
}
