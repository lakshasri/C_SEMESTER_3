#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MinHeap *h, int val) {
    if (h->size >= MAX) return;
    h->arr[h->size] = val;
    int i = h->size++;
    while (i && h->arr[i] < h->arr[(i - 1) / 2]) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(MinHeap *h) {
    if (h->size == 0) return -1;
    int root = h->arr[0];
    h->arr[0] = h->arr[--h->size];

    int i = 0;
    while (2 * i + 1 < h->size) {
        int smallest = 2 * i + 1;
        if (smallest + 1 < h->size && h->arr[smallest + 1] < h->arr[smallest])
            smallest++;
        if (h->arr[i] < h->arr[smallest]) break;
        swap(&h->arr[i], &h->arr[smallest]);
        i = smallest;
    }
    return root;
}

int main() {
    MinHeap h = {0};
    int choice, val;

    while (1) {
        printf("\n1. Insert  2. Extract Min  3. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(&h, val);
        } 
        else if (choice == 2) {
            int min = extractMin(&h);
            if (min != -1) printf("Min Extracted: %d\n", min);
            else printf("Heap is empty!\n");
        } 
        else if (choice == 3) break;
        else printf("Invalid choice, try again!\n");
    }
    return 0;
}
