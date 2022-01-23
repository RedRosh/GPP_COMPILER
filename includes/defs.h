#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "lexer.h"
#include "parser.h"

typedef struct
{
    char c;

} Lexer;

typedef struct
{
    enum
    {
        TOKEN_INTERFACE,
        TOKEN_INPUTFIELD,
        TOKEN_BUTTON,
        TOKEN_LABEL,
        TOKEN_SIZE,
        TOKEN_TEXT,
        TOKEN_ID,
        TOKEN_COLOR,
        TOKEN_POSITION,
        TOKEN_BORDER,
        TOKEN_BACKGROUND,
        TOKEN_WIDTH,
        TOKEN_HEIGHT,
        TOKEN_TEXTALIGN,
        TOKEN_BEGIN,
        TOKEN_END,
        TOKEN_START,
        TOKEN_PUT,
        TOKEN_INTLIT,
        TOKEN_STRING,
        TOKEN_OB,
        TOKEN_FB,
        TOKEN_PV,
        TOKEN_DP,
        TOKEN_COMMA,
        TOKEN_EOF,
        TOKEN_ERREUR
    } type;
    char *value;
} TOKEN;
