#include <stdio.h>	// Double Linked List Operations
#include <stdlib.h>


struct node{
	int data;
	struct node *prev;
	struct node *next;
};


struct node *addfront(struct node*head,int x){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	
	temp->data=x;
	temp->next=head;
	temp->prev=NULL;
	
	if(head!=NULL)
		head->prev=temp;
	
	head = temp;

    return head;
}

struct node *addlast(struct node*head,int x){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL){
		temp->prev=NULL;
		head=temp;
	}
	else{
		struct node *last=head;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=temp;
		temp->prev=last;
		temp->next=NULL;
		
	}
	
	return head;
}
void print(struct node*head){
		
		struct node*temp=head;
		if(head==NULL)
			printf("list is empty");
		else{
			while(head!=NULL){
	
				printf("%d ",head->data);
				head=head->next;
			} 
		}
		
	}
int main(){
	struct node *head=(struct node*)malloc(sizeof(struct node));
	head->data=8;
	head->next=NULL;
	head->prev=NULL;
	head->next=(struct node*)malloc(sizeof(struct node));
	head->next->data=9;
	head->next->next=NULL;
	
	print(head);
	printf("\n--------------\n");
	
	head=addfront(head,7);
	
	head=addlast(head,5);
	
	head=addfront(head,1);
	
	print(head);
	
}


