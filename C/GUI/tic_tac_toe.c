// gcc tic_tac_toe.c -o tictactoe `pkg-config --cflags --libs gtk4`
// ./tictactoe

#include <gtk/gtk.h>

GtkWidget *buttons[3][3];
char board[3][3];
char current_player = 'X';

// winner check
static void check_winner() {
    for (int i = 0; i < 3; i++) {
        // row
        if (board[i][0] && board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            g_print("Winner: %c\n", board[i][0]);
            return;
        }
        // column
        if (board[0][i] && board[0][i] == board[1][i] &&
            board[1][i] == board[2][i]) {
            g_print("Winner: %c\n", board[0][i]);
            return;
        }
    }

    // diagonal
    if (board[0][0] && board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        g_print("Winner: %c\n", board[0][0]);
        return;
    }

    if (board[0][2] && board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        g_print("Winner: %c\n", board[0][2]);
        return;
    }
}

// button click
static void on_button_clicked(GtkButton *button, gpointer data) {
    int row = GPOINTER_TO_INT(data) / 3;
    int col = GPOINTER_TO_INT(data) % 3;

    if (board[row][col] != 0)
        return;

    board[row][col] = current_player;

    char text[2] = {current_player, '\0'};
    gtk_button_set_label(button, text);

    check_winner();

    current_player = (current_player == 'X') ? 'O' : 'X';
}

// app start
static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Tic Tac Toe");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);

    grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window), grid);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            buttons[i][j] = gtk_button_new_with_label("");
            gtk_widget_set_hexpand(buttons[i][j], TRUE);
            gtk_widget_set_vexpand(buttons[i][j], TRUE);

            int index = i * 3 + j;
            g_signal_connect(
                buttons[i][j],
                "clicked",
                G_CALLBACK(on_button_clicked),
                GINT_TO_POINTER(index)
            );

            gtk_grid_attach(GTK_GRID(grid), buttons[i][j], j, i, 1, 1);
            board[i][j] = 0;
        }
    }

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) {
    GtkApplication *app;
    int status;

    app = gtk_application_new(
        "com.example.tictactoe",
        G_APPLICATION_DEFAULT_FLAGS
    );

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
