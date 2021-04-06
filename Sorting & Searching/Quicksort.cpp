#include <stdio.h>
#include <stdlib.h>

// Partition index
int Partition(int a[],int start,int end){

 int pivot = a[end];
 int pi = start,i;

 for( i = start; i < end; ++i){
   if(a[i] <= pivot){
     int temp = a[i];
     a[i] = a[pi];
     a[pi] = temp;

     pi++;
   }
 }
 int temp = a[end];
 a[end] = a[pi];
 a[pi] = temp;

 return pi;
}

// Quicksort function
void Quicksort(int a[],int start,int end){

  if(start < end){
    int pi = Partition(a,start,end);

    Quicksort(a,start,pi - 1);
    Quicksort(a,pi + 1,end);
  }
}


int main()
{
  int n;
    scanf("%d",&n);
  int *ar;
  ar = (int *)malloc(n*sizeof(int));
  for(int i = 0; i < n; ++i){
    scanf("%d",&ar[i]);
  }
  Quicksort(ar,0,n-1);

  for(int i = 0; i < n; ++i){
    printf("%d ",ar[i]);
  }
  return 0;
}
