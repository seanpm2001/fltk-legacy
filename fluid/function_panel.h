//
// "$Id$"
//
// Code dialogs for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-2010 by Bill Spitzak and others.
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
// Please report all bugs and problems on the following page:
//
//     http://www.fltk.org/str.php
//

// generated by Fast Light User Interface Designer (fluid) version 1.0300

#ifndef function_panel_h
#define function_panel_h
#include <fltk3/run.h>
#include <fltk3/DoubleWindow.h>
extern Fl_Double_Window *function_panel;
#include <fltk3/Group.h>
#include <fltk3/Choice.h>
extern Fl_Choice *f_public_member_choice;
extern Fl_Choice *f_public_choice;
#include <fltk3/LightButton.h>
extern Fl_Light_Button *f_c_button;
#include <fltk3/Box.h>
#include <fltk3/Input.h>
extern Fl_Input *f_name_input;
extern Fl_Input *f_return_type_input;
#include <fltk3/ReturnButton.h>
extern Fl_Return_Button *f_panel_ok;
#include <fltk3/Button.h>
extern Fl_Button *f_panel_cancel;
#include <fltk3/TextEditor.h>
extern Fl_Text_Editor *f_comment_input;
Fl_Double_Window* make_function_panel();
extern Fl_Menu_Item menu_f_public_member_choice[];
extern Fl_Menu_Item menu_f_public_choice[];
extern Fl_Double_Window *code_panel;
#include "CodeEditor.h"
extern CodeEditor *code_input;
extern Fl_Return_Button *code_panel_ok;
extern Fl_Button *code_panel_cancel;
Fl_Double_Window* make_code_panel();
extern Fl_Double_Window *codeblock_panel;
extern Fl_Input *code_before_input;
extern Fl_Input *code_after_input;
extern Fl_Return_Button *codeblock_panel_ok;
extern Fl_Button *codeblock_panel_cancel;
Fl_Double_Window* make_codeblock_panel();
extern Fl_Double_Window *declblock_panel;
extern Fl_Choice *declblock_public_choice;
extern Fl_Light_Button *declblock_public_button_x;
extern Fl_Input *decl_before_input;
extern Fl_Input *decl_after_input;
extern Fl_Return_Button *declblock_panel_ok;
extern Fl_Button *declblock_panel_cancel;
Fl_Double_Window* make_declblock_panel();
extern Fl_Menu_Item menu_declblock_public_choice[];
extern Fl_Double_Window *decl_panel;
extern Fl_Choice *decl_choice;
extern Fl_Choice *decl_class_choice;
extern Fl_Input *decl_input;
extern Fl_Return_Button *decl_panel_ok;
extern Fl_Button *decl_panel_cancel;
extern Fl_Text_Editor *decl_comment_input;
Fl_Double_Window* make_decl_panel();
extern Fl_Menu_Item menu_decl_choice[];
extern Fl_Menu_Item menu_decl_class_choice[];
extern Fl_Double_Window *data_panel;
extern Fl_Choice *data_choice;
extern Fl_Choice *data_class_choice;
extern Fl_Input *data_input;
extern Fl_Input *data_filename;
extern Fl_Button *data_filebrowser;
extern Fl_Return_Button *data_panel_ok;
extern Fl_Button *data_panel_cancel;
extern Fl_Text_Editor *data_comment_input;
Fl_Double_Window* make_data_panel();
extern Fl_Menu_Item menu_data_choice[];
extern Fl_Menu_Item menu_data_class_choice[];
extern Fl_Double_Window *class_panel;
extern Fl_Light_Button *c_public_button;
extern Fl_Input *c_name_input;
extern Fl_Input *c_subclass_input;
extern Fl_Text_Editor *c_comment_input;
extern Fl_Return_Button *c_panel_ok;
extern Fl_Button *c_panel_cancel;
Fl_Double_Window* make_class_panel();
extern Fl_Double_Window *comment_panel;
extern CodeEditor *comment_input;
extern Fl_Return_Button *comment_panel_ok;
extern Fl_Button *comment_panel_cancel;
extern Fl_Light_Button *comment_in_source;
extern Fl_Light_Button *comment_in_header;
#include <fltk3/MenuButton.h>
extern Fl_Menu_Button *comment_predefined;
extern Fl_Button *comment_load;
Fl_Double_Window* make_comment_panel();
void type_make_cb(fltk3::Widget*,void*d);
#include <fltk3/Window.h>
extern Fl_Window *widgetbin_panel;
Fl_Window* make_widgetbin();
extern void toggle_sourceview_cb(Fl_Double_Window*, void*);
extern Fl_Double_Window *sourceview_panel;
#include <fltk3/TabGroup.h>
extern void update_sourceview_position_cb(Fl_Tabs*, void*);
extern Fl_Tabs *sv_tab;
extern CodeViewer *sv_source;
extern CodeViewer *sv_header;
extern void update_sourceview_cb(Fl_Button*, void*);
extern Fl_Light_Button *sv_autorefresh;
extern Fl_Light_Button *sv_autoposition;
extern void toggle_sourceview_b_cb(Fl_Button*, void*);
Fl_Double_Window* make_sourceview();
#endif

//
// End of "$Id$".
//
