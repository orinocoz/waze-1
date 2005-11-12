/* editor_trkseg.h - database layer
 *
 * LICENSE:
 *
 *   Copyright 2005 Ehud Shabtai
 *
 *   This file is part of RoadMap.
 *
 *   RoadMap is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   RoadMap is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with RoadMap; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef INCLUDE__EDITOR_TRKSEG__H
#define INCLUDE__EDITOR_TRKSEG__H

#include "../roadmap_types.h"
#include "../roadmap_dbread.h"

#define ED_TRKSEG_CONNECT_GLOBAL 1

/* flags */
#define ED_TRKSEG_FAKE      0x1
#define ED_TRKSEG_IGNORE    0x2
#define ED_TRKSEG_NEW_TRACK 0x4

typedef struct editor_db_trkseg_s {
   int line_id;
   int point_from;
   int point_to;
   int first_shape;
   int last_shape;
   int gps_start_time;
   int gps_end_time;
   int flags;
   int next_road_trkseg;
   int next_global_trkseg;
} editor_db_trkseg;

void editor_trkseg_set_line (int trkseg, int line_id);

int editor_trkseg_add (int line_id,
                       int p_from,
                       int p_to,
                       int first_shape,
                       int last_shape,
                       int gps_start_time,
                       int gps_end_time,
                       int flags,
                       int connect);

void editor_trkseg_get (int trkseg,
                        int *p_from,
                        int *p_to,
                        int *first_shape,
                        int *last_shape,
                        int *flags);

int editor_trkseg_get_line (int trkseg);

void editor_trkseg_get_time (int trkseg,
                             int *start_time,
                             int *end_time);

void editor_trkseg_connect_roads (int previous, int next);
void editor_trkseg_connect_global (int previous, int next);
int editor_trkseg_next_in_road (int trkseg);
int editor_trkseg_next_in_global (int trkseg);

int editor_trkseg_roadmap_line (int line_id, int *first, int *last);

int editor_trkseg_split (int trkseg, RoadMapPosition *split_pos);

extern roadmap_db_handler EditorTrksegHandler;

#endif // INCLUDE__EDITOR_TRKSEG__H
