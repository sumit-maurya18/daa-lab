#include <stdio.h>
#include <stdlib.h>

#define MAX 3  // Maximum keys per node (2*t - 1, here t=2)

struct BTreeNode {
    int keys[MAX + 1];
    int count;
    struct BTreeNode *child[MAX + 1];
};

struct BTreeNode *root = NULL;


struct BTreeNode *createNode(int key, struct BTreeNode *child);
void insertValue(int key);
void insertNode(int key, int pos, struct BTreeNode *node, struct BTreeNode *child);
void splitNode(int key, int *pval, int pos, struct BTreeNode *node, struct BTreeNode *child, struct BTreeNode **newNode);
int setValueInNode(int key, int *pval, struct BTreeNode *node, struct BTreeNode **child);
void inorderTraversal(struct BTreeNode *node);
void printLevel(struct BTreeNode *root, int level);
int height(struct BTreeNode *root);
void printBTree(struct BTreeNode *root);

//CREATE NEW NODE
struct BTreeNode *createNode(int key, struct BTreeNode *child) {
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    newNode->keys[1] = key;
    newNode->count = 1;
    newNode->child[0] = root;
    newNode->child[1] = child;
    return newNode;
}

//INSERT VALUE
void insertValue(int key) {
    int flag, i;
    struct BTreeNode *child;
    flag = setValueInNode(key, &i, root, &child);
    if (flag)
        root = createNode(i, child);
}

//RECURSIVE INSERTION
int setValueInNode(int key, int *pval, struct BTreeNode *node, struct BTreeNode **child) {
    int pos;
    if (node == NULL) {
        *pval = key;
        *child = NULL;
        return 1;
    }

    if (key < node->keys[1])
        pos = 0;
    else {
        for (pos = node->count; (key < node->keys[pos] && pos > 1); pos--);
        if (key == node->keys[pos]) {
            printf("Duplicate key %d ignored.\n", key);
            return 0;
        }
    }

    int flag = setValueInNode(key, pval, node->child[pos], child);

    if (flag) {
        if (node->count < MAX)
            insertNode(*pval, pos, node, *child);
        else {
            splitNode(*pval, pval, pos, node, *child, child);
            return 1;
        }
    }
    return 0;
}

//INSERT IN NODE
void insertNode(int key, int pos, struct BTreeNode *node, struct BTreeNode *child) {
    for (int j = node->count; j > pos; j--) {
        node->keys[j + 1] = node->keys[j];
        node->child[j + 1] = node->child[j];
    }
    node->keys[pos + 1] = key;
    node->child[pos + 1] = child;
    node->count++;
}

//SPLIT NODE
void splitNode(int key, int *pval, int pos, struct BTreeNode *node, struct BTreeNode *child, struct BTreeNode **newNode) {
    int median, j;
    if (pos > 1)
        median = 2;
    else
        median = 1;

    *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    j = median + 1;

    while (j <= MAX) {
        (*newNode)->keys[j - median] = node->keys[j];
        (*newNode)->child[j - median] = node->child[j];
        j++;
    }

    (*newNode)->count = MAX - median;
    node->count = median;

    if (pos <= median)
        insertNode(key, pos, node, child);
    else
        insertNode(key, pos - median, *newNode, child);

    *pval = node->keys[node->count];
    (*newNode)->child[0] = node->child[node->count];
    node->count--;
}

//INORDER TRAVERSAL
void inorderTraversal(struct BTreeNode *node) {
    if (node != NULL) {
        for (int i = 0; i < node->count; i++) {
            inorderTraversal(node->child[i]);
            printf("%d ", node->keys[i + 1]);
        }
        inorderTraversal(node->child[node->count]);
    }
}

//DISPLAY (LEVEL ORDER PRINT)
int height(struct BTreeNode *root) {
    if (root == NULL)
        return 0;
    int h = 0;
    struct BTreeNode *temp = root;
    while (temp) {
        h++;
        temp = temp->child[0];
    }
    return h;
}

void printLevel(struct BTreeNode *root, int level) {
    if (root == NULL)
        return;

    if (level == 1) {
        printf("[");
        for (int i = 1; i <= root->count; i++) {
            printf("%d", root->keys[i]);
            if (i != root->count)
                printf(" ");
        }
        printf("] ");
    } else if (level > 1) {
        for (int i = 0; i <= root->count; i++)
            printLevel(root->child[i], level - 1);
    }
}

void printBTree(struct BTreeNode *root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printf("Level %d: ", i);
        printLevel(root, i);
        printf("\n");
    }
}

int main() {
    int keys[] = {10, 20, 5, 6, 12};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("B-Tree Insertion Operation\n");
    printf("--------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("\nInserting key: %d\n", keys[i]);
        insertValue(keys[i]);
        printf("B-Tree structure after insertion:\n");
        printBTree(root);
        printf("\n");
    }

    printf("\nFinal Inorder Traversal of B-Tree:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
