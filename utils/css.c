#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"
#include "../includes/css.h"

static FILE *themeFile;
void generateCssFile()
{

    if ((themeFile = fopen("theme.css", "w+")) == NULL)
    {
        logError("Could Not open the file");
        exit(1);
    }
    generateResetCss();
    WIDGETNODE *last = linkedWidgetList;
    if (linkedWidgetList == NULL)
    {
        printf("Empty list of widgets");
        exit(1);
    }
    while (last != NULL)
    {
        generateCssForWidget(last->widget);
        last = last->next;
    }
    fclose(themeFile);
}
void addStringCssProperty(char *prop, char *attribute)
{
    if (attribute != NULL)
    {
        fprintf(themeFile, "%s : %s ;\n", prop, attribute);
    }
}
void addIntegerCssProperty(char *prop, int attribute)
{
    if (attribute != -1)
    {

        fprintf(themeFile, "%s : %dpx ;\n", prop, attribute);
    }
}
void generateResetCss()
{
    fprintf(themeFile, "GtkButton { \n");
    addStringCssProperty("border-image", "none");
    fprintf(themeFile, "%s : %s ;\n", "background-image", "none");
    fprintf(themeFile, "} \n\n");
}
void generateCssForWidget(WIDGET *widget)
{
    fprintf(themeFile, "#%s { \n", widget->id);
    addIntegerCssProperty("font-size", widget->styles->fontsize);
    addStringCssProperty("font-style", widget->styles->fontstyle);
    addStringCssProperty("font-weight", widget->styles->fontweight);
    addStringCssProperty("background-color", widget->styles->backgroundcolor);
    addStringCssProperty("color", widget->styles->color);
    addIntegerCssProperty("letter-spacing", widget->styles->letterspacing);
    addStringCssProperty("text-decoration-line", widget->styles->textdecorationline);
    addStringCssProperty("text-decoration-style", widget->styles->textdecorationstyle);
    addIntegerCssProperty("margin-top", widget->styles->margintop);
    addIntegerCssProperty("margin-left", widget->styles->marginleft);
    addIntegerCssProperty("margin-right", widget->styles->marginright);
    addIntegerCssProperty("margin-bottom", widget->styles->marginbottom);
    addIntegerCssProperty("padding-top", widget->styles->paddingtop);
    addIntegerCssProperty("padding-left", widget->styles->paddingleft);
    addIntegerCssProperty("padding-right", widget->styles->paddingright);
    addIntegerCssProperty("padding-bottom", widget->styles->paddingbottom);
    addIntegerCssProperty("min-width", widget->styles->minwidth);
    addIntegerCssProperty("min-height", widget->styles->minheight);
    addIntegerCssProperty("border-width", widget->styles->borderwidth);
    addIntegerCssProperty("border-radius", widget->styles->borderradius);
    addStringCssProperty("border-style", widget->styles->borderstyle);
    addStringCssProperty("border-color", widget->styles->bordercolor);
    fprintf(themeFile, "%s : %s ;\n", "font-family", "\"Comic Sans\"");
    fprintf(themeFile, "} \n\n");
}