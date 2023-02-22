#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5


typedef struct{
	
	int cnt;
	int front,rear;
	int data[QUEUE_SIZE];
}queue;

int isFull(queue *q){
	if(q->cnt==QUEUE_SIZE)
		return 1;
	else
		return 0;
}

int isEmpty(queue *q){
	if(q->cnt==0)
		return 1;
	else
		return 0;
}

void initialize(queue *q){
	q-> cnt=0;
	q->front=0;
	q->rear=-1;
	
}

void enqueue(queue *q,int x){
	if(isFull(q))
		printf("queue is full");
		
	else{
		q->cnt++;
		q->rear++;
		
		if(q->rear==QUEUE_SIZE){
			q->rear=0;
		}
			
			
		q->data[q->rear]=x;
		
	}
	
}

int dequeue(queue *q){
	if(isEmpty(q)){
	
		printf("queue is empty");
		return -100;
	}
	else{
		int x=q->data[q->front];
		q->front++;
		q->cnt--;
		
		if(q->front==QUEUE_SIZE)
			q->front=0;  	// ???????????????
			
		return x;
	}

}

void print(queue *q){
	if(isEmpty(q)){
		printf("bosch aq");
	}
	else{
		int a=q->front;
		printf("----- Values ----\n");
		for(int i = 0; i<q->cnt ; i++){
		//while(a!=q->rear+1){
			printf("%5d",q->data[a]);
			a++;
			
			if(a==QUEUE_SIZE)
				a=0;
		}
	}
	printf("\n");
}

int main(){
	
	queue *q=malloc(sizeof(queue));
	initialize(q);
	enqueue(q,8);
	enqueue(q,4);
	enqueue(q,3);
	enqueue(q,1);
	enqueue(q,6);
	print(q);
	dequeue(q);
	enqueue(q,9);
//	enqueue(q,7);
	//dequeue(&q);
	//dequeue(&q);
	print(q);
}
