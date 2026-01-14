// calculator.c
#include <gtk/gtk.h>

// widgets global for callback 
GtkWidget *entry1;
GtkWidget *entry2;
GtkWidget *result_label;

// function for button
static void calculate(GtkButton *button, gpointer user_data) {
    const char *op = gtk_button_get_label(button);

    double a = atof(gtk_editable_get_text(GTK_EDITABLE(entry1)));
    double b = atof(gtk_editable_get_text(GTK_EDITABLE(entry2)));
    double result = 0.0;

    if (g_strcmp0(op, "+") == 0)
        result = a + b;
    else if (g_strcmp0(op, "-") == 0)
        result = a - b;
    else if (g_strcmp0(op, "*") == 0)
        result = a * b;
    else if (g_strcmp0(op, "/") == 0) {
        if (b == 0) {
            gtk_label_set_text(GTK_LABEL(result_label), "Error: Divide by zero");
            return;
        }
        result = a / b;
    }

    char buffer[100];
    g_snprintf(buffer, sizeof(buffer), "Result: %.2f", result);
    gtk_label_set_text(GTK_LABEL(result_label), buffer);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *hbox;
    GtkWidget *button;

    // main window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "GTK Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // vertical box
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
    gtk_window_set_child(GTK_WINDOW(window), vbox);

    // input fields
    entry1 = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry1), "Enter first number");

    entry2 = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry2), "Enter second number");

    gtk_box_append(GTK_BOX(vbox), entry1);
    gtk_box_append(GTK_BOX(vbox), entry2);

    // horizontal box for buttons
    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_append(GTK_BOX(vbox), hbox);

    // buttons
    const char *ops[] = {"+", "-", "*", "/"};

    for (int i = 0; i < 4; i++) {
        button = gtk_button_new_with_label(ops[i]);
        g_signal_connect(button, "clicked", G_CALLBACK(calculate), NULL);
        gtk_box_append(GTK_BOX(hbox), button);
    }

    // result label
    result_label = gtk_label_new("Result: ");
    gtk_box_append(GTK_BOX(vbox), result_label);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) {
    GtkApplication *app;
    int status;

    app = gtk_application_new(
        "com.example.calculator",
        G_APPLICATION_DEFAULT_FLAGS
    );

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
