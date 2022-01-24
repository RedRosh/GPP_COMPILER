#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"

void widget_init()
{
    Widget = calloc(1, sizeof(WIDGET));
    Widget->height = -1;
    Widget->width = -1;
    Widget->opacity = -1;
}
void widget_clean()
{
    free(Widget);
}

void widget_set_type()
{
    switch (Token->type)
    {
    case TOKEN_INTERFACE:
    {
        Widget->widgetType = INTERFACE_TYPE;
        Widget->type.interface = calloc(1, sizeof(INTERFACE));
        Widget->type.interface->title = NULL;
        break;
    }
    case TOKEN_BUTTON:
    {
        Widget->widgetType = BUTTON_TYPE;
        Widget->type.button = calloc(1, sizeof(BUTTON));
        Widget->type.button->text = NULL;
        break;
    }
    case TOKEN_LABEL:
    {
        Widget->widgetType = LABEL_TYPE;
        Widget->type.label = calloc(1, sizeof(LABEL));
        Widget->type.label->text = NULL;
        Widget->type.label->xalign = -1;
        Widget->type.label->yalign = -1;
        Widget->type.label->angle = -1;
        break;
    }
    case TOKEN_INPUTFIELD:
    {
        Widget->widgetType = INPUTFIELD_TYPE;
        Widget->type.inputField = calloc(1, sizeof(INPUTFIELD));
        Widget->type.inputField->text = NULL;
        Widget->type.inputField->placeholder = NULL;
        Widget->type.inputField->maxlength = -1;
        break;
    }
    }
}

void widget_set_id(char *token_id)
{

    if (!idExists(token_id))
    {
        Widget->id = malloc(strlen(token_id) * sizeof(char));
        strcpy(Widget->id, token_id);
    }
    else
    {
        logSemanticError("id widget already exists");
        exit(1);
    }
}

void widget_set_property(int token_prop)
{
    switch (token_prop)
    {
    case TOKEN_WIDTH:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("Width property is an integer ");
            exit(1);
        }
        Widget->width = atoi(Token->value);
        break;
    }
    case TOKEN_HEIGHT:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("Height property is an integer ");
            exit(1);
        }
        Widget->height = atoi(Token->value);
        break;
    }
    case TOKEN_OPACITY:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("Opacity property is an integer ");
            exit(1);
        }
        int opacity = atoi(Token->value);
        if (opacity > 100 || opacity < 0)
        {
            logSemanticError("Opacity is between 0 and 100 ");
            exit(1);
        }
        Widget->opacity = opacity;
        break;
    }
    default:
    {
        switch (Widget->widgetType)
        {
        case INTERFACE_TYPE:
        {
            switch (token_prop)
            {
            case TOKEN_TITLE:
            {
                if (Token->type != TOKEN_STRING)
                {
                    logSemanticError("Title property is a String ");
                    exit(1);
                }
                Widget->type.interface->title = malloc(strlen(Token->value) * sizeof(char));
                strcpy(Widget->type.interface->title, Token->value);
                break;
            }
            default:
            {
                logPropDoesntBelongToWidget(token_prop, Widget->widgetType);
                exit(1);
            }
            }
            break;
        }
        case LABEL_TYPE:
        {
            switch (token_prop)
            {
            case TOKEN_TEXT:
            {
                if (Token->type != TOKEN_STRING)
                {
                    logSemanticError("Text property is a String ");
                    exit(1);
                }
                Widget->type.label->text = malloc(strlen(Token->value) * sizeof(char));
                strcpy(Widget->type.label->text, Token->value);
                break;
            }
            case TOKEN_ANGLE:
            {
                if (Token->type != TOKEN_INTLIT)
                {
                    logSemanticError("Angle property is an Interger ");
                    exit(1);
                }
                Widget->type.label->angle = atoi(Token->value);
                break;
            }
            case TOKEN_XALIGN:
            {
                if (Token->type != TOKEN_INTLIT)
                {
                    logSemanticError("Xalign property is an Interger ");
                    exit(1);
                }
                Widget->type.label->xalign = atoi(Token->value);
                break;
            }
            case TOKEN_YALIGN:
            {
                if (Token->type != TOKEN_INTLIT)
                {
                    logSemanticError("Yalign property is an Interger ");
                    exit(1);
                }
                Widget->type.label->yalign = atoi(Token->value);
                break;
            }
            default:
            {
                logPropDoesntBelongToWidget(token_prop, Widget->widgetType);
                exit(1);
            }
            }
            break;
        }
        case BUTTON_TYPE:
        {
            switch (token_prop)
            {
            case TOKEN_TEXT:
            {
                if (Token->type != TOKEN_STRING)
                {
                    logSemanticError("Text property is a String ");
                    exit(1);
                }
                Widget->type.button->text = malloc(strlen(Token->value) * sizeof(char));
                strcpy(Widget->type.button->text, Token->value);
                break;
            }
            default:
            {
                logPropDoesntBelongToWidget(token_prop, Widget->widgetType);
                exit(1);
            }
            }
            break;
        }
        case INPUTFIELD_TYPE:
        {
            switch (token_prop)
            {
            case TOKEN_TEXT:
            {
                if (Token->type != TOKEN_STRING)
                {
                    logSemanticError("Text property is a String ");
                    exit(1);
                }
                Widget->type.inputField->text = malloc(strlen(Token->value) * sizeof(char));
                strcpy(Widget->type.inputField->text, Token->value);
                break;
            }
            case TOKEN_MAXLENGTH:
            {
                if (Token->type != TOKEN_INTLIT)
                {
                    logSemanticError("MaxLength property is an Integer ");
                    exit(1);
                }
                Widget->type.inputField->maxlength = atoi(Token->value);
                break;
            }
            case TOKEN_PLACEHOLDER:
            {
                if (Token->type != TOKEN_STRING)
                {
                    logSemanticError("PlaceHolder property is a String ");
                    exit(1);
                }
                Widget->type.inputField->placeholder = malloc(strlen(Token->value) * sizeof(char));
                strcpy(Widget->type.inputField->placeholder, Token->value);
                break;
            }
            default:
            {
                logPropDoesntBelongToWidget(token_prop, Widget->widgetType);
                exit(1);
            }
            }
            break;
        }
        }
    }
    }
}

