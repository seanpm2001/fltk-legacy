//
// "$Id: Fl_Menu_SW.cxx,v 1.2 1999/03/18 22:59:08 carl Exp $"
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

#include <FL/Fl_Menu_.H>

void Fl_Menu_::textfont(uchar s) {
  mstyle(&_style);
  MENU_STYLE->sbf |= bf(TEXTFONT);
  MENU_STYLE->menu(TEXTFONT)=s;
}

void Fl_Menu_::textsize(uchar s) {
  mstyle(&_style);
  MENU_STYLE->sbf |= bf(TEXTSIZE);
  MENU_STYLE->menu(TEXTSIZE)=s;
}

void Fl_Menu_::textcolor(uchar n) {
  mstyle(&_style);
  MENU_STYLE->sbf |= bf(TEXTCOLOR);
  MENU_STYLE->menu(TEXTCOLOR)=n;
}

void Fl_Menu_::down_box(Fl_Boxtype b) {
  mstyle(&_style);
  MENU_STYLE->sbf |= bf(DOWN_BOX);
  MENU_STYLE->menu(DOWN_BOX)=b;
}

void Fl_Menu_::down_color(uchar c) {selection_color(c);}

