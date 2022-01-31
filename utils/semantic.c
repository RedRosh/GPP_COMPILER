#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"

void addWidgetToList()
{
    WIDGETNODE *new_node_widget = (WIDGETNODE *)calloc(1, sizeof(struct WIDGETNODE));
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

void addOperationToList()
{
    OPERATIONNODE *new_node_operation = (OPERATIONNODE *)calloc(1, sizeof(struct OPERATIONNODE));
    OPERATIONNODE *last = linkedOperationList;

    new_node_operation->operation = getTheCurrentOperation();
    new_node_operation->next = NULL;
    if (linkedOperationList == NULL)
    {
        linkedOperationList = new_node_operation;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node_operation;
}

void getAllOperations()
{
    OPERATIONNODE *last = linkedOperationList;
    if (linkedOperationList == NULL)
    {
        printf("Empty list of Operations");
        exit(1);
    }
    while (last != NULL)
    {
        logCurrentOperation(last->operation);
        last = last->next;
    }
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

int interfaceExists()
{
    WIDGETNODE *current = linkedWidgetList;
    if (linkedWidgetList == NULL)
    {
        return 0;
    }
    int numberOfInterface = 0;
    while (current != NULL)
    {
        if (current->widget->widgetType == INTERFACE_TYPE)
        {
            numberOfInterface++;
        }
        current = current->next;
    }
    return numberOfInterface != 0;
}

void deleteWidgetFromList(char *widget_id)
{
    WIDGETNODE *current = linkedWidgetList;
    if (linkedWidgetList == NULL)
    {
        printf("Nothing To Delete \n");
        return;
    }
    if (!strcmp(linkedWidgetList->widget->id, widget_id) && linkedWidgetList->widget->widgetType == INTERFACE_TYPE)
    {
        printf("Destroying Interface , Nothing will happen \n");
        exit(1);
    }
    while (current->next != NULL)
    {
        if (!strcmp(current->next->widget->id, widget_id))
        {
            if (current->next->widget->widgetType == INTERFACE_TYPE)
            {
                printf("Destroying Interface , Nothing will happen \n");
                exit(1);
            }
            else
            {
                current->next = current->next->next;
            }
        }
        current = current->next;
    }
}
int isInterfaceWidget(char *widget_id)
{
    WIDGETNODE *current = linkedWidgetList;
    if (linkedWidgetList == NULL)
    {
        return 0;
    }
    while (current != NULL)
    {
        if (current->widget->widgetType == INTERFACE_TYPE &&
            !strcmp(widget_id, current->widget->id))
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
