#include <gtk/gtk.h>

static void activate(GtkApplication *app,gpointer user_data){
    GtkWidget *window;
    GtkWidget *label;
     GtkCssProvider *css_provider;
     
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window),"GTK 4 Test ");
    gtk_window_set_default_size(GTK_WINDOW(window),400,300);

    // Create a label with "Hello World"
    label = gtk_label_new("Hello World!");

     // Add the label to the window
    gtk_window_set_child(GTK_WINDOW(window), label);

    // Create CSS provider and load file
    css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(css_provider, "style.css");

    // Apply CSS to the default screen
    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(),
        GTK_STYLE_PROVIDER(css_provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER
    );

    // Show the window
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc,char*argv[]){
    GtkApplication *app;
    int status;

    app = gtk_application_new(
        "com.example.gtk4test",
        G_APPLICATION_DEFAULT_FLAGS
    );

    g_signal_connect(app,"activate",
        G_CALLBACK(activate),NULL);

    status = g_application_run(
        G_APPLICATION(app),
        argc,argv
    );

    g_object_unref(app);
    return status;
}