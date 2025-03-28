/*
a competitive gaming leaderboard where:

Players register (insert into BST).
Scores are updated dynamically.
The top 3 players can be quickly retrieved.
A player can be removed if they quit the game.
Efficient search operations allow finding any player's rank.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
WHY FEATURE:
- A BST is used to maintain a sorted leaderboard based on player scores.
- Searching, inserting, and deleting players are efficient (O(log n) on average).
- Allows quick ranking updates without needing to re-sort after every insertion.
*/

typedef struct Player {
    char name[50];
    int score;
    struct Player *left, *right;
} Player;

// Function to create a new player node
Player* createPlayer(char *name, int score) {
    Player *newPlayer = (Player*)malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->score = score;
    newPlayer->left = newPlayer->right = NULL;
    return newPlayer;
}

// Insert player into BST based on score
Player* insertPlayer(Player *root, char *name, int score) {
    if (!root) return createPlayer(name, score);
    if (score > root->score) root->right = insertPlayer(root->right, name, score);
    else root->left = insertPlayer(root->left, name, score);
    return root;
}

// In-order traversal to display leaderboard (sorted order)
void displayLeaderboard(Player *root) {
    if (!root) return;
    displayLeaderboard(root->right);
    printf("%s - %d\n", root->name, root->score);
    displayLeaderboard(root->left);
}

// Search for a player in BST
Player* searchPlayer(Player *root, char *name) {
    if (!root || strcmp(root->name, name) == 0) return root;
    if (strcmp(name, root->name) > 0) return searchPlayer(root->right, name);
    return searchPlayer(root->left, name);
}

// Find the minimum value node (used in deletion)
Player* minValueNode(Player *node) {
    while (node && node->left) node = node->left;
    return node;
}

// Delete a player from BST
Player* deletePlayer(Player *root, char *name) {
    if (!root) return NULL;
    if (strcmp(name, root->name) > 0) root->right = deletePlayer(root->right, name);
    else if (strcmp(name, root->name) < 0) root->left = deletePlayer(root->left, name);
    else {
        if (!root->left) {
            Player *temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            Player *temp = root->left;
            free(root);
            return temp;
        }
        Player *temp = minValueNode(root->right);
        strcpy(root->name, temp->name);
        root->score = temp->score;
        root->right = deletePlayer(root->right, temp->name);
    }
    return root;
}

// Main function
int main() {
    Player *leaderboard = NULL;
    int choice, score;
    char name[50];

    while (1) {
        printf("\n1. Add Player  2. Display Leaderboard  3. Search Player  4. Remove Player  5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter player name: ");
                scanf("%s", name);
                printf("Enter score: ");
                scanf("%d", &score);
                leaderboard = insertPlayer(leaderboard, name, score);
                break;
            case 2:
                printf("\nFortnite Leaderboard:\n");
                displayLeaderboard(leaderboard);
                break;
            case 3:
                printf("Enter player name to search: ");
                scanf("%s", name);
                if (searchPlayer(leaderboard, name)) printf("Player found: %s\n", name);
                else printf("Player not found!\n");
                break;
            case 4:
                printf("Enter player name to remove: ");
                scanf("%s", name);
                leaderboard = deletePlayer(leaderboard, name);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
