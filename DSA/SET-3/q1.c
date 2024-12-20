#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* createBinaryTree() {
    int data;
    printf("Enter the root value (-1 for NULL): ");
    scanf("%d", &data);

    if (data == -1) return NULL;

    Node* root = createNode(data);
    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];

        printf("Enter left child of %d (-1 for NULL): ", current->data);
        scanf("%d", &data);
        if (data != -1) {
            current->left = createNode(data);
            queue[rear++] = current->left;
        }

        printf("Enter right child of %d (-1 for NULL): ", current->data);
        scanf("%d", &data);
        if (data != -1) {
            current->right = createNode(data);
            queue[rear++] = current->right;
        }
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


void postorderTraversal(Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    int choice;

    do {
        printf("\n\n---- Binary Tree Menu ----\n");
        printf("1. Create Binary Tree\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (root != NULL) {
                    printf("Tree already exists! Freeing the existing tree...\n");
                    freeTree(root);
                }
                root = createBinaryTree();
                printf("Binary tree created successfully.\n");
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("In-order traversal: ");
                    inorderTraversal(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Pre-order traversal: ");
                    preorderTraversal(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Post-order traversal: ");
                    postorderTraversal(root);
                    printf("\n");
                }
                break;
            case 5:
                printf("Exiting the program...\n");
                if (root != NULL) {
                    freeTree(root);
                }
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
