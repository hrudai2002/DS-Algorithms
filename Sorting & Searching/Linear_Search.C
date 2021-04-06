/* Linear search */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool linear_search(int ar[],int n,int k){
    for(int i = 0; i < n; ++i){
        if(ar[i] == k){
            return true;
        }

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
    if(linear_search(ar,n,k)){
        printf("Element Found \n");
    }
    else{
        printf("Element is not found \n");
    }

    return 0;
}