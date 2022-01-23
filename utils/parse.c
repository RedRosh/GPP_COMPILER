#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"

static TOKEN *tempToken;

void parser_parse()
{
    tempToken = calloc(1, sizeof(TOKEN));
    lexer_get_next_token();
    Program();
}

bool parser_eat(int token_type)
{
    if (Token->type == TOKEN_ERREUR)
    {
        logCurrentToken();
        exit(1);
    }
    if (Token->type != token_type)
    {
        log_parser_unexpected_token(token_type);
        exit(1);
    }
    lexer_get_next_token();

    return true;
}

Program()
{
}