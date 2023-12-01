keywords "void"|"int"
function "printf"|"main"
string \".*\"
identifiers [A-Za-z][0-9]*
arithmeticoperators [+|-|*|/|=]
relationaloperators [<|>]
punctuators [(|)|{|}|[|]|;|,|.]
%%
{keywords} printf("%s: Keyword\n",yytext);
{function} printf("%s: Function\n",yytext);
{string} printf("%s: String\n",yytext);
{identifiers} printf("%s: Identifier\n",yytext);
{arithmeticoperators} printf("%s: Arithmeticoperator\n",yytext);
{relationaloperators} printf("%s: Relationaloperator\n",yytext);
{punctuators} printf("%s: Punctuators\n",yytext);
%%
int main()
{
yyin = fopen("prod.c","r");
yylex();
}
int yywrap()
{
return 1;
}

/*

```` OUTPUT ````
<<Input File (prod.c)>>
void main()
{
int a,b,p;
p = a*b;
if (p<0)
printf("Product is negative");
printf("Product is: %d",s);
}
______________________________________________
_____________________________________________________
void: Keyword
main: Function
(: Punctuators
): Punctuators

{: Punctuators

int: Keyword
a: Identifier
,: Punctuators
b: Identifier
,: Punctuators
p: Identifier
;: Punctuators

p: Identifier
=: Arithmeticoperator
a: Identifier
*: Arithmeticoperator
b: Identifier

;: Punctuators

i: Identifier
f: Identifier
(: Punctuators
p: Identifier
<: Relationaloperator
0): Punctuators

printf: Function
(: Punctuators
"Product is negative": String
): Punctuators
;: Punctuators

printf: Function
(: Punctuators
"Product is: %d": String
,: Punctuators
s: Identifier
): Punctuators
;: Punctuators

}: Punctuators

*/