#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

// Structure for Red-Black Tree Node
struct Node {
    int data;
    enum Color color;
    struct Node *left, *right, *parent;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->color = RED;  // New node is always red initially
    node->left = node->right = node->parent = NULL;
    return node;
}

// Left Rotation
void rotateLeft(struct Node** root, struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

// Right Rotation
void rotateRight(struct Node** root, struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;

    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

// Fix Red-Black Tree violations after insertion
void fixViolation(struct Node** root, struct Node* z) {
    while (z != *root && z->parent->color == RED) {
        struct Node* parent = z->parent;
        struct Node* grandparent = parent->parent;

        // Case A: Parent is left child of Grandparent
        if (parent == grandparent->left) {
            struct Node* uncle = grandparent->right;

            // Case 1: Uncle is RED — recoloring
            if (uncle != NULL && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            } else {
                // Case 2: z is right child — left rotation needed
                if (z == parent->right) {
                    z = parent;
                    rotateLeft(root, z);
                }
                // Case 3: z is left child — right rotation needed
                parent->color = BLACK;
                grandparent->color = RED;
                rotateRight(root, grandparent);
            }
        }

        // Case B: Parent is right child of Grandparent
        else {
            struct Node* uncle = grandparent->left;

            // Case 1: Uncle is RED — recoloring
            if (uncle != NULL && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            } else {
                // Case 2: z is left child — right rotation needed
                if (z == parent->left) {
                    z = parent;
                    rotateRight(root, z);
                }
                // Case 3: z is right child — left rotation needed
                parent->color = BLACK;
                grandparent->color = RED;
                rotateLeft(root, grandparent);
            }
        }
    }
    (*root)->color = BLACK;
}

// Insert a new node into BST normally, then fix Red-Black Tree
void insert(struct Node** root, int data) {
    struct Node* z = newNode(data);
    struct Node* y = NULL;
    struct Node* x = *root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == NULL)
        *root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    // Fix any Red-Black Tree property violations
    fixViolation(root, z);
}

// In-order traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d(%s) ", root->data, (root->color == RED) ? "R" : "B");
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;

    int elements[] = {10, 20, 30, 15, 25, 5};
    int n = sizeof(elements) / sizeof(elements[0]);

    printf("Inserting elements into Red-Black Tree:\n");
    for (int i = 0; i < n; i++) {
        printf("Insert: %d\n", elements[i]);
        insert(&root, elements[i]);
        printf("Inorder Traversal after insertion: ");
        inorder(root);
        printf("\n\n");
    }

    printf("Final Red-Black Tree (Inorder Traversal):\n");
    inorder(root);
    printf("\n");

    return 0;
}
