#include <gtk/gtk.h>
void add_element_to_window(GtkWidget *window, GtkWidget *button, int x, int y);
int main(int argc, char *argv[])
{

    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *button2;
    GtkWidget *fixed;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Tooltip");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 15);

    button = gtk_button_new_with_label("Yo");
    button2 = gtk_button_new_with_label("yay");
    gtk_widget_set_size_request(button2, 15, 100);
    gtk_widget_set_tooltip_text(button, "Button widget");
    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);
    add_element_to_window(fixed, button, 10, 50);
    add_element_to_window(fixed, button2, 100, 50);
    gtk_widget_show_all(window);
    g_signal_connect(G_OBJECT(window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();

    return 0;
}

void add_element_to_window(GtkWidget *fixed, GtkWidget *button, int x, int y)
{
    gtk_fixed_put(GTK_FIXED(fixed), button, x, y);
}