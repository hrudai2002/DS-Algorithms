/* 
Multistack is having multiple stacks in single stack
here you can see the implementation of the multiple stack is array
*/


#include <stdio.h>
#define max 50
 
int top1, top2, stk_arr[max];
 
void push();
void pop();
void display();
 
int main()
{
int ch;
top1=-1,top2=max;
do
{
printf("\n 1:push\n 2:pop\n 3:display\n 4:exit\n choice:");
scanf("%d", &ch);
switch (ch)
{
case 1:push();
break;
case 2:pop();
break;
case 3:display();
break;
case 4:printf("exiting from program\n");
break;
default:printf("wrong choice\n");
break;
}
}while(ch!=4);
}
void push()
{
int x,ch;
if(top1==top2-1)
{
printf("stack overflow \n");
return;
}
printf("enter a no \n");
scanf("%d",&x);
printf("\n press 1 to push in stack1 or press 2 for stack2:");
scanf("%d",&ch);
if(ch==1)
stk_arr[++top1]=x;
else
stk_arr[--top2]=x;
printf("\n %d element is successfully pushed \n",x);
return;
}
 
void pop()
{
int y,ch;
printf("\n press 1 to pop from stack1 or press 2 for stack2");
scanf("%d",&ch);
if(ch==1)
{
if(top1==-1)
{
printf("stack underflow\n");
return;
}
y=stk_arr[top1];
stk_arr[top1--]=0;
}
else
{
if(top2==max)
{
printf("stack underflow\n");
return;
}
y=stk_arr[top2];
stk_arr[top2++]=0;
}
printf("\n%d element is successfully poped from stack \n", y);
return;
}
 
void display()
{
int i;
if (top1 == -1)
{
printf("stack 1 is empty \n");
}
else
{
printf("elements of Stack 1 are : \n");
for (i = top1; i >= 0; i--)
{
printf("%d\n",stk_arr[i]);
}
}
if (top2 == max)
{
printf("stack 2 is empty \n");
}
else
{
printf("elements of Stack 2 are : \n");
for (i = top1 + 1; i >= max; i++)
{
printf("%d\n",stk_arr[i]);
}
}
return ;
}
