#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left, * right;
} Node;

Node* insert(Node* root, int val) {
    if (!root) {
        Node* n = malloc(sizeof(Node));
        n->data = val;
        n->left = n->right = NULL;
        return n;
    }
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    else printf("Value %d already exists.\n", val);
    return root;
}

void free_tree(Node* root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void dfs(Node* root) {
    if (!root) return;
    dfs(root->left);
    printf("%d ", root->data);
    dfs(root->right);
}

void bfs(Node* root) {
    if (!root) return;
    Node* queue[1024];
    int front = 0, back = 0;
    queue[back++] = root;
    while (front < back) {
        Node* cur = queue[front++];
        printf("%d ", cur->data);
        if (cur->left)  queue[back++] = cur->left;
        if (cur->right) queue[back++] = cur->right;
    }
}

void search(Node* root, int val) {
    if (!root) {
        printf("-> not found\n");
        return;
    }
    printf("[%d] ", root->data);
    if (val == root->data) {
        printf("-> found!\n");
    }
    else if (val < root->data) {
        printf("-> left ");
        search(root->left, val);
    }
    else {
        printf("-> right ");
        search(root->right, val);
    }
}

void print_menu() {
    printf("\nMENU\n");
    printf("1. Insert element\n");
    printf("2. Preorder (NLR)\n");
    printf("3. DFS / Inorder (LNR)\n");
    printf("4. BFS\n");
    printf("5. Search element\n");
    printf("6. Clear tree\n");
    printf("0. Exit\n");
    printf("Choice: ");
}

Node* input_tree() {
    Node* root = NULL;
    int n, val;

    printf("Enter number of elements: ");
    if (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return NULL;
    }

    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf_s("%d", &val) != 1) {
            printf("Invalid input. Clearing tree.\n");
            free_tree(root);
            while (getchar() != '\n');
            return NULL;
        }
        root = insert(root, val);
    }

    return root;
}

int main() {
    Node* root = NULL;
    int choice, val;

    printf("=== Initial tree input ===\n");
    root = input_tree();
    if (!root) {
        printf("Failed to build tree. Exiting.\n");
        return 1;
    }
    printf("Tree built successfully.\n");

    while (1) {
        print_menu();

        if (scanf_s("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            if (scanf_s("%d", &val) != 1) {
                printf("Invalid value.\n");
                while (getchar() != '\n');
                break;
            }
            root = insert(root, val);
            printf("Inserted %d.\n", val);
            break;

        case 2:
            printf("Preorder (NLR): ");
            preorder(root);
            printf("\n");
            break;

        case 3:
            printf("DFS / Inorder (LNR): ");
            dfs(root);
            printf("\n");
            break;

        case 4:
            printf("BFS: ");
            bfs(root);
            printf("\n");
            break;

        case 5:
            printf("Enter search key: ");
            if (scanf_s("%d", &val) != 1) {
                printf("Invalid value.\n");
                while (getchar() != '\n');
                break;
            }
            printf("Search path: ");
            search(root, val);
            break;

        case 6:
            free_tree(root);
            root = NULL;
            printf("Tree cleared. Please build a new one.\n");
            root = input_tree();
            if (!root) {
                printf("Failed to build tree. Exiting.  \n");
                return 1;
            }
            printf("Tree built successfully.\n");
            break;

        case 0:
            free_tree(root);
            printf("Exiting.\n");
            return 0;

        default:
            printf("Unknown option.\n");
            break;
        }
    }
}