#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"
#include "../includes/operation.h"

void operation_init()
{
    Opera = calloc(1, sizeof(OPERATION));
}

void set_operation_type()
{
    switch (Token->type)
    {
    case TOKEN_START:
    {
        Opera->OperationType = START_TYPE;
        break;
    }
    case TOKEN_SHOW:
    {
        Opera->OperationType = SHOW_TYPE;
        break;
    }
    case TOKEN_PUT:
    {
        Opera->OperationType = PUT_TYPE;
        break;
    }
    case TOKEN_DESTROY:
    {
        Opera->OperationType = DESTROY_TYPE;
        break;
    }
    case TOKEN_SLEEP:
    {
        Opera->OperationType = SLEEP_TYPE;
        break;
    }
    }
}
void set_operation_id(char *widget_id)
{
    if (idExists(widget_id))
    {
        switch (Opera->OperationType)
        {
        case START_TYPE:
        case SHOW_TYPE:
        {
            if (!isInterfaceWidget(widget_id))
            {
                logSemanticError("you should use start / show operations with widget of the type Interface ");
                exit(1);
            }
        }
        }
        Opera->id_widget = calloc(strlen(widget_id) + 1, sizeof(char));
        strcpy(Opera->id_widget, widget_id);
    }
    else
    {
        logSemanticError("Id does not exist");
        exit(1);
    }
}

void set_query_params(char *query)
{
    switch (Opera->OperationType)
    {
    case START_TYPE:
    {
        if (!strcmp(query, "CENTER") || !strcmp(query, "MOUSE"))
        {
            Opera->params.query = calloc(strlen(query) + 1, sizeof(char));
            strcpy(Opera->params.query, query);
            break;
        }
        else
        {
            logSemanticError("Query should be either CENTER or MOUSE ");
            exit(1);
        }
    }
    default:
    {
        logSemanticError("Only Start operation supports string parameter");
        exit(1);
    }
    }
}
void set_sleep_params(int sleep)
{
    switch (Opera->OperationType)
    {
    case SLEEP_TYPE:
    {
        Opera->params.sleep = sleep;
        break;
    }
    default:
    {
        logSemanticError("Only Sleep operation supports one integer as param");
        exit(1);
    }
    }
}
void set_position_params(int x, int y)
{
    switch (Opera->OperationType)
    {
    case PUT_TYPE:
    {
        Opera->params.position = (POSITION *)calloc(1, sizeof(POSITION));
        Opera->params.position->x = x;
        Opera->params.position->y = y;
        break;
    }
    default:
    {
        logSemanticError("Only Put operation supports two integer as params");
        exit(1);
    }
    }
}

void check_operation()
{
    switch (Opera->OperationType)
    {
    case SHOW_TYPE:
    case DESTROY_TYPE:
    {
        break;
    }
    default:
    {
        logOperationNeedParams(Opera->OperationType);
        exit(1);
    }
    }
}

OPERATION *getTheCurrentOperation()
{
    OPERATION *new_operation = (OPERATION *)calloc(1, sizeof(OPERATION));
    new_operation->OperationType = Opera->OperationType;
    switch (new_operation->OperationType)
    {
    case START_TYPE:
    {
        new_operation->id_widget = calloc(strlen(Opera->id_widget) + 1, sizeof(char));
        strcpy(new_operation->id_widget, Opera->id_widget);
        new_operation->params.query = calloc(strlen(Opera->params.query) + 1, sizeof(char));
        strcpy(new_operation->params.query, Opera->params.query);
        break;
    }
    case PUT_TYPE:
    {
        new_operation->id_widget = calloc(strlen(Opera->id_widget) + 1, sizeof(char));
        strcpy(new_operation->id_widget, Opera->id_widget);
        new_operation->params.position = (POSITION *)calloc(1, sizeof(POSITION));
        new_operation->params.position->x = Opera->params.position->x;
        new_operation->params.position->y = Opera->params.position->y;
        break;
    }
    case SLEEP_TYPE:
    {
        new_operation->params.sleep = Opera->params.sleep;
        break;
    }
    case DESTROY_TYPE:
    case SHOW_TYPE:
    {
        new_operation->id_widget = calloc(strlen(Opera->id_widget) + 1, sizeof(char));
        strcpy(new_operation->id_widget, Opera->id_widget);
        break;
    }
    }
    return new_operation;
}
void clean_operation()
{
    free(Opera);
}
