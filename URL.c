#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct BrowserHistory {
    Node* current;
} BrowserHistory;

Node* createNode(char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

BrowserHistory* init(char* homepage) {
    BrowserHistory* history = (BrowserHistory*)malloc(sizeof(BrowserHistory));
    history->current = createNode(homepage);
    return history;
}


void visit(BrowserHistory* history, char* url) {
    Node* newNode = createNode(url);

    
    if (history->current->next != NULL) {
        Node* temp = history->current->next;
        while (temp != NULL) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        history->current->next = NULL;
    }

    newNode->prev = history->current;
    history->current->next = newNode;
    history->current = newNode;

    printf("Visited: %s\n", history->current->url);
}


void back(BrowserHistory* history) {
    if (history->current->prev != NULL) {
        history->current = history->current->prev;
        printf("Back to: %s\n", history->current->url);
    } else {
        printf("No previous page!\n");
    }
}


void forward(BrowserHistory* history) {
    if (history->current->next != NULL) {
        history->current = history->current->next;
        printf("Forward to: %s\n", history->current->url);
    } else {
        printf("No forward page!\n");
    }
}


void getCurrentPage(BrowserHistory* history) {
    printf("Current Page: %s\n", history->current->url);
}


void freeHistory(Node* node) {
    while (node != NULL) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    char homepage[100];
    printf("Enter homepage URL: ");
    scanf("%s", homepage);

    BrowserHistory* history = init(homepage);

    int choice;
    char url[100];
    int t=1;
    while(t==1){
        printf("1. Visit new page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Current page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice==1){
                printf("Enter URL to visit: ");
                scanf("%s", url);
                visit(history, url);
        }
        else if(choice==2){
                back(history);
        }
        else if(choice==3){
                forward(history);
        }
        else if(choice==4){
                getCurrentPage(history);
        }
        else if(choice==5){
                printf("Exiting browser...\n");
                freeHistory(history->current); 
                free(history);
                t=0;
        }
        else{
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
