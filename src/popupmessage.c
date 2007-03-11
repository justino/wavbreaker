/* wavbreaker - A tool to split a wave file up into multiple waves.
 * Copyright (C) 2002-2003 Timothy Robinson
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <gtk/gtk.h>
#include "wavbreaker.h"

void popupmessage_hide( GtkDialog *dialog, int response_id, gpointer user_data)
{
    GtkWidget *window = GTK_WIDGET(user_data);
    gtk_widget_destroy(window);
}

void popupmessage_show( GtkWidget *main_window, const char *message, const char *description)
{
    GtkMessageDialog *dialog;
    gint result;

    if( main_window == NULL) {
        main_window = wavbreaker_get_main_window();
    }

    dialog = gtk_message_dialog_new( main_window,
                                     GTK_DIALOG_DESTROY_WITH_PARENT | GTK_DIALOG_MODAL,
                                     GTK_MESSAGE_INFO,
                                     GTK_BUTTONS_OK,
                                     message);

    gtk_message_dialog_format_secondary_text( dialog, description);

    g_signal_connect( G_OBJECT(dialog), "response", (GtkSignalFunc)popupmessage_hide, dialog);

    gtk_widget_show_all( dialog);
}

