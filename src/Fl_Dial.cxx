//
// "$Id: Fl_Dial.cxx,v 1.19 1999/10/27 08:40:54 bill Exp $"
//
// Circular dial widget for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-1999 by Bill Spitzak and others.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//
// Please report all bugs and problems to "fltk-bugs@easysw.com".
//

#include <FL/Fl.H>
#include <FL/Fl_Dial.H>
#include <FL/fl_draw.H>
#include <stdlib.h>
#include <FL/math.h>

// All angles are measured with 0 to the right and counter-clockwise

void Fl_Dial::draw(int x, int y, int w, int h) {
  double angle = (a2-a1)*(value()-minimum())/(maximum()-minimum()) + a1;
  if (type() == FL_FILL_DIAL) {
    if (box() == FL_OVAL_BOX) {x--; y--; w+=2; h+=2;}
    fl_color(color());
    fl_pie(x, y, w-1, h-1, 270-a1, angle > a1 ? 360+270-angle : 270-360-angle);
    fl_color(selection_color());
    fl_pie(x, y, w-1, h-1, 270-angle, 270-a1);
    if (box() == FL_OVAL_BOX) {
      fl_color(off_color());
      fl_arc(x, y, w, h, 0, 360);
    }
    return;
  }
  if (!(damage()&FL_DAMAGE_ALL)) {
    fl_color(color());
    fl_pie(x+1, y+1, w-2, h-2, 0, 360);
  }
  fl_push_matrix();
  fl_translate(x+w/2-.5, y+h/2-.5);
  fl_scale(w-1, h-1);
  fl_rotate(45-angle);
  fl_color(selection_color());
  if (type()) { // FL_LINE_DIAL
    fl_begin_polygon();
    fl_vertex(0.0,   0.0);
    fl_vertex(-0.04, 0.0);
    fl_vertex(-0.25, 0.25);
    fl_vertex(0.0,   0.04);
    fl_end_polygon();
    fl_color(off_color());
    fl_begin_loop();
    fl_vertex(0.0,   0.0);
    fl_vertex(-0.04, 0.0);
    fl_vertex(-0.25, 0.25);
    fl_vertex(0.0,   0.04);
    fl_end_loop();
  } else {
    fl_begin_polygon(); fl_circle(-0.20, 0.20, 0.07); fl_end_polygon();
    fl_color(off_color());
    fl_begin_loop(); fl_circle(-0.20, 0.20, 0.07); fl_end_loop();
  }
  fl_pop_matrix();
}

void Fl_Dial::draw() {
  if (damage()&FL_DAMAGE_ALL) draw_box();
  draw(x()+box()->dx(),
       y()+box()->dy(),
       w()-box()->dw(),
       h()-box()->dh());
  draw_label();
}

int Fl_Dial::handle(int event, int x, int y, int w, int h) {
  switch (event) {
  case FL_ENTER: return 1; // for tooltips
  case FL_PUSH:
    handle_push();
  case FL_DRAG: {
    int mx = Fl::event_x()-x-w/2;
    int my = Fl::event_y()-y-h/2;
    if (!mx && !my) return 1;
    double angle = 270-atan2((float)-my, (float)mx)*180/M_PI;
    double oldangle = (a2-a1)*(value()-minimum())/(maximum()-minimum()) + a1;
    while (angle < oldangle-180) angle += 360;
    while (angle > oldangle+180) angle -= 360;
    double val;
    if ((a1<a2) ? (angle <= a1) : (angle >= a1)) {
      val = minimum();
    } else if ((a1<a2) ? (angle >= a2) : (angle <= a2)) {
      val = maximum();
    } else {
      val = minimum() + (maximum()-minimum())*(angle-a1)/(a2-a1);
    }
    handle_drag(clamp(round(val)));
  } return 1;
  case FL_RELEASE:
    if (!Fl::pushed()) handle_release();
    return 1;
  default:
    return 0;
  }
}

int Fl_Dial::handle(int e) {
  return handle(e,
		x()+box()->dx(),
		y()+box()->dy(),
		w()-box()->dw(),
		h()-box()->dh());
}

Fl_Style Fl_Dial::default_style = {
  FL_OVAL_BOX,	// box
  0,		// glyph
  0,		// label_font
  0,		// text_font
  0,		// label_type
  0,		// color
  0,		// label_color
  FL_DARK2	// selection_color
  // rest is zero
};

static Fl_Style_Definer x("dial", Fl_Dial::default_style);

Fl_Dial::Fl_Dial(int x, int y, int w, int h, const char* l)
  : Fl_Valuator(x, y, w, h, l) {
  style(default_style);
  a1 = 45;
  a2 = 315;
}

//
// End of "$Id: Fl_Dial.cxx,v 1.19 1999/10/27 08:40:54 bill Exp $".
//
