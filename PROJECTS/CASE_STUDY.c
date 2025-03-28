#include <stdio.h>
#include <string.h>

#define MAX_CHATS 5
#define MAX_MSGS 5
#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    char msgs[MAX_MSGS][MAX_LEN];
    int msgCount;
    int pinned;
} Chat;

Chat chats[MAX_CHATS];
int chatCount = 0;

void createChat() {
    if (chatCount >= MAX_CHATS) {
        printf("Chat limit reached!\n");
        return;
    }
    printf("Enter chat name: ");
    scanf(" %[^\n]", chats[chatCount].name);
    chats[chatCount].msgCount = 0;
    chats[chatCount].pinned = 0;
    chatCount++;
}

void sendMsg() {
    int i;
    printf("Select chat (1-%d): ", chatCount);
    scanf("%d", &i);
    if (i < 1 || i > chatCount) {
        printf("Invalid chat!\n");
        return;
    }
    if (chats[i - 1].msgCount >= MAX_MSGS) {
        printf("Message limit reached for this chat!\n");
        return;
    }
    printf("Enter message: ");
    scanf(" %[^\n]", chats[i - 1].msgs[chats[i - 1].msgCount]);
    chats[i - 1].msgCount++;
}

void pinChat() {
    int i;
    printf("Select chat to pin/unpin (1-%d): ", chatCount);
    scanf("%d", &i);
    if (i < 1 || i > chatCount) {
        printf("Invalid chat!\n");
        return;
    }
    chats[i - 1].pinned = !chats[i - 1].pinned;
    printf("Chat %s %s.\n", chats[i - 1].name, chats[i - 1].pinned ? "Pinned" : "Unpinned");
}

void deleteChat() {
    int i;
    printf("Select chat to delete (1-%d): ", chatCount);
    scanf("%d", &i);
    if (i < 1 || i > chatCount) {
        printf("Invalid chat!\n");
        return;
    }
    for (int j = i - 1; j < chatCount - 1; j++) {
        chats[j] = chats[j + 1];
    }
    chatCount--;
    printf("Chat deleted.\n");
}

void viewChats() {
    printf("\nChats:\n");
    for (int i = 0; i < chatCount; i++) {
        if (chats[i].pinned) printf("[PINNED] ");
        printf("%d. %s\n", i + 1, chats[i].name);
        for (int j = 0; j < chats[i].msgCount; j++) {
            printf("   - %s\n", chats[i].msgs[j]);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Create Chat  2. Send Message  3. Pin/Unpin  4. Delete  5. View Chats  6. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createChat(); break;
            case 2: sendMsg(); break;
            case 3: pinChat(); break;
            case 4: deleteChat(); break;
            case 5: viewChats(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
