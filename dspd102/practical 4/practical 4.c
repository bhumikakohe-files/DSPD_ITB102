

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* new_node = NULL;
    int data;
    int count = 0;

    printf("Enter elements (enter 0 to stop):\n");

    while (1) {
        printf("Enter element: ");
        scanf("%d", &data);

        if (data == 0) {
            break;
        }

        new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;
        count++;

        if (head == NULL) {
            head = new_node;
            temp = new_node;
        } else {
            temp->next = new_node;
            temp = new_node;
        }
    }

    printf("\nThe linked list is:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Number of nodes in the list: %d\n", count);

    return 0;
}


