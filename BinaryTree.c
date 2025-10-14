#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node{
    char *token;
    struct Node *left,*right;
}Node;

Node * new(const char *tok){
    Node *n =(Node *)malloc(sizeof(Node));
    n->token=malloc(strlen(tok)+1);
    strcpy(n->token,tok);
    n->left=n->right=NULL;
    return n;
}
int IsOperator(const char *tok){
    if(strlen(tok)==1){
        char c=tok[0];
        return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
    }
    return 0;
}
Node * buildTree(char * postfix){
    Node *stack[100];
    int top=0;
    char * tok=strtok(postfix," ");
    while(tok){
        if(!IsOperator(tok)){
            stack[top++]=new(tok);
        }
        else{
            Node *right=stack[--top];
            Node *left=stack[--top];
            Node *op=new(tok);
            op->left=left;
            op->right=right;
            stack[top++]=op;
        }
        tok=strtok(NULL," ");
    }
    return stack[0];
}
void printPrefix(Node *root){
    if(!root)return;
    printf("%s ",root->token);
    printPrefix(root->left);
    printPrefix(root->right);
}
void printInfix(Node *root){
    if(!root)return;
    if(IsOperator(root->token)){
        printf("(");
        printInfix(root->left);
        printf("%s ",root->token);
        printInfix(root->right);
        printf(")");
    }
    else{
        printf("%s",root->token);
    }
}
int eval(Node *root){
    if(!IsOperator(root->token)){
        return atoi(root->token);
    }
    int L=eval(root->left);
    int R=eval(root->right);
    switch(root->token[0]){
        case '+': return L+R;
        case '-': return L-R;
        case '*': return L*R;
        case '/': return L/R;
        case '^': return (int)pow(L,R);
    }
    return 0;
}
void FreeTree(Node *root){
    if(!root)return;
    FreeTree(root->left);
    FreeTree(root->right);
    free(root->token);
    free(root);
}
int main(){
    char input[200];
    printf("enter Postfix expression : ");
    fgets(input,sizeof(input),stdin);
    input[strcspn(input,"\n")]='\0';

    Node *root=buildTree(input);
    printf("\nPrefix: ");
    printPrefix(root);
    printf("\nInfix: ");
    printInfix(root);
    printf("\nEvaluate Result: %d\n",eval(root));
    FreeTree(root);
    return 0;
}