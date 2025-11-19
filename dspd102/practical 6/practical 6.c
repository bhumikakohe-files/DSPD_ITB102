

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
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

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

struct Node* deleteLeaf(struct Node* root, int key) {
    struct Node* parent = NULL;
    struct Node* current = root;

    while (current != NULL && current->data != key) {
        parent = current;
        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == NULL) {
        printf("Element %d not found in the BST.\n", key);
        return root;
    }

    if (current->left != NULL || current->right != NULL) {
        printf("Element %d is not a leaf node. Cannot delete.\n", key);
        return root;
    }

    printf("Deleting leaf node %d.\n", key);
    
    if (parent == NULL) {
        free(current);
        return NULL;
    }

    if (parent->left == current) {
        parent->left = NULL;
    } else {
        parent->right = NULL;
    }
    
    free(current);
    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


int main() {
    struct Node* root = NULL;
    struct Node* result = NULL;
    int choice, data;

    while (1) {
        printf("\n--- BINARY SEARCH TREE MENU ---\n");
        printf("1. Insert Element\n");
        printf("2. Search Element\n");
        printf("3. Delete Leaf Element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Inserted %d. Current tree (Inorder): ", data);
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &data);
                result = search(root, data);
                if (result != NULL) {
                    printf("Found\n");
                } else {
                    printf("NULL (Not Found)\n");
                }
                break;
            case 3:
                printf("Enter leaf element to delete: ");
                scanf("%d", &data);
                root = deleteLeaf(root, data);
                printf("Current tree (Inorder): ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

