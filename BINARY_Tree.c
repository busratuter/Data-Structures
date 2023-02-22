#include <stdio.h>  // Binary Tree Operations
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
	//struct node *parents; // bazen lazim olabiliyor
};

typedef struct node BTREE;


BTREE *new_node(int x){
	
	BTREE *p=(BTREE*)malloc(sizeof(BTREE));
	
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	
	return p;
	
}

 BTREE *insert(BTREE *root,int x){
 		
 		if(root==NULL)
 			root=new_node(x);
 			
 		else{
 			
 			if(x<root->data)
 				root->left=insert(root->left,x);
 			
 			else
 				root->right=insert(root->right,x);
		 }
	return root;
		 
 }


void inorder(BTREE *root){ //bastan siralama
	
	if(root!=NULL){
		
		inorder(root->left);
		inorder(root->right);
		printf("%5d",root->data);
		
	}
}

int countnode(BTREE *root){
	if(root==NULL){
		return 0;	
	}
	else 
		return 1 + countnode(root->left) + countnode(root->right);
}

int child(BTREE *root){ // parent sayiyor
	
	if(root==NULL)
		return 0;
	else if(root->left!=NULL || root->right!=NULL)
		return 1 + child(root->left) + child(root->right);
	
} 


int maxmin(BTREE *root){
	
	int top=0;
	int min=0;
	int max=0;
	BTREE *temp=root;
	if(root->left==NULL && root->right==NULL){
		return root->data;
	}
	else{
	
		while(temp->left!=NULL){
			temp=temp->left;
		}
		min=temp->data;
		printf("\n%d min value",min);
		
		temp=root;
	//	root=root;
	//	max=root->data;
		while(temp->right!=NULL){
			temp=temp->right;
		}
		
		max=temp->data;
		printf("\n%d max value\n",max);
		
	}
} 
void katcocuk(BTREE *root){
	
	if(root==NULL)
		return;
	
	else{
		
		if(root->right!=NULL||root->left!=NULL) {
			
			if(root->right->data==2*root->data)
				printf("%d\t",root->data);
			
			katcocuk(root->left);
			katcocuk(root->right);
		}
	}
}

int cift(BTREE *root){
    
    static int top=0;
    
    if(root==NULL)
        return 0;
    else{
        if(root->data%2==0)
            top+=root->data;
        
        cift(root->left);
        cift(root->right);
    }
    return top;
}

int yaprak(BTREE *root){
    
    
    if(root==NULL)
        return 0;
      
    
    if(root->right== NULL && root->left==NULL)
        return 1;
    
    return 0 + yaprak(root->left) + yaprak(root->right);
    
        
   
}
int topla(BTREE *root){
if(root == NULL){
return 0;
} else {
return topla(root->left)+topla(root->right)+
root->data;
}
}

int main(){
	
	BTREE *myroot=NULL;
	int i;
	
	printf("add to value to tree: ");
	scanf("%d",&i);
			
		while(i!=-1){
			
			myroot=insert(myroot,i);
			scanf("%d",&i);
		}
	inorder(myroot); // cause of the write values
	printf("%d",	maxmin(myroot));
	printf("\n number of children %d",child(myroot));
	printf("\n node sayisi %d",countnode(myroot));
	maxmin(myroot);
	
	printf("sum of even numbers %d\n",cift(myroot));
	printf("sum of leafs %d\n",yaprak(myroot));
	printf("\n\n sum of values %d",topla(myroot));
}


