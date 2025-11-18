//AIM:Implement Binary search tree(BST) with following Menu operations.
//1.	Search an element in BST(Display NULL if not found, If found Display Found)
//2.	Insert an element in BST
//3.	Delete leaf element in BST
//4.	Exit
//ROLL NO 102
#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node *left, *right;
};
 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}
 
void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }
    if (root->data == key) {
        printf("Found\n");
        return;
    }
    if (key < root->data) {
        search(root->left, key);
    } else {
        search(root->right, key);
    }
} 
struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key < root->data) {
        root->left = deleteLeaf(root->left, key);
    } else if (key > root->data) {
        root->right = deleteLeaf(root->right, key);
    } else {
         
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else {
            printf("Node is not a leaf, cannot delete.\n");
        }
    }
    return root;
}
 
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Search an element in BST\n");
        printf("2. Insert an element in BST\n");
        printf("3. Delete a leaf element in BST\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &value);
                search(root, value);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Element inserted.\n");
                break;
            case 3:
                printf("Enter the leaf element to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                printf("Leaf element deleted (if it existed).\n");
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}