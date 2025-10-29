#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node { 
    char word[100];
    char meaning[256];
    struct Node *left;
    struct Node *right; 
};

struct Node *CreateNode(const char *word, const char *meaning) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, const char *word, const char *meaning) {
    if (root == NULL) {
        return CreateNode(word, meaning);
    }
    int cmp = strcmp(word, root->word);
    if (cmp < 0) {
        root->left = insert(root->left, word, meaning);
    } else if (cmp > 0) {
        root->right = insert(root->right, word, meaning);
    } else {
        strcpy(root->meaning, meaning); // update existing
    }
    return root;
}

struct Node *Search(struct Node *root, const char *word) {
    if (root == NULL) return NULL;

    int cmp = strcmp(word, root->word);
    if (cmp == 0)
        return root;
    else if (cmp < 0)
        return Search(root->left, word);
    else
        return Search(root->right, word);
}

void InOrder(struct Node *root) {
    if (root != NULL) {
        InOrder(root->left);
        printf("%s : %s\n", root->word, root->meaning); 
        InOrder(root->right);
    }
}

void FreeTree(struct Node *root) {
    if (root) {
        FreeTree(root->left);
        FreeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node *root = NULL;
    int choice;
    char word[100], meaning[256];
    struct Node *temp;

    while (1) {
        printf("\nDictionary Menu:\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter the word: ");
                scanf("%s", word);
                getchar(); 
                printf("Enter the meaning: ");
                scanf(" %[^\n]", meaning);
                root = insert(root, word, meaning);
                printf("Word added successfully!\n");
                break;

            case 2:
                printf("Enter the word to search: ");
                scanf("%s", word);
                temp = Search(root, word);
                if (temp)
                    printf("Meaning: %s\n", temp->meaning);
                else
                    printf("Word not found!\n");
                break;

            case 3:
                printf("\nDictionary:\n");
                InOrder(root);
                break;

            case 4:
                FreeTree(root);
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
