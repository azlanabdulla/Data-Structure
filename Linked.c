#include<stdio.h>
#include<stdlib.h>

typedef struct term{
    int coeff;
    int expo;
    struct term* next;
}term;

term* CreateTerm(int coeff,int expo){
    term* t=(term*)malloc(sizeof(term));
    t->coeff = coeff;
    t->expo = expo;
    t->next = NULL;
    return t;
}
void append(term **head,int coeff,int expo){
    term* t=CreateTerm(coeff,expo);
    if(*head==NULL){
        *head=t;
    }
    else{
        term* cur= *head;
        while(cur->next){
            cur=cur->next;
        }
        cur->next=t;
    }
}
term* addpoly(term* a,term *b){
    term* c=NULL;
    while(a&&b){
        if(a->expo==b->expo){
            if((a->coeff+b->coeff)!=0){
                append(&c,a->coeff+b->coeff,a->expo);
            }
        a=a->next;
        b=b->next;
        }
        else if(a->expo < b->expo){
            append(&c,a->coeff,a->expo);
            a=a->next;
        }
        else{
            append(&c,b->coeff,b->expo);
            b=b->next;
        }

    }
    while(a){
        append(&c,a->coeff,a->expo);
        a=a->next;
    }
    while(b){
        append(&c,b->coeff,b->expo);
        b=b->next;
    }
    return c;
}
void display(term* t){
    if(!t){
        printf("empty\n");
        exit(1); 
    }
    else{
        while(t){
            printf("%dX^%d",t->coeff,t->expo);
            if(t->next && (t->next->coeff >=0)){
                printf("+");
                
            }
            else{
                printf(" ");
            
            }
            t=t->next;
        }
        printf("\n");
    }
}

void main(){
    term *a=NULL,*b=NULL,*c;
    int n,i,x,y;
    printf("enter the number of terms: ");
    scanf("%d",&n);
    printf("enter the polynomail: ");
    for(i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        append(&a,x,y);
    }
    printf("\n");
    display(a);
    printf("Polynomail A added\n");
    printf("enter the number of terms: ");
    scanf("%d",&n);
    printf("enter the polynomail: ");
    for(i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        append(&b,x,y);
    }
    printf("\n");
    display(b);
    printf("Polynomail B added\n");
    printf("Polynomial A:");
    display(a);
    printf("Polynomial B:");
    display(b);
    c=addpoly(a,b);
    printf("The Sum Is: ");
    display(c);
}