/* Binary search */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool Binary_search(int ar[],int n,int k){
    int l = 0;
    int r = n - 1;
    int mid = (l + r) / 2;

    while(l <= r){
        if(ar[mid] == k){
            return true;
        }
        else if(ar[mid] < k){
            l = mid + 1;
        }
        else 
          r = mid - 1;
        
        mid = (l + r) / 2;
    }
    return false;
}

int main()
{
    int n;
    int *ar;
    printf("Enter the size \n");
    scanf("%d", &n);
    ar = (int *)malloc(n*sizeof(int));
    for(int i = 0; i < n; ++i){
        scanf("%d",&ar[i]);
    }
    int k;
    printf("Enter the key element to be searched \n");
    scanf("%d",&k);
    if(Binary_search(ar,n,k)){
        printf("Element Found \n");
    }
    else{
        printf("Element is not found \n");
    }

    return 0;
}