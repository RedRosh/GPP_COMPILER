#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"

void widget_init()
{
    Widget = calloc(1, sizeof(WIDGET));
    Widget->styles = (CSSSTYLES *)malloc(sizeof(CSSSTYLES));
    Widget->styles->fontsize = -1;
    Widget->styles->letterspacing = -1;
    Widget->styles->margintop = -1;
    Widget->styles->marginleft = -1;
    Widget->styles->marginright = -1;
    Widget->styles->marginbottom = -1;
    Widget->styles->paddingtop = -1;
    Widget->styles->paddingleft = -1;
    Widget->styles->paddingright = -1;
    Widget->styles->paddingbottom = -1;
    Widget->styles->minwidth = -1;
    Widget->styles->minheight = -1;
    Widget->styles->borderradius = -1;
    Widget->styles->borderwidth = -1;
    Widget->styles->fontstyle = NULL;
    Widget->styles->fontweight = NULL;
    Widget->styles->backgroundcolor = NULL;
    Widget->styles->color = NULL;
    Widget->styles->textdecorationline = NULL;
    Widget->styles->textdecorationstyle = NULL;
    Widget->styles->borderstyle = NULL;
    Widget->styles->bordercolor = NULL;
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
        if (interfaceExists())
        {
            logSemanticError("only one interface should exists");
            exit(1);
        }
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
    case TOKEN_FONTSIZE:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("FontSize property is an integer ");
            exit(1);
        }
        Widget->styles->fontsize = atoi(Token->value);
        break;
    }
    case TOKEN_FONTSTYLE:
    {
        if (Token->type != TOKEN_STRING)
        {
            logSemanticError("FontStyle property is a String ");
            exit(1);
        }
        Widget->styles->fontstyle = malloc(strlen(Token->value) * sizeof(char));
        strcpy(Widget->styles->fontstyle, Token->value);
        break;
    }
    case TOKEN_FONTWEIGHT:
    {
        if (Token->type != TOKEN_STRING)
        {
            logSemanticError("FontWeight property is a String ");
            exit(1);
        }
        Widget->styles->fontweight = malloc(strlen(Token->value) * sizeof(char));
        strcpy(Widget->styles->fontweight, Token->value);
        break;
    }
    case TOKEN_BACKGROUNDCOLOR:
    {
        if (Token->type != TOKEN_STRING)
        {
            logSemanticError("BackgroundColor property is a String ");
            exit(1);
        }
        Widget->styles->backgroundcolor = malloc(strlen(Token->value) * sizeof(char));
        strcpy(Widget->styles->backgroundcolor, Token->value);
        break;
    }
    case TOKEN_COLOR:
    {
        if (Token->type != TOKEN_STRING)
        {
            logSemanticError("Color property is a String ");
            exit(1);
        }
        Widget->styles->color = malloc(strlen(Token->value) * sizeof(char));
        strcpy(Widget->styles->color, Token->value);
        break;
    }
    case TOKEN_LETTERSPACING:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("LetterSpacing property is an integer ");
            exit(1);
        }
        Widget->styles->letterspacing = atoi(Token->value);
        break;
    }
    case TOKEN_TEXTDECORATIONLINE:
    {
        if (Token->type != TOKEN_STRING)
        {
            logSemanticError("TextDecorationLine property is a String ");
            exit(1);
        }
        Widget->styles->textdecorationline = malloc(strlen(Token->value) * sizeof(char));
        strcpy(Widget->styles->textdecorationline, Token->value);
        break;
    }
    case TOKEN_TEXTDECORATIONSTYLE:
    {
        if (Token->type != TOKEN_STRING)
        {
            logSemanticError("TextDecorationStyle property is a String ");
            exit(1);
        }
        Widget->styles->textdecorationstyle = malloc(strlen(Token->value) * sizeof(char));
        strcpy(Widget->styles->textdecorationstyle, Token->value);
        break;
    }
    case TOKEN_MARGINTOP:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("MarginTop property is an integer ");
            exit(1);
        }
        Widget->styles->margintop = atoi(Token->value);
        break;
    }
    case TOKEN_MARGINLEFT:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("MarginLeft property is an integer ");
            exit(1);
        }
        Widget->styles->marginleft = atoi(Token->value);
        break;
    }
    case TOKEN_MARGINRIGHT:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("MarginRight property is an integer ");
            exit(1);
        }
        Widget->styles->marginright = atoi(Token->value);
        break;
    }
    case TOKEN_MARGINBOTTOM:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("MarginBottom property is an integer ");
            exit(1);
        }
        Widget->styles->marginbottom = atoi(Token->value);
        break;
    }
    case TOKEN_PADDINGTOP:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("PaddingTop property is an integer ");
            exit(1);
        }
        Widget->styles->paddingtop = atoi(Token->value);
        break;
    }
    case TOKEN_PADDINGLEFT:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("PaddingLeft property is an integer ");
            exit(1);
        }
        Widget->styles->paddingleft = atoi(Token->value);
        break;
    }
    case TOKEN_PADDINGRIGHT:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("PaddingRight property is an integer ");
            exit(1);
        }
        Widget->styles->paddingright = atoi(Token->value);
        break;
    }
    case TOKEN_MINWIDTH:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("MinWidth property is an integer ");
            exit(1);
        }
        Widget->styles->minwidth = atoi(Token->value);
        break;
    }
    case TOKEN_MINHEIGHT:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("MinHeight property is an integer ");
            exit(1);
        }
        Widget->styles->minheight = atoi(Token->value);
        break;
    }
    case TOKEN_BORDERWIDTH:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("BorderWidth property is an integer ");
            exit(1);
        }
        Widget->styles->borderwidth = atoi(Token->value);
        break;
    }
    case TOKEN_BORDERRADIUS:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("BorderRadius property is an integer ");
            exit(1);
        }
        Widget->styles->borderradius = atoi(Token->value);
        break;
    }
    case TOKEN_BORDERSTYLE:
    {
        if (Token->type != TOKEN_STRING)
        {
            logSemanticError("BorderStyle property is a String ");
            exit(1);
        }
        Widget->styles->borderstyle = malloc(strlen(Token->value) * sizeof(char));
        strcpy(Widget->styles->borderstyle, Token->value);
        break;
    }
    case TOKEN_BORDERCOLOR:
    {
        if (Token->type != TOKEN_STRING)
        {
            logSemanticError("BorderColor property is a String ");
            exit(1);
        }
        Widget->styles->bordercolor = malloc(strlen(Token->value) * sizeof(char));
        strcpy(Widget->styles->bordercolor, Token->value);
        break;
    }
    case TOKEN_PADDINGBOTTOM:
    {
        if (Token->type != TOKEN_INTLIT)
        {
            logSemanticError("PaddingBottom property is an integer ");
            exit(1);
        }
        Widget->styles->paddingbottom = atoi(Token->value);
        break;
    }
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
    new_widget->styles = (CSSSTYLES *)malloc(sizeof(CSSSTYLES));
    new_widget->styles->fontsize = Widget->styles->fontsize;
    new_widget->styles->letterspacing = Widget->styles->letterspacing;
    new_widget->styles->margintop = Widget->styles->margintop;
    new_widget->styles->marginleft = Widget->styles->marginleft;
    new_widget->styles->marginright = Widget->styles->marginright;
    new_widget->styles->marginbottom = Widget->styles->marginbottom;
    new_widget->styles->paddingtop = Widget->styles->paddingtop;
    new_widget->styles->paddingleft = Widget->styles->paddingleft;
    new_widget->styles->paddingright = Widget->styles->paddingright;
    new_widget->styles->paddingbottom = Widget->styles->paddingbottom;
    new_widget->styles->minwidth = Widget->styles->minwidth;
    new_widget->styles->minheight = Widget->styles->paddingbottom;
    new_widget->styles->borderradius = Widget->styles->borderradius;
    new_widget->styles->borderwidth = Widget->styles->borderwidth;

    if (Widget->styles->textdecorationline == NULL)
    {
        new_widget->styles->textdecorationline = NULL;
    }
    else
    {
        new_widget->styles->textdecorationline = malloc(strlen(Widget->styles->textdecorationline) * sizeof(char));
        strcpy(new_widget->styles->textdecorationline, Widget->styles->textdecorationline);
    }
    if (Widget->styles->textdecorationstyle == NULL)
    {
        new_widget->styles->textdecorationstyle = NULL;
    }
    else
    {
        new_widget->styles->textdecorationstyle = malloc(strlen(Widget->styles->textdecorationstyle) * sizeof(char));
        strcpy(new_widget->styles->textdecorationstyle, Widget->styles->textdecorationstyle);
    }
    if (Widget->styles->borderstyle == NULL)
    {
        new_widget->styles->borderstyle = NULL;
    }
    else
    {
        new_widget->styles->borderstyle = malloc(strlen(Widget->styles->borderstyle) * sizeof(char));
        strcpy(new_widget->styles->borderstyle, Widget->styles->borderstyle);
    }

    if (Widget->styles->bordercolor == NULL)
    {
        new_widget->styles->bordercolor = NULL;
    }
    else
    {
        new_widget->styles->bordercolor = malloc(strlen(Widget->styles->bordercolor) * sizeof(char));
        strcpy(new_widget->styles->bordercolor, Widget->styles->bordercolor);
    }

    if (Widget->styles->fontstyle == NULL)
    {
        new_widget->styles->fontstyle = NULL;
    }
    else
    {
        new_widget->styles->fontstyle = malloc(strlen(Widget->styles->fontstyle) * sizeof(char));
        strcpy(new_widget->styles->fontstyle, Widget->styles->fontstyle);
    }

    if (Widget->styles->fontweight == NULL)
    {
        new_widget->styles->fontweight = NULL;
    }
    else
    {
        new_widget->styles->fontweight = malloc(strlen(Widget->styles->fontweight) * sizeof(char));
        strcpy(new_widget->styles->fontweight, Widget->styles->fontweight);
    }
    if (Widget->styles->backgroundcolor == NULL)
    {
        new_widget->styles->backgroundcolor = NULL;
    }
    else
    {
        new_widget->styles->backgroundcolor = malloc(strlen(Widget->styles->backgroundcolor) * sizeof(char));
        strcpy(new_widget->styles->backgroundcolor, Widget->styles->backgroundcolor);
    }
    if (Widget->styles->color == NULL)
    {
        new_widget->styles->color = NULL;
    }
    else
    {
        new_widget->styles->color = malloc(strlen(Widget->styles->color) * sizeof(char));
        strcpy(new_widget->styles->color, Widget->styles->color);
    }
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

WIDGET *getWidgetById(char *widget_id)
{
    WIDGETNODE *last = linkedWidgetList;
    if (linkedWidgetList == NULL)
    {
        printf("Empty list of widgets");
        exit(1);
    }
    while (last != NULL)
    {
        if (!strcmp(last->widget->id, widget_id))
        {
            return last->widget;
        }
        last = last->next;
    }
    return NULL;
}