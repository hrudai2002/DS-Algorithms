#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define Max 101
char op[Max];
int top1 = -1;

int val[Max];
int top2 = -1;

void push1(char ch){
  top1 += 1;
  op[top1] = ch;
}

void push2(int elem){
  top2 += 1;
  val[top2] = elem;
}

void pop1(){
  top1 -= 1;
}

void pop2(){
  top2 -= 1;
}

int prece(char ch){
  if(ch == '^') return 3;
  if(ch == '*' || ch == '/') return 2;
  if(ch == '+' || ch == '-') return 1;
  return 0;
}

int applyon(int a,int b,char ch){
  if(ch == '+') return a + b;
  if(ch == '*') return a * b;
  if(ch == '-') return a - b;
  if(ch == '/') return a / b;
}
int main(){
  char str[Max];
   scanf("%s",str);
  int i = 0;
  while(str[i] != '\0'){
      char ch = str[i];

      if(ch == '(') push1(ch);
      
      else if(isdigit(ch)){
        int val = 0;

        while(str[i] != '\0' && isdigit(str[i])){
            val = val*10 + (str[i] - '0');
            i++;
        }
        
        push2(val);
        i -= 1;
      }

      else if(ch == ')'){
        
        while(top1 > -1 && op[top1] != '('){
             int val2 = val[top2];
              pop2();

              int val1 = val[top2];
              pop2();
              
              char c = op[top1];
              pop1();

              push2(applyon(val1,val2,c));
        }
        if(top1 > -1) pop1();

      }

      else{
        while(top1 > -1 && prece(op[top1]) > prece(ch)){
              int val2 = val[top2];
              pop2();

              int val1 = val[top2];
              pop2();
              
              char c = op[top1];
              pop1();

              push2(applyon(val1,val2,c));
        }
        push1(ch);
      }

      i += 1;
  }
  while(top1 > -1){
              int val2 = val[top2];
              pop2();

              int val1 = val[top2];
              pop2();
              
              char c = op[top1];
              pop1();

              push2(applyon(val1,val2,c));
    
  }

  printf("%d",val[top2]);
  

}
