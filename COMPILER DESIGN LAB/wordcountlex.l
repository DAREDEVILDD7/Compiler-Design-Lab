%{
int count = 0;
%}
%%
[a-z][a-z0-9]* ++count;
%%
int main()
{
yyin = fopen("input.txt", "r");
yylex();
printf("Count of words: %d", count);
}

int yywrap()
{
return 1;
}

/*
```` OUTPUT ````
<<Input File (input.txt)>>
This is a sample input file for displaying the number of words
_____________________________________________________
_____________________________________________________
Count of words: 12
*/