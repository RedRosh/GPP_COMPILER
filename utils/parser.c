#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"

void parser_parse()
{
    lexer_get_next_token();
    Program();
}

bool parser_eat(int token_type)
{
    bool success = true;
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
    else
    {
        success = true;
    }
    lexer_get_next_token();
    return success;
}

void Program()
{
    Widgets();
    parser_eat(TOKEN_BEGIN);
    Operations();
    parser_eat(TOKEN_END);
    logSuccessParser("the file is well written");
}

void Widgets()
{
    do
    {
        widget();
    } while (Token->type != TOKEN_BEGIN && Token->type != TOKEN_EOF);
}

void widget()
{
    switch (Token->type)
    {
    case TOKEN_INTERFACE:
    case TOKEN_BUTTON:
    case TOKEN_LABEL:
    case TOKEN_INPUTFIELD:
    {
        lexer_get_next_token();
        parser_eat(TOKEN_IDENTIFICATEUR);
        parser_eat(TOKEN_DP);
        parser_eat(TOKEN_OB);
        Props();
        parser_eat(TOKEN_FB);
        parser_eat(TOKEN_PV);
        break;
    }
    default:
    {
        logErrorParser("invalid  widget");
        exit(1);
    }
    }
}

void Props()
{
    do
    {
        if (TOKEN_COMMA == Token->type)
        {
            lexer_get_next_token();
        }
        prop();
    } while (Token->type == TOKEN_COMMA);
}
void prop()
{
    switch (Token->type)
    {
    case TOKEN_WIDTH:
    case TOKEN_HEIGHT:
    case TOKEN_ID:
    case TOKEN_TEXT:
    case TOKEN_TEXTALIGN:
    case TOKEN_BACKGROUND:
    case TOKEN_BORDER:
    case TOKEN_COLOR:
    case TOKEN_POSITION:
    case TOKEN_SIZE:
    {
        lexer_get_next_token();
        parser_eat(TOKEN_DP);
        attribute();
        lexer_get_next_token();
        break;
    }
    case TOKEN_FB:
    {
        logErrorParser("Don't put comma in the last prop");
        exit(1);
    }
    default:
    {
        log_parser_unexpected_token_prop();
        exit(1);
    }
    }
}

void attribute()
{
    switch (Token->type)
    {
    case TOKEN_STRING:
    case TOKEN_INTLIT:
    {
        break;
    }
    default:
    {
        log_parser_unexpected_token_attribute();
        exit(1);
    }
    }
}

void Operations()
{
    do
    {
        if (TOKEN_PV == Token->type)
        {
            lexer_get_next_token();
        }
        Operation();
        parser_eat(TOKEN_PV);
    } while (Token->type != TOKEN_END && Token->type != TOKEN_EOF);
}
void Operation()
{
    switch (Token->type)
    {
    case TOKEN_START:
    {
        Start();
        break;
    }
    case TOKEN_PUT:
        Put();
        break;
    default:
    {
        logErrorParser("Invalid Operation");
        exit(1);
    };
    }
}
void Start()
{
    lexer_get_next_token();
    parser_eat(TOKEN_IDENTIFICATEUR);
}
void Put()
{
    lexer_get_next_token();
    parser_eat(TOKEN_IDENTIFICATEUR);
    parser_eat(TOKEN_INTLIT);
    parser_eat(TOKEN_INTLIT);
}
