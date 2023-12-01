#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int i,j,k;
int d=0;
int n;
char productions[10][10];
char stack[50],input[50];
void check();
int main()
{
printf("\n Enter the number of productions: \n");
scanf("%d",&n);
printf("\n Enter the productions (e.g., E->E+T):\n");
for(i=0;i<n;i++)
{
scanf("%s",productions[i]);
}
printf("\n Enter input string:\n");
scanf("%s",input);
printf("\n%-20s%-20s%-20s\n","Stack","Input","Action");
strcpy(stack,"$");
strcat(input,"$");
i=1;
j=0;
while(input[j]!='$' || strcmp(stack,"$S")!=0)
{
d++;
if(d<75)
{
check();
}
else
goto l1;
}
if(strcmp(stack,"$S")==0)
{
printf("\n%-20s%-20s%-20s\n\n",stack,input+j,"Accept");
printf("Success: Input string is parsed successfully.\n");
}
l1: if(d>70)
{
printf("\n Failure: Input string cannot be parsed ");
exit(0);
}
return 0;
}
void check()

{
for(k=0;k<n;k++)
{
int prodLen=strlen(productions[k])-3;
char *rhs=&productions[k][3];
if(i>=prodLen && strncmp(stack+i-prodLen,rhs,prodLen)==0)
{
stack[i-prodLen]=productions[k][0];
stack[i-prodLen+1]='\0';
i=i-prodLen+1;
printf("\n%-20s%-20s%s using
%s\n",stack,input+j,"Reduced",productions[k]);
return;
}
}
if(input[j]!='$')
{
stack[i]=input[j];
stack[i+1]='\0';
printf("\n%-20s%-20s%-20s\n",stack,input+j,"Shift");
i++;
j++;
}
}
/*
```` OUTPUT ````
Enter the number of productions:
4
Enter the productions (e.g., E->E+T):
S->(L)
S->a
L->L,S
L->S
Enter input string:
(a,(a,a))
Stack    Input      Action
$(       (a,(a,a))$ Shift
$(a        ,(a,a))$ Shift
$(S        ,(a,a))$ Reduced using S->a
$(L        ,(a,a))$ Reduced using L->S
$(L,        (a,a))$ Shift
$(L,(        a,a))$ Shift
$(L,(a        ,a))$ Shift
$(L,(S        ,a))$ Reduced using S->a
$(L,(L        ,a))$ Reduced using L->S
$(L,(L,        a))$ Shift
$(L,(L,a        ))$ Shift
$(L,(L,S        ))$ Reduced using S->a
$(L,(L          ))$ Reduced using L->L,S
$(L,(L)         ))$ Shift
$(L,S            )$ Reduced using S->(L)
$(L              )$ Reduced using L->L,S
$(L)              $ Shift
$S                $ Reduced using S->(L)
$S                $ Accept
Success: Input string is parsed successfully.
*/