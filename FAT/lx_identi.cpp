/*lex code to determine whether input is an identifier or not*/
% {
#include <stdio.h>
	%
}

	/ rule section % %
	// regex for valid identifiers
	^[a - z A - Z _][a - z A - Z 0 - 9 _] * printf("Valid Identifier");

// regex for invalid identifiers
^[^a - z A - Z _] printf("Invalid Identifier");
.;
% %

	main()
{
	yylex();
}


lex gfg.l
cc lex.yy.c - lfl
•/a.out
