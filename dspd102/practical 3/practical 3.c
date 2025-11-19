
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

char queue_arr[MAX];
int front = -1;
int rear = -1;

void enqueue(char item) {
    if ((rear + 1) % MAX == front) {
        printf("QUEUE OVERFLOW. Cannot insert %c.\n", item);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue_arr[rear] = item;
    printf("Inserted %c into queue.\n", item);
}

void dequeue() {
    char item;
    if (front == -1) {
        printf("QUEUE UNDERFLOW. Cannot delete.\n");
        return;
    }
    item = queue_arr[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("Deleted %c from queue.\n", item);
}

void demonstrateOverflow() {
    int i;
    char c = 'A';
    printf("\n--- Demonstrating Overflow ---\n");
    front = -1;
    rear = -1;
    
    printf("Filling queue (MAX=%d)...\n", MAX);
    for (i = 0; i < MAX; i++) {
        enqueue(c + i);
    }
    
    printf("Queue is now full. Attempting to insert one more...\n");
    enqueue('Z');
    
    front = -1;
    rear = -1;
    printf("Queue reset for normal use.\n");
}

void demonstrateUnderflow() {
    printf("\n--- Demonstrating Underflow ---\n");
    front = -1;
    rear = -1;
    printf("Queue is empty. Attempting to delete...\n");
    dequeue();
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue status (Front to Rear):\n");
    
    if (rear >= front) {
        for (i = front; i <= rear; i++) {
            printf("%c ", queue_arr[i]);
        }
    } else {
        for (i = front; i < MAX; i++) {
            printf("%c ", queue_arr[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%c ", queue_arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice;
    char item;

    while (1) {
        printf("\n--- QUEUE MENU (MAX = %d) ---\n", MAX);
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Demonstrate Overflow and Underflow\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                demonstrateOverflow();
                demonstrateUnderflow();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}


