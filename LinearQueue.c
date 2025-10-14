#include<stdio.h>
#define size 5

int queue[size];
int front=-1,rear=-1;

void eq(int value){

	if(rear==size-1){
	    printf("overflow");}
	else{
		if(front==-1)
			front=0;
		queue[++rear]=value;

	}
	printf("\nVALUE ADDED\n");
}
void dq(){

	if ((front==-1)||(front>rear))
		printf("underflow");
	else{
		printf("the deleted element is %d",queue[front++]);
		if(front>rear)
			front=rear=-1;
	}
}
void display(){
	printf("DISPLAY:\n");
	if(front==-1)
		printf("empty");
	else{
        printf("Queue");
		for(int i=front;i<=rear;i++){
            printf("%d",queue[i]);
            printf("\n");

        }
	
	}
}

void main(){
	int opt,n,i=0;
	while(i==0){
		printf("\n");
		printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
		scanf("%d",&opt);
		if(opt==1){
		    printf("enter the element: ");
			scanf("%d",&n);
			eq(n);
			continue;
		}
		else if(opt==2){
		    dq();
			continue;

		}
		else if(opt==3){
			display();
			continue;
		}
		else if(opt==4){
			i=1;
			break;
		}
		else {
			printf("invalid option ");
			continue;
		}
	}
    // eq(3);
    // eq(5);
    // eq(8);
    // eq(3);
    // eq(1);
    // display();
    // dq();
    // dq();
    // dq();
    // display();
    // eq(3);
    // eq(5);




}
