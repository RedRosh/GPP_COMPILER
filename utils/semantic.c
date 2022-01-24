#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"

static int size = 1;
static WIDGET **ListOfWidgets;

void init_sym()
{
    ListOfWidgets = (WIDGET **)calloc(size, sizeof(WIDGET));
}
void addWidgetToList()
{
    ListOfWidgets[size - 1] = Widget;
    realloc(*ListOfWidgets, (2 + size++) * sizeof(WIDGET));
}

void getAllWidget()
{
    for (int i = 0; i < size - 1; i++)
    {
        printf("width : %s \n", ListOfWidgets[i]->id);
    }
}
