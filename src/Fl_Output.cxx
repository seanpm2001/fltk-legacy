//
// "$Id: Fl_Output.cxx,v 1.7 1999/03/14 06:46:33 carl Exp $"
//
// Output widget for the Fast Light Tool Kit (FLTK).
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

// This subclass of Fl_Input_ does not allow user to edit the output.
// Used to display output.

#include <FL/Fl.H>
#include <FL/Fl_Output.H>
#include <FL/fl_draw.H>

#define DEFAULT_STYLE ((Style*)default_style())

Fl_Output::Style Fl_Output::_default_style;

Fl_Output::Style::Style() : Fl_Input_::Style() {
  widget(COLOR) = 51;
}

void Fl_Output::loadstyle() {
  if (!Fl::s_output) {
    Fl::s_output = 1;

    static Fl::Attribute widget_attributes[] = {
      { "label color", LABELCOLOR },
      { "label size", LABELSIZE },
      { "label type", LABELTYPE },
      { "label font", LABELFONT },
      { "output color", COLOR },
      { "selected color", COLOR2 },
      { "box", BOX },
      { 0 }
    };
    Fl::load_attributes("text input output", DEFAULT_STYLE->widget_, widget_attributes);

    static Fl::Attribute input_attributes[] = {
      { "text font", TEXTFONT },
      { "text size", TEXTSIZE },
      { "text color", TEXTCOLOR },
      { "selected text color", SELECTED_TEXTCOLOR },
      { "cursor color", CURSOR_COLOR },
      { 0 }
    };
    Fl::load_attributes("text input output", DEFAULT_STYLE->input_, input_attributes);
  }
}

void Fl_Output::draw() {
  loadstyle();
  Fl_Boxtype b = box() ? box() : FL_DOWN_BOX;
  if (damage() & FL_DAMAGE_ALL) draw_box(b, color());
  Fl_Input_::drawtext(x()+Fl::box_dx(b)+3, y()+Fl::box_dy(b),
		      w()-Fl::box_dw(b)-6, h()-Fl::box_dh(b));
}

int Fl_Output::handle(int event) {
  if (event == FL_FOCUS) return 0;
  Fl_Boxtype b = box() ? box() : FL_DOWN_BOX;
  return Fl_Input_::handletext(event,
	x()+Fl::box_dx(b)+3, y()+Fl::box_dy(b),
	w()-Fl::box_dw(b)-6, h()-Fl::box_dh(b));
}

//
// End of "$Id: Fl_Output.cxx,v 1.7 1999/03/14 06:46:33 carl Exp $".
//
