#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
typedef struct Node {
    int data;           // Data stored in the node
    struct Node* left;  // Pointer to the left child node
    struct Node* right; // Pointer to the right child node
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;   // Set the data of the new node
    newNode->left = NULL;   // Initialize the left child pointer to NULL
    newNode->right = NULL;  // Initialize the right child pointer to NULL
    return newNode;
}

// Function to insert a new node into the binary tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);  // If the tree is empty, create a new node and return it
    }
    if (data < root->data) {
        root->left = insert(root->left, data);   // Recursively insert into the left subtree
    } else if (data > root->data) {
        root->right = insert(root->right, data); // Recursively insert into the right subtree
    }
    return root;
}

// Function to traverse the binary tree in inorder (left-root-right) fashion
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);       // Traverse the left subtree
        printf("%d ", root->data);          // Visit the root node
        inorderTraversal(root->right);      // Traverse the right subtree
    }
}

int main() {
    // Create the root node and insert elements into the binary tree
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Traverse the binary tree in inorder and print its elements
    printf("Inorder traversal of the binary tree: ");
    inorderTraversal(root);
    printf("\n");

    // Free memory allocated for the binary tree nodes
    // This should be done recursively, but for simplicity, we will not implement it here

    return 0;
}
