//
// "$Id: Fl_Tabs.cxx,v 1.38 2000/04/10 06:45:45 bill Exp $"
//
// Tab widget for the Fast Light Tool Kit (FLTK).
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

// This is the "file card tabs" interface to allow you to put lots and lots
// of buttons and switches in a panel, as popularized by many toolkits.

// Each child widget is a card, and it's label() is printed on the card tab.
// Clicking the tab makes that card visible.

#include <FL/Fl.H>
#include <FL/Fl_Tabs.H>
#include <FL/fl_draw.H>

#define BORDER 10
#define TABSLOPE 8

// return the left edges of each tab (plus a fake left edge for a tab
// past the right-hand one).  These position are actually of the left
// edge of the slope.  They are either seperated by the correct distance
// or by TABSLOPE or by zero.
// Return value is the index of the selected item.

int Fl_Tabs::tab_positions(int* p, int* w) {
  int selected = -1;
  Fl_Widget*const* a = array();
  int i;
  p[0] = 0;
  for (i=0; i<children(); i++) {
    Fl_Widget* o = *a++;
    if (o->visible()) selected = i;
    if (o->label()) {
      int wt = 0; int ht = 0; o->measure_label(wt,ht);
      w[i] = wt+TABSLOPE;
      if (2*TABSLOPE > w[i]) w[i] = 2*TABSLOPE;
    } else 
      w[i] = 2*TABSLOPE;
    p[i+1] = p[i]+w[i];
  }
  int r = this->w()-TABSLOPE-1;
  if (p[i] <= r) return selected;
  // uh oh, they are too big:
  // pack them against right edge:
  p[i] = r;
  for (i = children(); i--;) {
    int l = r-w[i];
    if (p[i+1]-TABSLOPE < l) l = p[i+1]-TABSLOPE;
    if (p[i] <= l) break;
    p[i] = l;
    r -= TABSLOPE;
  }
  // pack them against left edge and truncate width if they still don't fit:
  for (i = 0; i<children(); i++) {
    if (p[i] >= i*TABSLOPE) break;
    p[i] = i*TABSLOPE;
    int W = this->w()-1-TABSLOPE*(children()-i) - p[i];
    if (w[i] > W) w[i] = W;
  }
  // adjust edges according to visiblity:
  for (i = children(); i > selected; i--) {
    p[i] = p[i-1]+w[i-1];
  }
  return selected;
}

// return space needed for tabs.  Negative to put them on the bottom:
int Fl_Tabs::tab_height() {
  int H = h();
  int H2 = y();
  Fl_Widget*const* a = array();
  for (int i=children(); i--;) {
    Fl_Widget* o = *a++;
    if (o->y() < y()+H) H = o->y()-y();
    if (o->y()+o->h() > H2) H2 = o->y()+o->h();
  }
  H2 = y()+h()-H2;
  int dx=0; int dy=0; int dw=0; int dh=0; box()->inset(dx,dy,dw,dh);
  if (H2 > H) {
    H = H2-dy;
    return (H <= 0) ? 0 : -H-2;
  } else {
    H = H-dy;
    return (H <= 0) ? 0 : H+1;
  }
}

// this is used by fluid to pick tabs:
Fl_Widget *Fl_Tabs::which(int event_x, int event_y) {
  int H = tab_height();
  if (H < 0) {
    if (event_y > y()+h() || event_y < y()+h()+H) return 0;
  } else {
    if (event_y > y()+H || event_y < y()) return 0;
  }
  if (event_x < x()) return 0;
  int p[128], w[128];
  int selected = tab_positions(p, w);
  int d = (event_y-(H>=0?y():y()+h()))*TABSLOPE/H;
  for (int i=0; i<children(); i++) {
    if (event_x < x()+p[i+1]+(i<selected ? TABSLOPE-d : d)) return child(i);
  }
  return 0;
}

