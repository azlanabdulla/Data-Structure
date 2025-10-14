#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': return 2;
        case '/': return 2;
        case '+': return 1;
        case '-': return 1;
        default:  return 0;
    }
}

void ItoP(char infix[], char postfix[]) {
    int i, k = 0;
    for (i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isdigit(c)) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        else { // operator
            while (top != -1 && 
                  ((precedence(stack[top]) > precedence(c)) ||
                  (precedence(stack[top]) == precedence(c) && c != '^'))) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int EvalPostFix(char postfix[]) {
    int st[MAX], t = -1;
    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            st[++t] = c - '0';
        } else {
            int b = st[t--];
            int a = st[t--];
            switch (c) {
                case '+': st[++t] = a + b; 
				          break;
                case '-': st[++t] = a - b; 
				          break;
                case '*': st[++t] = a * b; 
				          break;
                case '/': st[++t] = a / b; 
				          break;
                case '^': st[++t] = pow(a, b); 
				          break;
            }
        }
    }
    return st[t];
}

void main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression : ");
    scanf("%s", infix);

    ItoP(infix, postfix);
    printf("Postfix : %s\n", postfix);
    printf("Result  : %d\n", EvalPostFix(postfix));
 
}