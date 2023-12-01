#include <stdio.h>
#include <string.h>
#include <ctype.h>
char input[100];
int ip = 0;
char postfix[100];
int pi = 0;
char stack[100];
int _top = -1;
char ti = '1';
void push(char c){
stack[++_top] = c;
}
char pop(){
return stack[_top--];
}
char top(){
return stack[_top];
}
int prec(char c){
switch(c){
case '(':return 0;
case '/':
case'*' :return 3;
case '+':
case '-':return 2;
case ')':return 1;
}
return -1;
}
int isop(char c){
return prec(c)!=-1;
}
int main(){
printf("Enter string: ");
scanf("%s",input);
int len = strlen(input);
input[len++]=')';
push('(');
while(ip<len){
char ic = input[ip];
if(isop(ic)){
while(ic!='(' && _top>-1 && prec(ic)<=prec(top())){
char c = pop();
postfix[pi++]=c;
}

ic == ')'? pop(): push(ic);
}
else{
postfix[pi++]=ic;
}
ip++;}
int ci = 0;
printf("\n Intermediate Code\n");
while (ci<pi){
char pc = postfix[ci];
if (isop(pc)){
char b=pop();
char a=pop();
printf("t%c=",ti);
isdigit(a)? printf("t%c",a): printf("%c",a);
printf("%c",pc);
isdigit(b)? printf("t%c",b): printf("%c",b);
printf("\n");
push(ti);
ti++;
}
else{
push(pc);
}
ci++;
}
return 0;
}
/*
```` OUTPUT ````
Enter string: a+b*(c-d)/(e+f)
Intermediate Code
t1=c-d
t2=b*t1
t3=e+f
t4=t2/t3
t5=a+t4
*/