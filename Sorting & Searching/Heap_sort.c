/*

Heap Sort 


*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100


void swap(int *a,int *b){
  int t = *a;
     *a = *b;
     *b =  t;
}
void heapify(int ar[],int n,int i){

  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;

  if(l < n && ar[l] >= ar[largest])
     largest = l;
  if(r < n && ar[r] >= ar[largest])
     largest = r;
  if(largest != i){
    swap(&ar[largest],&ar[i]);
    heapify(ar,n,largest);
  }
}
void Heapsort(int ar[],int n){

   for(int i = n/2 - 1; i >= 0; --i){
     heapify(ar,n,i);
   } 
   
   for(int i = n - 1; i > 0; --i){
       
       swap(&ar[0],&ar[i]);
       heapify(ar,i,0);
   }   
}

void Print(int ar[],int n){

  printf("Heap elements \n");
  for(int i = 0; i < n; ++i)
    printf("%d ",ar[i]);
  printf("\n");
}
int main()
{
 
 int n; 
   scanf("%d",&n);
 int ar[n];
   for(int i = 0; i < n; ++i)
    scanf("%d",&ar[i]);
  Heapsort(ar,n);
  Print(ar,n);
 
 
    return 0;

}