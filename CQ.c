#include<stdio.h>
#define size 5

int queue[size];
int front=-1,rear=-1;

void eq(int value){

	if((rear+1)%size==front){
	    printf("overflow");}
	else{
		if(front==-1)
			front=0;

		rear=(rear+1)%size;
		queue[rear]=value;

	}
	printf("\nVALUE ADDED\n");
}
void dq(){

	if (front==-1)
		printf("underflow");
	else{
		printf("the deleted element is %d",queue[front]);
		if(front==rear)
			front=rear=-1;
		else{
			front=(front+1)%size;
		}
	}
}
void display(){
	printf("DISPLAY:\n");
	if(front==-1)
		printf("empty");
	else{
		int i=front;
		while(1){
			printf("%d",queue[i]);
			if(i==rear)
				break;
			i=(i+1)%size;
			printf("\n");

		}
	printf("\n");
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

}
