#include <gtk/gtk.h>
#include <gtk/gtkclipboard.h>
#include <gdk/gdk.h>
#include <stdio.h>

static gboolean
view_onDragMotion (GtkWidget *widget, GdkDragContext *context, gint x,
    gint y, guint time, gpointer data) {
  printf("DRAG MOTION %d %d %d\n",time, x, y);
  return TRUE;
}

gboolean window_focus(GtkWidget* wnd, GdkEventFocus event, gpointer used_data) {
  printf("FOCUSED\n");
  return TRUE;
}
int main (int argc, char **argv)
{
  GtkWidget *window, *vbox;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(window, "delete_event", gtk_main_quit, NULL);
  g_signal_connect(window, "focus_in_event", G_CALLBACK(window_focus), NULL);
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

  vbox = gtk_box_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  static GtkTargetEntry targetentries[] =
  {
    { "text/uri-list", 0, 1 },
  };

  gtk_drag_dest_set(vbox, GTK_DEST_DEFAULT_ALL, targetentries, 1, GDK_ACTION_COPY|GDK_ACTION_MOVE|GDK_ACTION_LINK);

  g_signal_connect(vbox, "drag_motion",
      G_CALLBACK(view_onDragMotion), NULL);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
