/* 

Converting an infix expression to postfix expression


*/



#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;
void push(char item){
    
    if(top == MAX - 1){
        printf("\n Stack overflow");
    }

    else{
        stack[++top] = item;
    }
}

int is_operator(char item){
    if(item == '+' || item == '-' || item == '/' || item == '*' || item == '^'){
        return 1;
    }
    
    return 0;
}

char pop(){
    
    char item;
    if(top == -1){
        printf("Stack underflow \n");
    }
    else{
        item = stack[top];
        top = top - 1;
        return item;

    }
}
int precedence(char item){
    if(item == '^'){
        return 3;
    }
    else if(item == '*' || item == '/'){
        return 2;
    }
    else if(item == '+' || item == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

void InfixtoPostfix(char infix[],char postfix[]){
    int i,j;
    char item;
    char x;
    push('(');
    strcat(infix,")");
    i = 0, j = 0;
    item = infix[i];

    
    while(item != '\0'){

        if(item == '('){
            push(item);
        }

        else if(isdigit(item) || isalpha(item)){
            postfix[j++] = item;
        }

        else if(is_operator(item) == 1){
            
            x = pop();
            while(is_operator(x) == 1 && precedence(x) >= precedence(item)){
                postfix[j++] = x;
                x = pop();
            }
            push(x);

            push(item);
        }
        else if(item == ')'){
            x = pop();
            while(x != '('){
                postfix[j++] = x;
                x = pop();
            }
        }
        else{
            printf("Invaild Infix notation \n");
        }
        i++;

        item = infix[i];

    }
    if(top > 0 ){
        printf("Invaild Infix notation \n");
        return;
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter the Infix Notation\n");
    gets(infix);

    
   InfixtoPostfix(infix,postfix);

    printf("The Postfix Notation is :  ");
    printf("%s",postfix);

    return 0;
}
