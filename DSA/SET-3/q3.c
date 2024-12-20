#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
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

// Function to insert a key in the BST
Node* insert(Node* root, int key) {
    if (root == NULL) return createNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    else printf("Duplicate key! Key %d is already present in the BST.\n", key);
    return root;
}

// Function to search for a key in the BST
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

// Function to find the in-order predecessor of a node
Node* findPredecessor(Node* root) {
    Node* current = root->left;
    while (current && current->right != NULL) current = current->right;
    return current;
}

// Function to find the in-order successor of a node
Node* findSuccessor(Node* root) {
    Node* current = root->right;
    while (current && current->left != NULL) current = current->left;
    return current;
}

// Function to delete a key from the BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        Node* successor = findSuccessor(root);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}

// In-order traversal to print the BST
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to free all nodes of the tree (to avoid memory leaks)
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function
int main() {
    Node* root = NULL;
    int choice, key;

    do {
        printf("\n\n---- Binary Search Tree Menu ----\n");
        printf("1. Create Binary Search Tree\n");
        printf("2. Search a key in the BST\n");
        printf("3. Find in-order predecessor and successor of a node\n");
        printf("4. Insert a key into the BST\n");
        printf("5. Delete a key from the BST\n");
        printf("6. Display In-order Traversal of the BST\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (root != NULL) {
                    printf("Tree already exists! Freeing the existing tree...\n");
                    freeTree(root);
                    root = NULL;
                }
                printf("Enter keys to insert into the BST (-1 to stop):\n");
                while (1) {
                    scanf("%d", &key);
                    if (key == -1) break;
                    root = insert(root, key);
                }
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                Node* found = search(root, key);
                if (found) printf("Key %d found in the BST.\n", key);
                else printf("Key %d not found in the BST.\n", key);
                break;
            case 3:
                printf("Enter the key to find its in-order predecessor and successor: ");
                scanf("%d", &key);
                Node* node = search(root, key);
                if (node) {
                    Node* predecessor = findPredecessor(node);
                    Node* successor = findSuccessor(node);
                    if (predecessor) printf("In-order predecessor of %d is %d\n", key, predecessor->data);
                    else printf("No in-order predecessor for %d\n", key);
                    if (successor) printf("In-order successor of %d is %d\n", key, successor->data);
                    else printf("No in-order successor for %d\n", key);
                } else {
                    printf("Key %d not found in the BST.\n", key);
                }
                break;
            case 4:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 5:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 6:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("In-order traversal: ");
                    inorderTraversal(root);
                    printf("\n");
                }
                break;
            case 7:
                printf("Exiting the program...\n");
                if (root != NULL) {
                    freeTree(root);
                }
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}
