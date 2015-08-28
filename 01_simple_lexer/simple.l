%{
#include <stdio.h>
%}
%%

"hello world"                   { fprintf(yyout, "Why, hello yourself!\n"); }
 .                              { ; } /* a default pattern. Matches any character not caught by the above rules */

%%
int yywrap() {
    return 1;
}