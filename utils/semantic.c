#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"

void init_sym()
{
}
void addWidgetToList()
{
    WIDGETNODE *new_node_widget = (WIDGETNODE *)malloc(sizeof(struct WIDGETNODE));
    WIDGETNODE *last = linkedWidgetList;
    new_node_widget->widget = getTheCurrentWidget();
    new_node_widget->next = NULL;
    if (linkedWidgetList == NULL)
    {
        linkedWidgetList = new_node_widget;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node_widget;
}

void getAllWidgets()
{
    WIDGETNODE *last = linkedWidgetList;
    if (linkedWidgetList == NULL)
    {
        printf("Empty list of widgets");
        exit(1);
    }
    while (last != NULL)
    {
        logCurrentWidget(last->widget);
        last = last->next;
    }
}
int idExists(char *widget_id)
{
    WIDGETNODE *current = linkedWidgetList;
    if (linkedWidgetList == NULL)
    {
        return 0;
    }
    while (current != NULL)
    {
        if (!strcmp(current->widget->id, widget_id))
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}