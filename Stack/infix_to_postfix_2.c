#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Max 101
// Arithmetic Evaluation

char ar[Max];

int top = -1;


void push(char val){
  top += 1;
  ar[top] = val;
}

void pop(){
  top--;
}

int  prece(char ch){
  if(ch == '^') return 3;
  if(ch == '*' || ch == '/') return 2;
  if(ch == '+' || ch == '-') return 1;
  return -1;
}
int is_operator(char ch){
  if(ch == '*' || ch == '+' || ch == '-' || ch == '/' || ch == '^') return 1;
  else return 0;
}
int applyon(int a,int b,int ch){
  if(ch == '+') return a + b;
  if(ch == '-') return a - b;
  if(ch == '*') return a * b;
  if(ch == '/') return a / b;
}
int main(){

  char str[Max];
   scanf("%s",str);
  
  char ans[Max];
  int i = 0,j = 0;
  while(str[i] != '\0'){
      char ch = str[i];

      if(ch == '('){
        push(ch);
      }
      else if(isalpha(ch) || isdigit(ch)){
             ans[j] = ch;
             j += 1;
      }
      else if(ch == ')' && top > -1){
          
         while(ar[top] != '('){
           ans[j] = ar[top];
           j += 1;
           pop();
         }
         pop();
      }
      else{
             if(top == -1) push(ch);
             else {
                   if(prece(ar[top]) < prece(ch)) push(ch);
                   
                   else if(prece(ar[top]) > prece(ch)){
                        while(top > -1 && prece(ar[top]) >= prece(ch)){
                              ans[j] = ar[top];
                              pop();
                              j += 1;


                        }
                        push(ch);
                   }
                   else{
                       ans[j] = ar[top];
                       pop();
                       push(ch);
                       j += 1;
                   }
                   
             }
      }

      i += 1;
  }
 
  while(top > -1){
   
    ans[j] = ar[top];
    j += 1;
    top -= 1;
  }
  int start = 0;
  for(start = 0; start < j; ++start){
    printf("%c",ans[start]);
  }
  
  return 0;
  
}