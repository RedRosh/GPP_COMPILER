#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"

static char *token_str[] = {"TOKEN_INTERFACE",
                            "TOKEN_INPUTFIELD",
                            "TOKEN_BUTTON",
                            "TOKEN_LABEL",
                            "TOKEN_SIZE",
                            "TOKEN_TEXT",
                            "TOKEN_ID",
                            "TOKEN_COLOR",
                            "TOKEN_POSITION",
                            "TOKEN_BORDER",
                            "TOKEN_BACKGROUND",
                            "TOKEN_WIDTH",
                            "TOKEN_HEIGHT",
                            "TOKEN_TEXTALIGN",
                            "TOKEN_BEGIN",
                            "TOKEN_END",
                            "TOKEN_START",
                            "TOKEN_PUT",
                            "TOKEN_INTLIT",
                            "TOKEN_STRING",
                            "TOKEN_OB",
                            "TOKEN_FB",
                            "TOKEN_PV",
                            "TOKEN_DP",
                            "TOKEN_COMMA",
                            "TOKEN_EOF",
                            "TOKEN_ERREUR"};

//* Errors
void logError(char *errorMessage)
{
    red();
    printf("[ Error ] : %s \n", errorMessage);
    reset();
}

//* Parser Logs
void log_parser_unexpected_token(int token_type)
{
    red();
    printf("[ Parser ] Expected token ");
    blue();
    printf(" %s ", token_str[token_type]);
    red();
    printf(": , got  < ");
    blue();
    printf("%s , %s ", token_str[Token->type], Token->value);
    red();
    printf(" >, Line : ");
    blue();
    printf("% .2d  \n ", Line);
}
//* Lexer Logs
void logCurrentToken()
{
    switch (Token->type)
    {
    case TOKEN_ERREUR:
    {
        red();
        printf("[ Lexer ] : ");
        printf("Unexpected Token");
        blue();
        printf(" %s", Token->value);
        red();
        printf(" at Line  ");
        blue();
        printf("%d . \n ", Line);
        break;
    }
    case TOKEN_EOF:
    {
        green();
        printf("[ TOKEN ] : reaching the End Of the File \n");
        break;
    }
    default:
    {
        blue();
        printf("[ Lexer ] : ");
        yellow();
        printf("the current token , type : ");
        blue();
        printf("%s", token_str[Token->type]);
        yellow();
        printf(" , value : ");
        blue();
        printf(" %s  \n ", Token->value);
    }
    }
    reset();
}