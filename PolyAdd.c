#include<stdio.h>

struct Term{
   int exp;
   int coeff;
};
struct poly{
	int n;
	struct Term t[100];
	
}a,b,c;

void ReadA(){
	int i;
	printf("enter the power of polynomial(A): ");
	scanf("%d",&a.n);
	printf("\nenter the polynomial: ");
	for(i=0;i<a.n;i++){
		scanf("%d%d",&a.t[i].coeff,&a.t[i].exp);
	}
}
void ReadB(){
	
	int i;
	printf("\nenter the power of polynomial(B) : ");
	scanf("%d",&b.n);
	printf("\nenter the polynomial: ");
	for(i=0;i<b.n;i++){
		scanf("%d%d",&b.t[i].coeff,&b.t[i].exp);
	}
}
void AddPoly(){
	 int ia=0,ib=0,ic=0;
	 while(ia<a.n &&ib<b.n){
	  	if(a.t[ia].exp==b.t[ib].exp){    
	  	     c.t[ic].exp=a.t[ia].exp;
	  	     c.t[ic].coeff=a.t[ia].coeff+b.t[ib].coeff;
	  	     ic++,ia++,ib++;
	  	     
	  	}
	  	else if(a.t[ia].exp>b.t[ib].exp){
	  	 	c.t[ic].exp=b.t[ib].exp;
	  	 	c.t[ic].coeff=b.t[ib].coeff;
	  	 	ic++,ib++;
	  	}
	  	else{
	  	        c.t[ic].exp=a.t[ia].exp;
	  	 	c.t[ic].coeff=a.t[ia].coeff;
	  	 	ic++,ia++;
	  	
	  	}

	}
	while (ia<a.n){
		c.t[ic].exp=a.t[ia].exp;
	  	c.t[ic].coeff=a.t[ia].coeff;
	  	ic++,ia++;
	}
	while (ib<b.n){
		c.t[ic].exp=b.t[ib].exp;
	  	c.t[ic].coeff=b.t[ib].coeff;
	  	ic++,ib++;
	}
	
	c.n=ic;
 
}


void Display(){
	int i;
	printf("\npolynomial A:");
	for(i=0;i<a.n;i++){
		printf("%dx^%d",a.t[i].coeff,a.t[i].exp);
		if(i!=a.n-1){
			printf("+");
		}
	}
	printf("\npolynomial B:");
	for(i=0;i<b.n;i++){
		printf("%dx^%d",b.t[i].coeff,b.t[i].exp);
		if(i!=b.n-1){
			printf("+");
		}
	}
	printf("\nthe resultant polynomial: ");
	for(i=0;i<c.n;i++){
		printf("%dx^%d",c.t[i].coeff,c.t[i].exp);
		if(i!=c.n-1){
			printf("+");
		}
	}
}

 void  main(){
    ReadA();
    ReadB();
    AddPoly();
    Display();
    
    
    
 }
