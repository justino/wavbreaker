/* wavbreaker - A tool to split a wave file up into multiple waves.
 * Copyright (C) 2002-2006 Timothy Robinson
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

#include "gettext.h"

void reallyquit_show(GtkWidget *main_window)
{
    GtkMessageDialog *dialog;
    gint result;
    const gchar *message = _("Quit wavbreaker?");
    const gchar *info_text = _("If you quit wavbreaker now, any unsaved chunks will be lost.");

    if( main_window == NULL) {
        main_window = wavbreaker_get_main_window();
    }

    dialog = gtk_message_dialog_new( (GtkWindow*)main_window,
                                     GTK_DIALOG_DESTROY_WITH_PARENT,
                                     GTK_MESSAGE_QUESTION,
                                     GTK_BUTTONS_YES_NO,
                                     message);


    gtk_message_dialog_format_secondary_text( dialog, info_text);

    result = gtk_dialog_run( GTK_DIALOG(dialog));
    switch( result) {
        case GTK_RESPONSE_YES:
            wavbreaker_quit();
            break;
        default:
            gtk_widget_destroy( dialog);
            break;
    }
}

