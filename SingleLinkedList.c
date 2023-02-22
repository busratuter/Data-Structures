#include <stdio.h>	// Single Linked List Operations 
#include <stdlib.h>
struct node{
	
	int data;
	struct node *next;
};

	struct node *createlist(struct node*head,int x){
		struct node *temp;
		
		if(head==NULL){
			head=(struct node*)malloc(sizeof(struct node));
			temp=head;
		}
		
		else{
			temp->next=(struct node*)malloc(sizeof(struct node));
			temp=temp->next;
		}
		temp->data=x;		
		temp->next=NULL;
		return head;
	}
	
	struct node *addfront(struct node *head,int x){
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		
		temp->data=x;
		temp->next=head;
		head=temp;
		
		return head;
	}
	
	struct node *addlast(struct node *head,int x){
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		
		temp->data=x;
		temp->next=NULL;
		
		if(head==NULL)
			head=temp;
		else{
			struct node *last=head;
			while(last->next!=NULL)
				last=last->next;
			last->next=temp;
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
	
	void printreverse(struct node* head){
		
		if(head==NULL)
			return;
		else{

			printreverse(head->next);
			printf("%4d",head->data);
		}
	}
	
	struct node *delnode(struct node *head,int key){
	
	
	if(head!=NULL){ // liste doluysa
		
		struct node *temp=head;
		if(head->data==key){
			head=head->next;
			free(temp);
		}
	
		else{
			while(temp->next!=NULL && temp->next->data!=key){
				temp=temp->next;
			}
			if(temp->next==NULL)
				return head;
				
			struct node *deleted=temp->next;
			
			temp->next=deleted->next;
			free(deleted);
		}
	}
		
		return head;
	}
	
	
	struct node *search(struct node *head,int aranan){
		
		struct node *temp=head;
		
		while(temp!=NULL){
			if(temp->data==aranan)
				printf("aradiginiz sayi %d",aranan);
			temp=temp->next;
		}
		
		return head;
		
	}
int main(){
	
	int secim,x;
	struct node *head=NULL;
	printf("1-Create a list\n2-Add node in front\n3-Add node to the end\n4-Print list\n5-Print reverse\n6-Delete node");
	printf("\nwhat do you want on list?");
	scanf("%d",&secim);
	
	while(1){
		
	switch (secim){
		case 1: 
		
		printf("which number you want to add to the node??");
		scanf("%d",&x); 
		head=createlist(head,x); break;
		
		case 2:
	
		printf("which number you want to add to the node??");
		scanf("%d",&x);
		head=addfront(head,x); break;
		
		case 3:
	
		printf("which number you want to add to the node??");
		scanf("%d",&x);
		head= addlast(head,x); break;
		
		case 4: print(head); break;
		case 5: printreverse(head); break;
		case 6: 
		printf("which number you want to dell to the list??");
		int key;
		scanf("%d",&key);
		head=delnode(head,key); break;
		
		case 7:
		printf("which number you search??");
		int aranan;
		scanf("%d",&aranan);
		head=search(head,aranan); break;
	}
		printf("\n1-Create a list\n2-Add node in front\n3-Add node to the end\n4-Print list\n5-Print reverse\n6-Delete node\n7-Search node");
		printf("\nwhat do you want on list again?");
		scanf("%d",&secim);
	}
}
