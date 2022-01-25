#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <gtk/gtk.h>
#include "lexer.h"
#include "parser.h"
#include "widget.h"
#include "semantic.h"

typedef struct
{
    char c;

} Lexer;
typedef enum
{
    INPUTFIELD_TYPE,
    LABEL_TYPE,
    BUTTON_TYPE,
    INTERFACE_TYPE
} WidgetType;
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
        TOKEN_OPACITY,
        TOKEN_TITLE,
        TOKEN_ANGLE,
        TOKEN_XALIGN,
        TOKEN_YALIGN,
        TOKEN_PLACEHOLDER,
        TOKEN_MAXLENGTH,
        TOKEN_BEGIN,
        TOKEN_END,
        TOKEN_START,
        TOKEN_PUT,
        TOKEN_SHOW,
        TOKEN_DESTROY,
        TOKEN_SLEEP,
        TOKEN_INTLIT,
        TOKEN_STRING,
        TOKEN_OB,
        TOKEN_FB,
        TOKEN_PV,
        TOKEN_DP,
        TOKEN_COMMA,
        TOKEN_EOF,
        TOKEN_ERREUR,
        TOKEN_IDENTIFICATEUR,
    } type;
    char *value;
} TOKEN;

typedef struct
{
    char *title;

} INTERFACE;

typedef struct
{
    char *text;

} BUTTON;

typedef struct
{
    char *text;
    int xalign;
    int yalign;
    int angle;

} LABEL;

typedef struct
{
    int maxlength;
    char *placeholder;
    char *text;
} INPUTFIELD;

typedef struct WIDGET
{
    int height;
    WidgetType widgetType;
    int width;
    char *id;
    int opacity;
    union TYPE
    {
        INPUTFIELD *inputField;
        LABEL *label;
        BUTTON *button;
        INTERFACE *interface;
    } type;
} WIDGET;

typedef struct WIDGETNODE
{
    WIDGET *widget;
    struct WIDGETNODE *next;

} WIDGETNODE;

typedef struct GTKWIDGETNODE
{
    char *id;
    WidgetType widgetType;
    GtkWidget *gtk_widget;
    struct GTKWIDGETNODE *next;
} GTKWIDGETNODE;

typedef struct POSITION
{
    int x;
    int y;
} POSITION;

typedef enum OPERATIONTYPE
{
    START_TYPE,
    SHOW_TYPE,
    PUT_TYPE,
    DESTROY_TYPE,
    SLEEP_TYPE
} OPERATIONTYPE;

typedef struct OPERATION
{
    OPERATIONTYPE OperationType;
    char *id_widget;
    union
    {
        int sleep;
        char *query;
        POSITION *position;
    } params;
} OPERATION;

typedef struct OPERATIONNODE
{
    OPERATION *operation;
    struct OPERATIONNODE *next;
} OPERATIONNODE;