#include "./includes/defs.h"
#define _extern
#include "./includes/data.h"
#undef _extern
#include "./includes/dcl.h"

void main(int argc, char *argv[])
{
    if (argc != 2)
    {
        logError("Please insert a file");
        exit(1);
    }
    if ((inFile = fopen(argv[1], "r")) == NULL)
    {
        logError("Could Not open the file");
        exit(1);
    }
    init();
    do
    {
        lexer_get_next_token();
        logCurrentToken();
    } while (Token->type != TOKEN_EOF);
}