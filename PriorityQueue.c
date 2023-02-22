#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10


struct priority_queue{
	int a[QUEUE_SIZE+1];
	int cnt;
};

typedef struct priority_queue pqueue;

void initialize(pqueue *p){
	p->cnt=0;
}

void insert(pqueue *p, int key){
	if(p->cnt==QUEUE_SIZE)
		printf("queue is full");
	else{
		p->cnt++;
		p->a[p->cnt]=key;
		int iter=p->cnt;
		
	
	
		while(iter!=1 && p->a[iter] < p->a[iter/2]){
			int temp=p->a[iter]; 		// 3 satýr swap islemi
			p->a[iter]=p->a[iter/2];
			p->a[iter/2]=temp;
		
			iter=iter/2;
		}
	}	
}

int delette(pqueue *p){
	
	if(p->cnt==0){
	
		printf("queue is empty");
		return -100;
	}	
	else{
		int key=p->a[1];
		p->a[1]=p->a[p->cnt];
		p->cnt--;
		
		int iter=1;
		
		while(2*iter<=p->cnt && (p->a[iter] > p->a[2*iter] || p->a[iter] > p->a[2*iter + 1])){
			if(p->a[2*iter] < p->a[2*iter + 1 ]){  //sol cocuk sagdan buyukse
				int temp=p->a[iter]; 		// 3 satýr swap islemi
				p->a[iter]=p->a[2*iter];
				p->a[2*iter]=temp;
				
				iter=2*iter;
			}
			else{
				int temp1=p->a[iter]; 		// 2*iter + 1 ... sag cocuk
				p->a[iter]=p->a[2*iter + 1];
				p->a[2*iter+1]=temp1;
				
				iter=2*iter+1;
				
			}
		}
	return key;
	}
	
}

pqueue *convert(pqueue *q) {
    int n = QUEUE_SIZE; // heap'teki eleman sayýsýný al

    for (int i = (n - 2) / 2; i >= 0; i--) { // tüm parent düðümler için
        int k = i; // k: current node
        int j = 2 * k + 1; // j: left child of k

        if (j < n - 1 && q->array[j] < q->array[j + 1]) {
            j++; // j: right child of k
        }

        if (q->array[k] < q->array[j]) { // eðer current node küçükse
            int temp = q->array[k]; // swap yap
            q->array[k] = q->array[j];
            q->array[j] = temp;
            k = j;
        }
    }
    return q;
}

void printt(pqueue *p){
	if(p->cnt==0)
		printf("queue is empty");
	else{
		printf("Kuyruktaki elemanlar...");
		
		for(int i=1;i<=p->cnt;i++){
			
			printf("%5d", p->a[i]);
		}
	}
}

int main(){
	int key;
	pqueue p;
	int secim;
	
	initialize(&p);
	
//	printf("sayi griiniz");
//	scanf("%d", &key);
	
	/*while(key!=-1){
		insert(&p,key);
		scanf("%d",&key);
	} */
	insert(&p,10);
	insert(&p,7);
	insert(&p,6);
	insert(&p,4);
	insert(&p,11);
	
	printt(&p);
	
	delette(&p);
	delette(&p);
	
	
	printf("\nsilindi\n");
	printt(&p);
	
	convert(q);
	printt(&p);
	
	return 0;
}
