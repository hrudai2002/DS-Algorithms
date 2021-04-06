/*
Selection sort is used sort the array in ascending or descending order.
Time Complexity - O(n*2).

Reference - https://youtu.be/GUDLRan2DWM
*/



#include <stdio.h>
#include <stdlib.h>
 void Selectionsort(int a[],int n){

    for(int i = 0; i < n - 1; ++i){
        int mn = i;
        for(int j = i + 1; j < n; ++j){
            if(a[j] < a[mn]){
                mn = j;
            }
        }
        int t = a[i];
        a[i] = a[mn];
        a[mn] = t;
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

   Selectionsort(ar,n);

   for(int i = 0; i < n; ++i){
     printf("%d ",ar[i]);
   }

   return 0;
 }
