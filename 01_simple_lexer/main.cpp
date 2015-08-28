#include <cstdio>

extern FILE* yyin;      /* file handle to a file to parse. Defined by lex */
extern FILE* yyout;     /* file handle to an output file */
extern "C" int yylex(); /* function that starts the tokenization of the input file */

int main() {
#if USE_FILES
    yyin = fopen("testinput.txt", "r");
    if (yyin == NULL) {
        fprintf(stderr, "Could not open file for reading\n");
        return 1;
    }
    yyout = fopen("output.txt", "w");
#else
    yyin = stdin;
    yyout = stdout;
#endif

    return yylex(); // Start the parser
}