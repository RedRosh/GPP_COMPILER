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
                            "TOKEN_OPACITY",
                            "TOKEN_TITLE",
                            "TOKEN_ANGLE",
                            "TOKEN_XALIGN",
                            "TOKEN_YALIGN",
                            "TOKEN_PLACEHOLDER",
                            "TOKEN_MAXLENGTH",
                            "TOKEN_BEGIN",
                            "TOKEN_END",
                            "TOKEN_START",
                            "TOKEN_PUT",
                            "TOKEN_SHOW",
                            "TOKEN_DESTROY",
                            "TOKEN_SLEEP",
                            "TOKEN_INTLIT",
                            "TOKEN_STRING",
                            "TOKEN_OB",
                            "TOKEN_FB",
                            "TOKEN_PV",
                            "TOKEN_DP",
                            "TOKEN_COMMA",
                            "TOKEN_EOF",
                            "TOKEN_ERREUR",
                            "TOKEN_IDENTIFICATEUR"};
static char *widget_type_str[] = {"INPUTFIELD_TYPE",
                                  "LABEL_TYPE",
                                  "BUTTON_TYPE",
                                  "INTERFACE_TYPE"};
static char *operation_type_str[] = {
    "START_TYPE",
    "SHOW_TYPE",
    "PUT_TYPE",
    "DESTROY_TYPE",
    "SLEEP_TYPE"};
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
    printf(" , got  < ");
    blue();
    printf("%s ", token_str[Token->type]);
    red();
    printf(" , ");
    blue();
    printf(" %s ", Token->value);
    red();
    printf(" >, Line : ");
    blue();
    printf("% .2d  \n ", Line);
    reset();
}
void log_parser_unexpected_token_attribute()
{
    red();
    printf("[ Parser ] Attribute Error : Expected token ");
    blue();
    printf(" %s OR %s", token_str[TOKEN_STRING], token_str[TOKEN_INTLIT]);
    red();
    printf(" , got  < ");
    blue();
    printf("%s ", token_str[Token->type]);
    red();
    printf(" , ");
    blue();
    printf(" %s ", Token->value);
    red();
    printf(" >, Line : ");
    blue();
    printf("% .2d  \n ", Line);
    reset();
}
void log_parser_unexpected_token_prop()
{
    red();
    printf("[ Parser ] Prop Error : Expected a Prop ");

    red();
    printf(" , got  < ");
    blue();
    printf("%s ", token_str[Token->type]);
    red();
    printf(" , ");
    blue();
    printf(" %s ", Token->value);
    red();
    printf(" >, Line : ");
    blue();
    printf("% .2d  \n ", Line);
    reset();
}
void logErrorParser(char *message)
{
    red();
    printf("[ Parser ] : %s at the line :  %.2d \n", message, Line);
    reset();
}
void logSuccessParser(char *message)
{
    green();
    printf("[ Parser ] : %s \n", message);
    reset();
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

//* Semantic logs
void logSemantic(char *message)
{
    blue();
    printf("[ Semantic ] : ");
    yellow();
    printf("%s \n", message);
    reset();
}
void logPropertiesStringSemantic(char *prop, char *attribute)
{
    if (attribute != NULL)
    {
        blue();
        printf("\t\t\t %s ", prop);
        yellow();
        printf(": ");
        cyan();
        printf("%s", attribute);
        yellow();
        printf(" ; \n");
        reset();
    }
}
void logPropertiesIntegerSemantic(char *prop, int attribute)
{
    if (attribute != -1)
    {
        blue();
        printf("\t\t\t %s ", prop);
        yellow();
        printf(": ");
        cyan();
        printf("%d", attribute);
        yellow();
        printf(" ; \n");
        reset();
    }
}
void logPropDoesntBelongToWidget(int token_prop, int widget_type)
{
    red();
    printf("[ Semantic ] : ");
    printf(" this prop ");
    cyan();
    printf("%s ", token_str[token_prop]);
    red();
    printf("Does not belong to this Widget type ");
    cyan();
    printf("%s ", widget_type_str[widget_type]);
    red();
    printf("at Line : ");
    yellow();
    printf("%d \n", Line);
    reset();
}

void logSemanticError(char *message)
{
    red();
    printf("[ Semantic ] : %s at Line :", message);
    yellow();
    printf(" %d \n", Line);
    reset();
}
void logCurrentWidget(WIDGET *widget)
{
    logSemantic("The Current widget :");
    logPropertiesStringSemantic("Id", widget->id);
    logPropertiesStringSemantic("Type", widget_type_str[widget->widgetType]);
    logPropertiesIntegerSemantic("Height", widget->height);
    logPropertiesIntegerSemantic("Width", widget->width);
    logPropertiesIntegerSemantic("Opacity", widget->opacity);
    switch (widget->widgetType)
    {
    case INTERFACE_TYPE:
    {
        logPropertiesStringSemantic("Title", widget->type.interface->title);
        break;
    }
    case BUTTON_TYPE:
    {
        logPropertiesStringSemantic("Text", widget->type.button->text);
        break;
    }
    case LABEL_TYPE:
    {
        logPropertiesStringSemantic("Text", widget->type.label->text);
        logPropertiesIntegerSemantic("Xalign", widget->type.label->xalign);
        logPropertiesIntegerSemantic("Yalign", widget->type.label->yalign);
        logPropertiesIntegerSemantic("Angle", widget->type.label->angle);
        break;
    }
    case INPUTFIELD_TYPE:
    {
        logPropertiesStringSemantic("Text", widget->type.inputField->text);
        logPropertiesStringSemantic("PlaceHolder", widget->type.inputField->placeholder);
        logPropertiesIntegerSemantic("MaxLength", widget->type.inputField->maxlength);
        break;
    }
    }
}

//* OPERATIONS LOGS
void logOperationNeedParams(int operation_type)
{
    red();
    printf("[ Semantic ] : this operation of type");
    blue();
    printf(" %s", operation_type_str[operation_type]);
    red();
    printf(" needs params at Line :");
    yellow();
    printf(" %d \n", Line);
    reset();
}

void logCurrentOperation(OPERATION *operation)
{
    logSemantic("The Current Operation :");
    logPropertiesStringSemantic("type", operation_type_str[operation->OperationType]);
    switch (operation->OperationType)
    {
    case START_TYPE:
    {
        logPropertiesStringSemantic("id_widget", operation->id_widget);
        logPropertiesStringSemantic("query", operation->params.query);
        break;
    }
    case PUT_TYPE:
    {
        logPropertiesStringSemantic("id_widget", operation->id_widget);
        logPropertiesIntegerSemantic("x", operation->params.position->x);
        logPropertiesIntegerSemantic("y", operation->params.position->y);
        break;
    }
    case SLEEP_TYPE:
    {
        logPropertiesIntegerSemantic("sleep", operation->params.sleep);
        break;
    }
    default:
    {
        logPropertiesStringSemantic("id_widget", operation->id_widget);
        logPropertiesStringSemantic("Info", "No Params for this operation");
    }
    }
}