%{
int flag = 0;
%}

%%

[aeiouAEIOU][a-zA-Z0-9.]+  flag = 1;
[a-zA-Z0-9]+

%%

int main()
{
    yylex();
    if (flag == 1)
        printf("Accepted\n");
    else
        printf("Not Accepted\n");
    return 0;
}

lex vowel.l
cc lex.yy.c -ll
./a.out
