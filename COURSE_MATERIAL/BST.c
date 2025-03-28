#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* create(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int val) {
    if (!root) return create(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

Node* minValueNode(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

Node* delete(Node* root, int val) {
    if (!root) return root;
    if (val < root->data) root->left = delete(root->left, val);
    else if (val > root->data) root->right = delete(root->right, val);
    else {
        if (!root->left) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = NULL;
    int choice, val;

    while (1) {
        printf("\n1. Insert  2. Inorder Display  3. Delete  4. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            root = insert(root, val);
        } 
        else if (choice == 2) {
            printf("BST Inorder: ");
            inorder(root);
            printf("\n");
        } 
        else if (choice == 3) {
            printf("Enter value to delete: ");
            scanf("%d", &val);
            root = delete(root, val);
        } 
        else if (choice == 4) break;
        else printf("Invalid choice, try again!\n");
    }
    return 0;
}
