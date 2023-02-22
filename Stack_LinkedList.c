#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5


typedef struct{
	int cnt;
	struct node *top;
}stack;

struct node{
	
	int data;
	struct node *next;
};

void initialize(stack *stk){
	
	int cnt=0;
	stk->top=NULL;
	
}

void push(stack *stk,int x){
	if(stk->top==STACK_SIZE)
		printf("stack is full");
	else{
		struct node *temp=(struct node*)malloc(sizeof(struct node*));
		temp->data=x;
		temp->next=stk->top;
		stk->top=temp;
		stk->cnt++;
	}
}

int pop(stack *stk){
	
	int a=0;
	
	if(stk->cnt==0){
	
		printf("stack iss empty");
		return -100;
	}
	
	else{
		int a=stk->top->data;
		struct node *temp=stk->top;
		stk->top=stk->top->next;
		free(temp);
		
		stk->cnt--;
		
		return a;
	}

}

	print(stack *stk){
		struct node *temp;
		temp=stk->top;
		
		while(temp!=NULL){
			printf("\n\t%d\n",temp->data);
			temp=temp->next;
		}
	}


int main(){
	stack *stk=malloc(sizeof(*stk));
	initialize(stk);
	push(stk,5);
	push(stk,9);
	push(stk,1);
	push(stk,8);
	push(stk,0);
	pop(stk);
	pop(stk);
	
	printf("Values in stack: ");
	print(stk);
}
