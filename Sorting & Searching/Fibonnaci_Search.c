#include <stdio.h>
#include <malloc.h>

/* 

   Fibonnaci Search
> The Array Must Be sorted
> Similar to Binary Search
> Time Complexity - O(Logn)

*/

/* return's the minimum element*/
int min(int a,int b){
    return (a <= b)? a : b;
}

int fbsearch(int ar[],int x,int n){

    int a = 0; // (m - 2)th fibonacci number
    int b = 1; // (m - 1)th fibonacci number
    int c = a + b; // mth fibonacci number

    int offset = -1;

    while(c < n){
        a = b;
        b = c;
        c = a + b;
    }

    while(a > 1){

        int i = min(offset + a,n - 1);

        if(ar[i] < x){
            c = b;
            b = a;
            a = c - b;
            offset = i;
        }

        else if(ar[i] > x){
             c = a;
             b = b - a;
             a = c - b;
        }

        else 
          return i;
    }

    if(a && ar[offset + 1] == x)
       return offset + 1;
     
     return -1;
}

int main(){
    int n;
     scanf("%d",&n); // size of ther array
    
    int ar[n];
     for(int i = 0; i < n; ++i)
       scanf("%d",&ar[i]); // array elements
    
    int key;
     scanf("%d",&key); // element to be searched
    int id = fbsearch(ar,key,n);
    
    if(id >= 0)
      printf("Element Found \n");
    else 
      printf("Element not found \n");
    
    return 0;

}




