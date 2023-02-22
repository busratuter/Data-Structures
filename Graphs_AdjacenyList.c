#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node * next;
};


int outdegree(struct node *heads[],int v){
    int result = 0;
    struct node *temp = heads[v] ->next;
    while(temp!= NULL){
        result++;
        temp= temp -> next;
    } 
    return result;
}

struct node *addEdge(struct node *head,int key) {
    if(head==NULL)
    {
    head = (struct node *)malloc(sizeof(struct node));
    head->data = key;
    head->next = NULL;
    return head;
    }
    else
    {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = key;
    temp -> next = NULL;
    struct node *temp2 = head;
    while(temp2 -> next != NULL)
            temp2 = temp2 -> next;
        temp2 -> next = temp;
        return head;
    }
}

int main(){

    int n=5,i;
    struct node *heads[5];

    for(i=0;i<n;i++)
    {
        heads[i] = NULL;
    }
    heads[0] = addEdge(heads[0],1);
    heads[0] = addEdge(heads[0],2);
    heads[1] = addEdge(heads[1],2);
    heads[1] = addEdge(heads[1],4);
    heads[2] = addEdge(heads[2],3);
    heads[2] = addEdge(heads[2],1);
    heads[2] = addEdge(heads[2],4);
    heads[2] = addEdge(heads[2],5);
    heads[3] = addEdge(heads[3],4);
    heads[3] = addEdge(heads[3],1);
    heads[3] = addEdge(heads[3],3);
    heads[4] = addEdge(heads[4],5);
    for(i=0;i<n;i++){
        printf(" \n outdegree of vertex %d= %d",i+1,outdegree(heads,i));
}
}
