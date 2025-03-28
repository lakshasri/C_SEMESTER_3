#include <stdio.h>
#include <string.h>

#define MAX_T 5  
#define MAX_L 50  

char t[MAX_T][MAX_L];  
int t_count = 0;  

void clrBuf() { while (getchar() != '\n'); }  

void addT() {
    if (t_count < MAX_T) {
        printf("Enter task: ");
        clrBuf();
        fgets(t[t_count], MAX_L, stdin);
        t[t_count][strcspn(t[t_count], "\n")] = 0;  
        t_count++;
        printf("Task added!\n");
    } else {
        printf("Task list full!\n");
    }
}

void rmT() {
    int idx;
    if (t_count == 0) {
        printf("No tasks to remove!\n");
        return;
    }
    printf("Enter task number to remove (1-%d): ", t_count);
    scanf("%d", &idx);
    
    if (idx > 0 && idx <= t_count) {
        for (int i = idx - 1; i < t_count - 1; i++) {
            strcpy(t[i], t[i + 1]);
        }
        t_count--;
        printf("Task removed!\n");
    } else {
        printf("Invalid index!\n");
    }
}

void showT() {
    if (t_count == 0) {
        printf("\nTo-Do List is empty!\n");
        return;
    }
    printf("\nTo-Do List:\n");
    for (int i = 0; i < t_count; i++) {
        printf("%d. %s\n", i + 1, t[i]);
    }
}

void menu() {
    printf("\n=== TO-DO LIST ===\n");
    printf("1. Add Task\n2. Remove Task\n3. Show Tasks\n4. Exit\nChoice: ");
}

int main() {
    int ch;
    while (1) {
        menu();
        scanf("%d", &ch);
        switch (ch) {
            case 1: addT(); break;
            case 2: rmT(); break;
            case 3: showT(); break;
            case 4: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