int Fl_Tabs::handle(int event) {

  Fl_Widget *selected = this->value();
  int i;
  int backwards = 0;

  switch (event) {

  case FL_FOCUS:
    if (contains(Fl::focus())) {
      // this is called to indicate that some child got the focus
      /*if (Fl::focus() == this || focus() < 0)*/ damage(FL_DAMAGE_EXPOSE);
      focus(Fl::focus() == this ? -1 : 0);
      return 1;
    }
    // otherwise this indicates that somebody is trying to give focus to this
    switch (navigation_key()) {
    default:
      if (focus() < 0) break;
      // else fall through...
    case FL_Left:
    case FL_Up:
      if (selected) return send(event, *selected);
      break;
    case FL_Right:
    case FL_Down:
      break;
    } return 1;

  case FL_UNFOCUS:
    if (focus() < 0) damage(FL_DAMAGE_EXPOSE);
    return 1;

  // handle mouse events in the tabs:
  case FL_PUSH: {
    int H = tab_height();
    if (H >= 0) {
      if (Fl::event_y() > y()+H) break;
    } else {
      if (Fl::event_y() < y()+h()+H) break;
    }}
  case FL_DRAG:
  case FL_RELEASE:
    selected = which(Fl::event_x(), Fl::event_y());
    if (event == FL_RELEASE && !Fl::pushed()) {
      push(0);
      if (selected && value(selected)) do_callback();
    } else {
      push(selected);
    }
    return 1;

  case FL_KEYBOARD:
    switch (Fl::event_key()) {
    case ' ':
    case FL_Right:
      break;
    case FL_BackSpace:
    case FL_Left:
      backwards = 1;
      break;
    default:
      return 0;
    }
  MOVE:
    for (i = children()-1; i>0; i--) if (child(i)->visible()) break;
    if (backwards) {i = i ? i-1 : children()-1;}
    else {i++; if (i >= children()) i = 0;}
    value(child(i)); do_callback();
    return 1;

  case FL_SHORTCUT:
    if (Fl::event_key()==FL_Tab && Fl::event_state(FL_CTRL)) {
      backwards = Fl::event_state(FL_SHIFT);
      goto MOVE;
    }
    if (!selected) return 0;
    if (send(event, *selected)) return 1;
    if (!contains(Fl::focus())) return 0;
    switch (navigation_key()) {
    case FL_Right:
    case FL_Down:
      if (focus() < 0 && selected) return send(FL_FOCUS, *selected);
      else return 0;
    case FL_Left:
    case FL_Up:
      if (focus() >= 0) {Fl::focus(this); return 1;}
      else return 0;
    default:
      return 0;
    }
  }  

  if (selected) return send(event, *selected);
  return 0;
}

int Fl_Tabs::push(Fl_Widget *o) {
  if (push_ == o) return 0;
  if (push_ && !push_->visible() || o && !o->visible())
    damage(FL_DAMAGE_EXPOSE);
  push_ = o;
  return 1;
}

// The value() is the first visible child (or the last child if none
// are visible) and this also hides any other children.
// This allows the tabs to be deleted, moved to other groups, and
// show()/hide() called without it screwing up.
Fl_Widget* Fl_Tabs::value() {
  Fl_Widget* v = 0;
  Fl_Widget*const* a = array();
  for (int i=children(); i--;) {
    Fl_Widget* o = *a++;
    if (v) o->hide();
    else if (o->visible()) v = o;
    else if (!i) {o->show(); v = o;}
  }
  return v;
}

// Setting the value hides all other children, and makes this one
// visible, iff it is really a child:
int Fl_Tabs::value(Fl_Widget *newvalue) {
  int setfocus = !focused() && contains(Fl::focus());
  Fl_Widget*const* a = array();
  for (int i=children(); i--;) {
    Fl_Widget* o = *a++;
    if (o == newvalue) {
      if (o->visible()) return 0; // no change
      o->show();
      if (setfocus) o->take_focus();
    } else {
      o->hide();
    }
  }
  return 1;
}

enum {LEFT, RIGHT, SELECTED};

static int H;
static int p[128];
void Fl_Tabs::draw() {
  Fl_Widget *v = value();

  H = tab_height();
  if (damage() & FL_DAMAGE_ALL) { // redraw the entire thing:
    fl_clip(x(), y(), w(), h());
    if (v) draw_child(*v);
    parent()->draw_group_box();
    fl_pop_clip();
  } else { // redraw the child
    if (v) update_child(*v);
  }

  // draw the tabs if needed:
  if (damage() & (FL_DAMAGE_EXPOSE|FL_DAMAGE_ALL)) {
    int w[128];
    int selected = tab_positions(p,w);
    int i;

    Fl_Widget*const* a = array();
    for (i=0; i<selected; i++)
      draw_tab(x()+p[i], x()+p[i+1], w[i], H, a[i], LEFT);
    for (i=children()-1; i > selected; i--)
      draw_tab(x()+p[i], x()+p[i+1], w[i], H, a[i], RIGHT);
    if (v) {
      i = selected;
      draw_tab(x()+p[i], x()+p[i+1], w[i], H, a[i], SELECTED);
    } else {
      // draw the edge when no selection:
      fl_color(H >= 0 ? FL_LIGHT3 : FL_DARK3);
	  fl_xyline(x(), H >= 0 ? y()+H : y()+h()+H, x()+this->w());
    }

  }
}

