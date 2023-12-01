#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct la
{
char lex[100];
char name[100];
int did;
}ptr[100],id1[100];
void main()
{
int k=0,j=0,count=0,condition;
char buf[100],buf2[100];
FILE *fp1;
fp1=fopen("file1.txt","r");
fgets(buf,100,fp1);
while(!feof(fp1))
{
int fp=0,lb=0,flag=1;
printf("\nString is:%s\n",buf);
q1: flag=1;
if(buf[fp]=='i')
{
fp++;
goto q7;
}
else if(buf[fp]=='f')
{
fp++;
goto q12;
}
else if(isalpha(buf[fp]))
{
fp++;
goto q2;
}
else if(buf[fp]=='=')
{
fp++;
goto q21;
}
q2: if(isalpha(buf[fp]) || isdigit(buf[fp]))
{
fp++;
goto q2;
}
else goto q3;
q3: if(buf[fp]== ' ' || buf[fp]==';' || buf[fp]== '=' ||
buf[fp]=='>' || buf[fp]=='<' || buf[fp]==')' || buf[fp]=='+')
{
int count1=0,condition2=0;

if(buf[fp]=='+')
{
fp++;
goto q4;
}
else {
for(int a=0;a<100;a++)
{
buf2[a]=0;
}
for(int i=0,j=lb;j<fp;i++,j++)
{
count1++;
if(isdigit(buf[j]))
{
condition+=1;
}
else condition=0;
buf2[i]=buf[j];
}
strcpy(ptr[k].lex,buf2);
for(int l=0;l<=count;l++)
{
if(strcmp(ptr[k].lex,id1[l].name)==0)
{
printf("herre\n\n");
flag=0;
break;
}
}
if(condition==count1)
{
condition2=1;
}
if(flag==1 && condition2==0)
{
strcpy(id1[j].name,ptr[k].lex);
count++;
j++;
}
if(condition2==0)
printf("Identifier:%s\n",ptr[k].lex);
else
printf("Number:%s\n",ptr[k].lex);
k++;
for(int a=0;a<100;a++)
{
buf2[a]=0;
}
if(buf[fp]!=' ')
{
for(int i=0,j=fp;j<=fp;i++,j++)
{
buf2[i]=buf[j];
}

strcpy(ptr[k].lex,buf2);
if(buf[fp]!=';')
{
printf("Operator: %s\n",ptr[k].lex);
}
else
{
printf("Delimiter: %s\n",ptr[k].lex);
}
}
fp++;
lb=fp;
goto q1;
}
}
q4: if(buf[fp]=='+')
{
fp++;
goto q5;
}
q5: if(buf[fp]== ' ' || buf[fp]==';' || buf[fp]== '=' ||
buf[fp]=='>' || buf[fp]=='<' || buf[fp]==')' || buf[fp]=='+')
{
for(int a=0;a<100;a++)
{
buf2[a]=0;
}
for(int i=0,j=lb+1;j<fp;i++,j++)
{
buf2[i]=buf[j];
}
strcpy(ptr[k].lex,buf2);
printf("%s\n",ptr[k].lex);
k++;
for(int a=0;a<100;a++)
{
buf2[a]=0;
}
if(buf[fp]='+')
{
printf("Increment operator: ++\n");
}
else if(buf[fp]!=' ')
{
for(int i=0,j=fp;j<=fp;i++,j++)
{
buf2[i]=buf[j];
}
strcpy(ptr[k].lex,buf2);
printf("%s\n",ptr[k].lex);
}
fp++;
lb=fp;
goto q1;
}
q7: if(buf[fp]=='n')

{
fp++;
goto q10;
}
else if(buf[fp]=='=' || buf[fp]==')' || buf[fp]=='>' || buf[fp]=='<'
|| buf[fp]=='+'
)
goto q3;
else goto q8;
q8:if(buf[fp]=='f')
{
fp++;
goto q11;
}
q10:if(buf[fp]=='t')
{
fp++;
goto q11;
}
q11:if( buf[fp]=='(' || buf[fp]==' ')
{
for(int a=0;a<100;a++)
{
buf2[a]=0;
}
for(int i=0,j=lb;j<fp;i++,j++)
{
buf2[i]=buf[j];
}
strcpy(ptr[k].lex,buf2);
printf("Keyword: %s\n",ptr[k].lex);
k++;
for(int a=0;a<100;a++)
{
buf2[a]=0;
}
if(buf[fp]!=' ')
{
for(int i=0,j=fp;j<=fp;i++,j++)
{
buf2[i]=buf[j];
}
strcpy(ptr[k].lex,buf2);
printf("Paranthesis: %s\n",ptr[k].lex);
}
fp++;
lb=fp;
goto q1;
}
q12:if(buf[fp]=='o')
{
fp++;
goto q13;
}
else if(buf[fp]=='l')
{

fp++;
goto q23;
}
q13:if(buf[fp]=='r')
{
fp++;
goto q11;
}
q15:if(buf[fp]== '(')
{
for(int a=0;a<100;a++)
{
buf2[a]=0;
}
for(int i=0,j=lb;j<fp;i++,j++)
{
buf2[i]=buf[j];
}
strcpy(ptr[k].lex,buf2);
printf("%s\n",ptr[k].lex);
k++;
for(int a=0;a<100;a++)
{
buf2[a]=0;
}
for(int i=0,j=fp;j<=fp;i++,j++)
{
buf2[i]=buf[j];
}
strcpy(ptr[k].lex,buf2);
printf("Paranthesis: %s\n",ptr[k].lex);
fp++;
lb=fp;
goto q1;
}
q21:if(buf[fp]=='=')
{
fp++;
goto q22;
}
else goto q22;
q22:if(buf[fp]== ' ' || buf[fp]==';')
{
for(int a=0;a<100;a++)
{
buf2[a]=0;
}
if(buf[fp]!=' ')
{
for(int i=0,j=fp;j<=fp;i++,j++)
{
buf2[i]=buf[j];
}
strcpy(ptr[k].lex,buf2);
printf("%s\n",ptr[k].lex);
}

fp++;
lb=fp;
goto q1;
}
q23: if(buf[fp]=='o')
{
fp++;
goto q24;
}
q24: if(buf[fp]=='a')
{
fp++;
goto q25;
}
q25: if(buf[fp]=='t')
{
fp++;
goto q11;
}
fgets(buf,100,fp1);
}
printf("\nIdentifier\t ID\n");
for(int l=0;l<count;l++)
{
printf("\n%s\t\t id%d ",id1[l].name,l+1);
}
printf("\n");
}
/*
```` OUTPUT ````
<<Input File (file1.txt)>>
int b=10;
for(int i=0;i<n;i++)
{
if(b>i)
{
int abc2;
printf("Hello");
}
float d;
}
_____________________________________________________
_____________________________________________________
String is:int b=10;
Keyword: int
Identifier:b
Operator: =
Number:10
Delimiter: ;
String is:for(int i=0;i<n;i++)

Keyword: for
Paranthesis: (
Keyword: int
Identifier:i
Operator: =
Number:0
Delimiter: ;
herre
Identifier:i
Operator: <
Identifier:n
Delimiter: ;
++
Increment operator: ++
String is:{
String is:if(b>i)
Keyword: if
Paranthesis: (
herre
Identifier:b
Operator: >
herre
Identifier:i
Operator: )
String is:{
String is:int abc2;
Keyword: int
Identifier:abc2
Delimiter: ;
String is:printf("Hello");
Keyword: printf
Paranthesis: (
String is:}
String is:float d;
Keyword: float
Identifier:d
Delimiter: ;
String is:

String is:}
Identifier ID
b id1
i id2
n id3
abc2 id4
d id5

*/