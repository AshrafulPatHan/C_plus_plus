#include <gtk/gtk.h>

static void activate(GtkApplication *app,gpointer user_data){
    GtkWidget *window;
    GtkWidget *label;
     
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window),"GTK 4 Test ");
    gtk_window_set_default_size(GTK_WINDOW(window),400,300);

    // Create a label with "Hello World"
    label = gtk_label_new("Hello World!");

     // Add the label to the window
    gtk_window_set_child(GTK_WINDOW(window), label);

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