%{
#include <stdio.h>
%}
%token NUMBER ID
%left '+''-'
%left '*''/'
%left ')''('
%%
E:T {
printf("Arithmetic Expression is valid");
return 0;
}
T: T'+'T{$$=$1+$3;}
|T'-'T{$$=$1-$3;}
|T'*'T{$$=$1*$3;}
|T'/'T{$$=$1/$3;}
|T'%'T{$$=$1%$3;}
| '-' NUMBER {$$=-$2;}
| '-' ID {$$=-$2;}
| '('T')' {$$=$2;}
| NUMBER {$$=$1;}
| ID {$$=$1;};
%%
int main()

{
printf("\n Enter the expression: ");
yyparse();
}
int yyerror(char *s){
printf("\n Expression is invalid ");
}

/*
```` OUTPUT ````
Enter the expression: 24/(2*(2+2))
Arithmetic Expression is valid

*/