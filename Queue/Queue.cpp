#include<stdio.h>
//#define n 5
int main()
{
    int queue[100],ch=1,front=0,rear=0,i,n;
    printf("Queue using Array");
    printf("\n Enter the size of queue[MAX=100]:");
    scanf("%d",&n);
    printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit");
    while(ch)
    {
        printf("\nEnter the Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            if(rear == n)
                printf("\n Queue is Full");
            else
            {
                printf("\n Enter the element \n\t");
                scanf("%d",&queue[rear++]);
            }
            break;
        case 2:
            if(front==rear)
            {
                printf("\n Queue is empty");
            }
            else
            {
                printf("\n Deleted Element is %d",queue[front++]);
                
            }
            break;
        case 3:
            printf("\nQueue Elements are:\n ");
            if(front == rear)
                printf("\n Queue is Empty");
            else
            {
                for(i=front; i < rear; i++)
                {
                    printf("%d",queue[i]);
                    printf("\n");
                }
                break;
            case 4:
                ch = 0;
                break;
            default:
                printf("Wrong Choice: please see the options");
            }
        }
    }
    return 0;
}