WIDGET *getTheCurrentWidget()
{
    WIDGET *new_widget = (WIDGET *)malloc(sizeof(WIDGET));
    new_widget->widgetType = Widget->widgetType;
    new_widget->height = Widget->height;
    new_widget->width = Widget->width;
    new_widget->opacity = Widget->opacity;
    new_widget->id = malloc(strlen(Widget->id) * sizeof(char));
    strcpy(new_widget->id, Widget->id);
    switch (Widget->widgetType)
    {
    case INTERFACE_TYPE:
    {
        new_widget->type.interface = (INTERFACE *)malloc(sizeof(INTERFACE));
        if (Widget->type.interface->title == NULL)
        {
            new_widget->type.interface->title = NULL;
        }
        else
        {
            new_widget->type.interface->title = malloc(strlen(Widget->type.interface->title) * sizeof(char));
            strcpy(new_widget->type.interface->title, Widget->type.interface->title);
        }
        break;
    }
    case BUTTON_TYPE:
    {
        new_widget->type.button = (BUTTON *)malloc(sizeof(BUTTON));
        if (Widget->type.button->text == NULL)
        {
            new_widget->type.button->text = NULL;
        }
        else
        {
            new_widget->type.button->text = malloc(strlen(Widget->type.button->text) * sizeof(char));
            strcpy(new_widget->type.button->text, Widget->type.button->text);
        }
        break;
    }
    case LABEL_TYPE:
    {
        new_widget->type.label = (LABEL *)malloc(sizeof(LABEL));
        if (Widget->type.label->text == NULL)
        {
            new_widget->type.label->text = NULL;
        }
        else
        {
            new_widget->type.label->text = malloc(strlen(Widget->type.label->text) * sizeof(char));
            strcpy(new_widget->type.label->text, Widget->type.label->text);
        }
        new_widget->type.label->xalign = Widget->type.label->xalign;
        new_widget->type.label->yalign = Widget->type.label->yalign;
        new_widget->type.label->angle = Widget->type.label->angle;
        break;
    }
    case INPUTFIELD_TYPE:
    {
        new_widget->type.inputField = (INPUTFIELD *)malloc(sizeof(INPUTFIELD));
        if (Widget->type.inputField->text == NULL)
        {
            new_widget->type.inputField->text = NULL;
        }
        else
        {
            new_widget->type.inputField->text = malloc(strlen(Widget->type.inputField->text) * sizeof(char));
            strcpy(new_widget->type.inputField->text, Widget->type.inputField->text);
        }
        if (Widget->type.inputField->placeholder == NULL)
        {
            new_widget->type.inputField->placeholder = NULL;
        }
        else
        {
            new_widget->type.inputField->placeholder = malloc(strlen(Widget->type.inputField->placeholder) * sizeof(char));
            strcpy(new_widget->type.inputField->placeholder, Widget->type.inputField->placeholder);
        }
        new_widget->type.inputField->maxlength = Widget->type.inputField->maxlength;
        break;
    }
    }
    return new_widget;
}