#include <stdio.h>  
#include <stdlib.h>
#define STACK_SIZE 5


typedef struct{
	int top;
	int data[STACK_SIZE];
}stack;

struct node{
	
	int data;
	struct node *next;
}; 

void reset(stack *stk){
	stk->top=-1;
}

void push(stack *stk,int x){
	
	if(stk->top+1==STACK_SIZE) // ==STACKSÝZE-1
		printf("stack is full");
	else{
		stk->top++;
		stk->data[stk->top]=x;  // x  =  stk->data[ ++stk->top ];

	}
}


int pop(stack *stk){
	
	if(stk->top==-1){
		printf("stack is empty");
		return -100;
	}
	else{
		
		int x= stk->data[stk->top]; 	// ya da tek satýrda ...
		stk->top--;					// return stk->data[stk->top--]
		
		return x; 
	}
}

void print(stack *stk){
	
	printf("\tvalues in stack");
	
	/*for(int i=stk->top;i>=0;i--){
		printf("%d ",stk->data[i]);
		
	} */
	
	while(stk->top!=-1){
		printf("\n%d ",stk->data[stk->top]);
		stk->top--;
	} 
}


int main(){
	
	stack *stk=malloc(sizeof(stk));
	reset(stk);
	
	
	push(stk,8);
	push(stk,7);
	push(stk,1);
	push(stk,3);
	
	pop(stk);
	
	print(stk);
	
	
	
}
