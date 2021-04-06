/* 
     Evaluating an postfix expression 
     

*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX 100

int stack[MAX];
int top = -1;

int pop(){
    
    int item;
    if(top < 0){
        printf("\n Stack underflow");
    }
    else{
          item = stack[top--];
          return item;
          
    }
}

void push(int x){
    if(top == MAX - 1){
        printf("Stack Overflow \n");
    }

    else{
        stack[++top] = x;
    }
}

void Evalpostfix(char postfix[]){
    
    int i = 0;
    char item = postfix[i];
    int A,B;
    int val;
    while(item != '\0'){
        
        if(isdigit(item)){
            push(item - '0');
        }

        else if(item == '+' || item == '-' || item == '*' || item == '/' || item == '^'){
            A = pop();
            B = pop();

            switch(item){
                
                case '*':
                val = B * A;
                break;

                case '+':
                val = B + A;
                break;

                case '-':
                val = B - A;
                break;

                case '/':
                val = B / A;
                break;

                case '^':
                val = pow(B,A);
                break;
            }
            push(val);

        }
        i++;
        item = postfix[i];

    }
    printf("The resultant value : %d", pop());
}
int main()
{
    char postfix[MAX];
    printf("Enter the postfix notation :  ");
    scanf("%s",postfix);
   

    Evalpostfix(postfix);

    return 0;
}