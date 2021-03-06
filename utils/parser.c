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
void update_token()
{
    tempToken->type = Token->type;
    tempToken->value = calloc(strlen(Token->value) + 1, sizeof(char));
    strcpy(tempToken->value, Token->value);
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
    success = true;
    update_token();
    lexer_get_next_token();
    return success;
}

void Program()
{

    Widgets();
    getAllWidgets();
    convert_widget_to_gtk_widget();
    generateCssFile();
    parser_eat(TOKEN_BEGIN);
    Operations();
    getAllOperations();
    parser_eat(TOKEN_END);
    logSuccessParser("the file is well written");
    executeQuery();
}

void Widgets()
{
    do
    {
        widget_init();
        widget();
        addWidgetToList();
        widget_clean();
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
        widget_set_type();
        lexer_get_next_token();
        parser_eat(TOKEN_IDENTIFICATEUR);
        widget_set_id(tempToken->value);
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
    case TOKEN_FONTSIZE:
    case TOKEN_FONTSTYLE:
    case TOKEN_FONTWEIGHT:
    case TOKEN_BACKGROUNDCOLOR:
    case TOKEN_LETTERSPACING:
    case TOKEN_TEXTDECORATIONLINE:
    case TOKEN_TEXTDECORATIONSTYLE:
    case TOKEN_MARGINTOP:
    case TOKEN_MARGINLEFT:
    case TOKEN_MARGINRIGHT:
    case TOKEN_MARGINBOTTOM:
    case TOKEN_PADDINGTOP:
    case TOKEN_PADDINGLEFT:
    case TOKEN_PADDINGRIGHT:
    case TOKEN_PADDINGBOTTOM:
    case TOKEN_MINWIDTH:
    case TOKEN_MINHEIGHT:
    case TOKEN_BORDERWIDTH:
    case TOKEN_BORDERRADIUS:
    case TOKEN_BORDERSTYLE:
    case TOKEN_BORDERCOLOR:
    case TOKEN_BACKGROUND:
    case TOKEN_BORDER:
    case TOKEN_COLOR:
    case TOKEN_POSITION:
    case TOKEN_SIZE:
    case TOKEN_TITLE:
    case TOKEN_OPACITY:
    case TOKEN_ANGLE:
    case TOKEN_XALIGN:
    case TOKEN_PLACEHOLDER:
    case TOKEN_YALIGN:
    case TOKEN_MAXLENGTH:
    {
        int TOKEN_PROP = Token->type;
        lexer_get_next_token();
        parser_eat(TOKEN_DP);
        attribute();
        widget_set_property(TOKEN_PROP);
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
        operation_init();
        Operation();
        parser_eat(TOKEN_PV);
        addOperationToList();
        clean_operation();
    } while (Token->type != TOKEN_END && Token->type != TOKEN_EOF);
}
void Operation()
{
    switch (Token->type)
    {

    case TOKEN_START:
    case TOKEN_PUT:
    case TOKEN_SHOW:
    case TOKEN_DESTROY:
    {
        set_operation_type();
        lexer_get_next_token();
        parser_eat(TOKEN_IDENTIFICATEUR);
        set_operation_id(tempToken->value);
        params();
        break;
    }
    case TOKEN_SLEEP:
    {
        set_operation_type();
        lexer_get_next_token();
        params();
        break;
    }
    default:
    {
        logErrorParser("Invalid Operation");
        exit(1);
    };
    }
}

params()
{
    switch (Token->type)
    {
    case TOKEN_STRING:
    {
        set_query_params(Token->value);
        lexer_get_next_token();
        break;
    }
    case TOKEN_INTLIT:
    {
        int x = atoi(Token->value);
        lexer_get_next_token();
        switch (Token->type)
        {
        case TOKEN_INTLIT:
        {
            parser_eat(TOKEN_INTLIT);
            set_position_params(x, atoi(tempToken->value));
            break;
        }
        case TOKEN_PV:
        {
            set_sleep_params(x);
            break;
        }
        }
        break;
    }
    case TOKEN_PV:
    {
        check_operation();
        break;
    }
    default:
    {
        logErrorParser("Invalid params");
        exit(1);
    }
    }
}
