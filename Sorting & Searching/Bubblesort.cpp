/* 
 Bubble sort is used to sort an array in ascending or descending order
 Time Complexity - O(n*2)
 Reference - https://youtu.be/Jdtq5uKz-w4
 */
#include <stdio.h>
#include <stdlib.h>
 void Bubblesort(int a[],int n){

   for(int i = 0; i < n; ++i){
     for(int j = 0; j < n - i - 1; ++j){
         if(a[j] > a[j + 1]){
           int t = a[j];
           a[j] = a[j + 1];
           a[j + 1] = t;
         }
     }
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

   Bubblesort(ar,n);

   for(int i = 0; i < n; ++i){
     printf("%d ",ar[i]);
   }

   return 0;
 }
