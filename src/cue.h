/* wavbreaker - A tool to split a wave file up into multiple waves.
 * Copyright (C) 2002-2005 Timothy Robinson
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

#ifndef CUE_H
#define CUE_H

#include <glib.h>

#include "track_break.h"

gboolean
cue_read_file(const char *cue_filename, TrackBreakList *list);

gboolean
cue_write_file(const char *cue_filename, const char *audio_filename, TrackBreakList *list);

#endif /* CUE_H */
