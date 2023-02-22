#include <stdlib.h>
#include <stdio.h>

int edges(int A[][5],int n){   
    int i,j,result = 0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            result += A[i][j];
        }
    }
    return result;
}

int degree(int v, int n, int A[n][n]) {  	//Kom�uluk matrisi ile temsil edilen y�NS�Z bir grafta bir d���m�n giri� derecesini 
												//bulan fonksiyonu yaz�n�z. 
    int result = 0;							// sat�rdaki 1ler out////degree
    for (int i = 0; i < n; i++) {
        result += A[v][i];
    }
    return result;	
}  												

 int indegree(int a[][tepe_sayisi],int v)  	//Kom�uluk matrisi ile temsil edilen Y�NL� bir grafta bir d���m�n giri� derecesini 
												//bulan fonksiyonu yaz�n�z. 
{ 												//s�tundaki 1 ler indegree
 int i,degree=0; 
 for(i=0; i<tepe_sayisi; i++) 
 degree+=a[i][v]; 
 
 return degree; 
 
}  

 int main(){

   int n=5,i;
    int A[5][5]={ {0,1,1,1,0},
                {1,0,0,1,0},
                {1,0,0,1,1},
                {1,1,1,0,1},
                {0,0,1,1,0}
             };
   
   int sum_degree = 0;
    for(i=0;i<n;i++){
        sum_degree += degree(i,n,A);
        printf("\n degree of vertex %d = %d",i+1, degree(i,n,A));
    }
    printf("\n Total degree of vertices = %d ",sum_degree);
    printf("\n Total number of edges = %d",edges(A,n));
return 0;
}
