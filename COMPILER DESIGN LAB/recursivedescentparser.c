#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
char str[100];
char p[1];
int i;
void B()
{
if(str[i]=='b')
{
printf("\n Match Found: 'b'");
i++;
B();
}
else
return;
}
void A()
{
if(str[i]=='a')
{
printf("\n Match Found: 'a'");
i++;
if(str[i]=='a')
{
printf("\n Match Found: 'a'");
i++;
A();
}
else
{
i--;
}
}
else
return;
}
void S()
{
if(str[i]=='a')
{
printf("\n Match Found: 'a'");
i++;
if(str[i]=='a')
{
printf("\n Match Found: 'a'");
i++;

}
else
{
i--;
return;
}
}
else
{
i--;
}
A();
B();
}

void main()
{
p[0]='$';
int o;
do{
printf("\n Enter the string to be parsed: ");
scanf("%s",str);
strcat(str,p);
puts(str);
printf("\n ||||\tParsing\t||||\n");
i=0;
S();
if(str[i]=='$')
{
printf("\nParsing successfully completed ");
}
else
{
printf("\n Parsing Failed");
}
printf("\n Do you want to parse another string?\n1.Yes\n2.No\n");
scanf("%d",&o);
}while(o!=2);
}
/*
```` OUTPUT ````
Enter the string to be parsed: aaaab
aaaab$
|||| Parsing ||||
Match Found: 'a'
Match Found: 'a'
Match Found: 'a'
Match Found: 'a'
Match Found: 'b'
Parsing successfully completed
Do you want to parse another string?
1.Yes

2.No
1
Enter the string to be parsed: aaab
aaab$
|||| Parsing ||||
Match Found: 'a'
Match Found: 'a'
Match Found: 'a'
Parsing Failed
Do you want to parse another string?
1.Yes
2.No
2

*/