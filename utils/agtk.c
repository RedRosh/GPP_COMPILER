#include "../includes/defs.h"
#include "../includes/data.h"
#include "../includes/dcl.h"
#include "../includes/agtk.h"

void convert_widget_to_gtk_widget()
{

    WIDGETNODE *last = linkedWidgetList;
    if (linkedWidgetList == NULL)
    {
        printf("Empty list of widgets");
        exit(1);
    }
    while (last != NULL)
    {
        addGtkWidgetToList(last->widget);
        last = last->next;
    }
}

void addGtkWidgetToList(WIDGET *widget)
{
    GTKWIDGETNODE *new_node_gtk_widget = (GTKWIDGETNODE *)malloc(sizeof(struct GTKWIDGETNODE));
    GTKWIDGETNODE *last = linkedGtkWidgetList;
    new_node_gtk_widget->widgetType = widget->widgetType;
    new_node_gtk_widget->id = malloc(strlen(widget->id) * sizeof(char));
    strcpy(new_node_gtk_widget->id, widget->id);
    new_node_gtk_widget->gtk_widget = create_gtk_widget(widget);
    new_node_gtk_widget->next = NULL;
    if (linkedGtkWidgetList == NULL)
    {
        linkedGtkWidgetList = new_node_gtk_widget;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node_gtk_widget;
}

GtkWidget *create_gtk_widget(WIDGET *widget)
{
    GtkWidget *gtk_widget;
    switch (widget->widgetType)
    {
    case INTERFACE_TYPE:
    {
        gtk_widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        break;
    }
    case LABEL_TYPE:
    {
        gtk_widget = gtk_label_new(NULL);
        set_widget_text(gtk_widget, widget);
        set_widget_angle(gtk_widget, widget);
        set_widget_xalign(gtk_widget, widget);
        set_widget_yalign(gtk_widget, widget);
        break;
    }
    case BUTTON_TYPE:
    {
        gtk_widget = gtk_button_new();
        set_widget_text(gtk_widget, widget);
        break;
    }
    case INPUTFIELD_TYPE:
    {
        gtk_widget = gtk_entry_new();
        set_widget_text(gtk_widget, widget);
        set_widget_placeholder(gtk_widget, widget);
        set_widget_maxlength(gtk_widget, widget);
        break;
    }
    }
    set_widget_opacity(gtk_widget, widget);
    set_widget_height_width(gtk_widget, widget);
    set_widget_name(gtk_widget, widget);
    return gtk_widget;
}

void getAllGtkWidget()
{
    GTKWIDGETNODE *last = linkedGtkWidgetList;
    if (linkedGtkWidgetList == NULL)
    {
        printf("Empty list of gtk widgets");
        exit(1);
    }
    while (last != NULL)
    {
        printf("gtk :  %s  %d \n", last->id, last->widgetType);
        last = last->next;
    }
}
void set_widget_text(GtkWidget *gtk_widget, WIDGET *widget)
{
    switch (widget->widgetType)
    {
    case LABEL_TYPE:
    {
        if (widget->type.label->text != NULL)
        {
            gtk_label_set_text(GTK_LABEL(gtk_widget), widget->type.label->text);
        }
        break;
    }
    case BUTTON_TYPE:
    {
        if (widget->type.button->text != NULL)
        {
            gtk_container_add(GTK_CONTAINER(gtk_widget), gtk_label_new(widget->type.label->text));
        }
        break;
    }
    case INPUTFIELD_TYPE:
    {
        if (widget->type.inputField->text != NULL)
        {
            gtk_entry_set_text(GTK_ENTRY(gtk_widget), widget->type.inputField->text);
        }
        break;
    }
    }
}
void set_widget_maxlength(GtkWidget *gtk_widget, WIDGET *widget)
{
    if (widget->type.inputField->maxlength != -1)
    {
        gtk_entry_set_max_length(GTK_ENTRY(gtk_widget), widget->type.inputField->maxlength);
    }
}
void set_widget_placeholder(GtkWidget *gtk_widget, WIDGET *widget)
{
    if (widget->type.inputField->placeholder != NULL)
    {
        gtk_entry_set_placeholder_text(GTK_ENTRY(gtk_widget), widget->type.inputField->placeholder);
    }
}
void set_widget_xalign(GtkWidget *gtk_widget, WIDGET *widget)
{
    if (widget->type.label->xalign != -1)
    {
        gtk_label_set_xalign(GTK_LABEL(gtk_widget), (float)(widget->type.label->xalign / 100.0));
    }
}
void set_widget_yalign(GtkWidget *gtk_widget, WIDGET *widget)
{
    if (widget->type.label->yalign != -1)
    {
        gtk_label_set_yalign(GTK_LABEL(gtk_widget), (float)(widget->type.label->yalign / 100.0));
    }
}
void set_widget_angle(GtkWidget *gtk_widget, WIDGET *widget)
{
    if (widget->type.label->angle != -1)
    {
        gtk_label_set_angle(GTK_LABEL(gtk_widget), (double)(widget->type.label->angle));
    }
}
void set_widget_title(GtkWidget *gtk_widget, WIDGET *widget)
{
    if (widget->type.interface->title != NULL)
    {
        gtk_window_set_title(gtk_widget, widget->type.interface->title);
    }
}
void set_widget_opacity(GtkWidget *gtk_widget, WIDGET *widget)
{
    if (widget->opacity != -1)
    {
        gtk_widget_set_opacity(gtk_widget, (double)(widget->opacity / 100.0));
    }
}

void set_widget_height_width(GtkWidget *gtk_widget, WIDGET *widget)
{
    if (widget->height != -1 && widget->width != -1)
    {
        gtk_widget_set_size_request(gtk_widget, widget->width, widget->height);
    }
}

void set_widget_name(GtkWidget *gtk_widget, WIDGET *widget)
{
    if (widget->id != NULL)
    {
        gtk_widget_set_name(gtk_widget, widget->id);
    }
}

void show_widget(GtkWidget *gtk_widget)
{
    gtk_widget_show_all(gtk_widget);
}

void launch_gtk()
{
    gtk_main();
}
