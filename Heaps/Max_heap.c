// MAX HEAP
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int Heap[MAX];
int size = 0;
void swap(int *a,int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(int i){
    if(size == 1){
        printf("Single element is present in the Heap \n");
    }
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < size && Heap[l] >= Heap[i])
       largest = l;
    if(r < size && Heap[r] >= Heap[i])
       largest = r;
    if(largest != i){
        swap(&Heap[i],&Heap[largest]);
        heapify(i);
    }
}
void insert(int  value){
    
    //int i;
    if(size == 0){
        Heap[size++] = value;
        return;
    }
    Heap[size++] = value;
    for(int i = size/2 - 1; i >= 0; --i){
        heapify(i);
    }
}
void Delete(int val){

    int i;
    for(i = 0; i < size; ++i){
        if(val == Heap[i])
           break;
    }
    if(i == size){
        printf("Element is not present in the Heap \n");
        return;
    }
    swap(&Heap[i],&Heap[size - 1]);
    size--;
    for(int i = size/2 - 1; i >= 0; --i){
        heapify(i);
    }

}
void print(){
    printf("Heap elements : ");
    for(int i = 0; i < size; ++i){
        printf("%d ",Heap[i]);
    }
    printf("\n");
}
int main()
{
    int ch = 1;
    int choice;
    int elem;
    printf("1. Insert the element into Heap \n");
    printf("2. Delete an element from the Heap\n");
    printf("3. Display \n");
    printf("4. Exit \n");
    while(ch){
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
              printf("Enter the element \n");
              scanf("%d" ,&elem);
              insert(elem);
              break;
            
            case 2:
             printf("Enter the element to be deleted \n");
             scanf("%d", &elem);
             Delete(elem);
             break;

            case 3:
             print();
             break;

            case 4:
              exit(0);
        }


    }
    return 0;
}