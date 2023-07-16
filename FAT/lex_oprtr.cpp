%{
#include <stdio.h>
%}

%%
==      printf("Relational Operator: ==\n");
!=      printf("Relational Operator: !=\n");
<=      printf("Relational Operator: <=\n");
>=      printf("Relational Operator: >=\n");
<       printf("Relational Operator: <\n");
>       printf("Relational Operator: >\n");
if      printf("Keyword: if\n");
else    printf("Keyword: else\n");
while   printf("Keyword: while\n");
for     printf("Keyword: for\n");
int     printf("Keyword: int\n");
float   printf("Keyword: float\n");
char    printf("Keyword: char\n");
return  printf("Keyword: return\n");
%%
 
int main() {
    yylex();
    return 0;
}