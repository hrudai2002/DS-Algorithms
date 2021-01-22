/*
Insertion sort is used sort the array in ascending or descending order.
Time Complexity - O(n*2).
Insertion sort is better than Bubble,Selection sort.
Reference - https://youtu.be/i-SKeOcBwko


*/
#include <stdio.h>
#include <stdlib.h>
 void Insertionsort(int ar[],int n){

   for(int i = 1; i < n; ++i){
     int key = ar[i];
     int j = i - 1;
     while(j >= 0 && ar[j] > key){
       ar[j + 1] = ar[j];
       j--;
     }
     ar[j + 1] = key;
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

   Insertionsort(ar,n);

   for(int i = 0; i < n; ++i){
     printf("%d ",ar[i]);
   }

   return 0;
 }
