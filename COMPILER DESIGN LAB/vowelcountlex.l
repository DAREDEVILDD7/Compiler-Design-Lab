%{
int count = 0;
%}
%%
[AEIOU]* |
[aeiou] ++count;
%%
int main()
{
yyin = fopen("input.txt", "r");
yylex();
printf("Count of Vowels: %d", count);
}

int yywrap()
{
return 1;
}
/*
```` OUTPUT ````
<<Input File (input.txt)>>
Hey There How Are You
_____________________________________________________
_____________________________________________________
Count of Vowels: 8
*/