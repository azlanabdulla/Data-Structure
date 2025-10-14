#include<stdio.h>
#define size 5
int deque[size];
int front=-1,rear=-1;
void insertFront(int value){
    if((front==0&&rear==size-1)||(front==rear+1)){
        printf("Deque Overflow!!");
    }
    else{
        if(front==-1) front=rear=0;
        else if(front==0)front=size-1;
        else front--;
        deque[front]=value;
    }
}
void insertRear(int value){
    if((front==0&&rear==size-1)||(front==rear+1)){
        printf("Deque Overflow!!");
    }
    else{
        if(front==-1) front=rear=0;
        else if(rear==size-1)rear=0;
        else rear++;   
        deque[rear]=value;
    }
}
void deleteFront(){
    if(front==-1){
        printf("UnderFlow!!");
    }
    else{
        printf("delted from the front: %d \n",deque[front]);
        if(front==rear) front=rear=-1;
        else if(front==size-1)front=0;
        else front++;
    }
}
void deleteRear(){
    if(front==-1) printf("UnderFlow!!");
    else{
        printf("Deleted from rear: %d\n",deque[rear]);
        if(front==rear)front=rear=-1;
        else if(rear==0)rear=size-1;
        else rear--;
    }
}
void display(){
    if(front==-1) printf("Empty");
    else{
        printf("deque : ");
        int i=front;
        while(1){
            printf("%d ",deque[i]);
            if(i==rear) break;
            i=(i+1)%size;
        }
    }printf("\n");
}

void main(){
    int val,i,op,t;
    t=1;
    while(t==1){
        printf("1.InsertFront\t2.InsertRear\t3.DeleteFront\t4.DeleteRear\t5.Display\t6.Exit\n");
        scanf("%d",&op);
        if(op==1){
            printf("Enter the value : ");
            scanf("%d",&val);
            insertFront(val);
        }
        else if(op==2){
            printf("Enter the value : ");
            scanf("%d",&val);
            insertRear(val);
        }
        else if(op==3){
            deleteFront();
        }
        else if (op==4){
            deleteRear();
        }
        else if(op==5){
            display();
        }
        else if(op==6){
            t=0;
        }
        else{
            printf("invlaid option !!");
        }
    }
}