// Call the draw method, handle the clip out
void Fl_Tabs::draw_n_clip()
{
  draw();
  // The tabs widget build itself the clip_out region with a special shape
  if (damage()&FL_DAMAGE_ALL) {
    fl_clip_out(x(), y()+(H>=0?0:h()+H), p[children()]+TABSLOPE, (H>=0?H:-H));
    fl_clip_out(x(), y()+(H>0?H:0), this->w(), h()-(H>=0?H:-H-1));
  }
}

void Fl_Tabs::draw_tab(int x1, int x2, int W, int H, Fl_Widget* o, int what) {
  if (x2 < x1+W) {
    if (what == LEFT) {
      if (x1+W < x2+TABSLOPE) x2 = x1+W;
      else x2 += TABSLOPE;
    } else {
      if (x1+W < x2+TABSLOPE) x1 = x2-W;
      else x1 -= TABSLOPE;
    }
  }
  int sel = (what == SELECTED);
  fl_color(o->color());
  if (H >= 0) {
    fl_polygon(x1, y()+H+sel, x1+TABSLOPE, y(), x2, y(),
	       x2+TABSLOPE, y()+H+sel);
    fl_color(!sel && o==push_ ? FL_DARK3 : FL_LIGHT3);
    fl_line(x1, y()+H, x1+TABSLOPE, y(), x2, y());
    if (sel) {
      if (x1>x()) fl_xyline(x(), y()+H, x1);
      if (x2+TABSLOPE < x()+w()-1) fl_xyline(x2+TABSLOPE, y()+H, x()+w()-1);
    }
    fl_color(!sel && o==push_ ? FL_LIGHT3 : FL_DARK3);
    fl_line(x2, y(), x2+TABSLOPE, y()+H);
  } else {
    fl_polygon(x1, y()+h()+H-sel, x1+TABSLOPE, y()+h(), x2, y()+h(),
	       x2+TABSLOPE, y()+h()+H-sel);
    fl_color(!sel && o==push_ ? FL_DARK3 : FL_LIGHT3);
    fl_line(x1+TABSLOPE, y()+h()-1, x2, y()+h()-1, x2+TABSLOPE, y()+h()+H);
    if (sel) {
      if (x1>x()) fl_xyline(x(), y()+h()+H, x1);
      if (x2+TABSLOPE < x()+w()-1) fl_xyline(x2+TABSLOPE, y()+h()+H,x()+w()-1);
    }
    fl_color(!sel && o==push_ ? FL_LIGHT3 : FL_DARK3);
    fl_line(x1, y()+h()+H, x1+TABSLOPE, y()+h()-1);
  }
  if (W > TABSLOPE) {
    if (sel && focused()) {
      fl_color(FL_BLACK);
      fl_line_style(FL_DOT);
      fl_rect(x2-W+TABSLOPE,
	      y()+(H<0?h()+H-3:0)+1, W-TABSLOPE,
	      (H<0?-H:H)+1);
      fl_line_style(0);
    }
    o->draw_label(what==LEFT ? x1+TABSLOPE : x2-W+TABSLOPE,
		  y()+(H<0?h()+H-3:0), W-TABSLOPE,
		  (H<0?-H:H)+3, FL_ALIGN_CENTER);
  }
}

static void revert(Fl_Style* s) {
  s->box = FL_THIN_UP_BOX;
}

static Fl_Named_Style* style = new Fl_Named_Style("Tabs", revert, &style);

Fl_Tabs::Fl_Tabs(int X,int Y,int W, int H, const char *l)
  : Fl_Group(X,Y,W,H,l)
{
  style(::style);
  type(FL_TABS);
  push_ = 0;
}

//
// End of "$Id: Fl_Tabs.cxx,v 1.38 2000/04/10 06:45:45 bill Exp $".
//
