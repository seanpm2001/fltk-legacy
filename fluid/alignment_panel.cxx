//
// "$Id$"
//
// Setting and shell dialogs for the Fast Light Tool Kit (FLTK).
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

#include "alignment_panel.h"
#include <fltk3/Preferences.h>
#include <fltk3/ask.h>
Fl_Text_Buffer *shell_run_buffer; 

fltk3::DoubleWindow *project_window=(fltk3::DoubleWindow *)0;

static void cb_Close(fltk3::Button*, void*) {
  project_window->hide();
}

fltk3::Input *header_file_input=(fltk3::Input *)0;

fltk3::Input *code_file_input=(fltk3::Input *)0;

fltk3::CheckButton *include_H_from_C_button=(fltk3::CheckButton *)0;

fltk3::CheckButton *use_FL_COMMAND_button=(fltk3::CheckButton *)0;

fltk3::Choice *i18n_type_chooser=(fltk3::Choice *)0;

fltk3::MenuItem menu_i18n_type_chooser[] = {
 {"None", 0,  0, 0, 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {"GNU gettext", 0,  0, 0, 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {"POSIX catgets", 0,  0, 0, 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

fltk3::Input *i18n_include_input=(fltk3::Input *)0;

fltk3::Input *i18n_file_input=(fltk3::Input *)0;

fltk3::IntInput *i18n_set_input=(fltk3::IntInput *)0;

fltk3::Input *i18n_function_input=(fltk3::Input *)0;

fltk3::DoubleWindow* make_project_window() {
  { project_window = new fltk3::DoubleWindow(399, 252, "Project Settings");
    { fltk3::Button* o = new fltk3::Button(328, 216, 60, 25, "Close");
      o->tooltip("Close this dialog.");
      o->callback((fltk3::Callback*)cb_Close);
    } // fltk3::Button* o
    { Fl_Tabs* o = new Fl_Tabs(10, 10, 378, 195);
      o->selection_color((fltk3::Color)12);
      { fltk3::Group* o = new fltk3::Group(10, 36, 378, 169, "Output");
        o->hide();
        { fltk3::Box* o = new fltk3::Box(100, 49, 236, 49, "Use \"name.ext\" to set a file name or just \".ext\" to set extension.");
          o->align(fltk3::Align(fltk3::ALIGN_WRAP|fltk3::ALIGN_INSIDE));
        } // fltk3::Box* o
        { header_file_input = new fltk3::Input(99, 103, 272, 20, "Header File:");
          header_file_input->tooltip("The name of the generated header file.");
          header_file_input->box(fltk3::THIN_DOWN_BOX);
          header_file_input->labelfont(1);
          header_file_input->textfont(4);
          header_file_input->callback((fltk3::Callback*)header_input_cb, (void*)(1));
          header_file_input->when(fltk3::WHEN_CHANGED);
        } // fltk3::Input* header_file_input
        { code_file_input = new fltk3::Input(100, 128, 272, 20, "Code File:");
          code_file_input->tooltip("The name of the generated code file.");
          code_file_input->box(fltk3::THIN_DOWN_BOX);
          code_file_input->labelfont(1);
          code_file_input->textfont(4);
          code_file_input->callback((fltk3::Callback*)code_input_cb, (void*)(1));
          code_file_input->when(fltk3::WHEN_CHANGED);
        } // fltk3::Input* code_file_input
        { include_H_from_C_button = new fltk3::CheckButton(100, 153, 272, 20, "Include Header from Code");
          include_H_from_C_button->tooltip("Include the header file from the code file.");
          include_H_from_C_button->down_box(fltk3::DOWN_BOX);
          include_H_from_C_button->callback((fltk3::Callback*)include_H_from_C_button_cb);
        } // fltk3::CheckButton* include_H_from_C_button
        { use_FL_COMMAND_button = new fltk3::CheckButton(100, 176, 272, 20, "Menu shortcuts use fltk3::COMMAND");
          use_FL_COMMAND_button->tooltip("Replace fltk3::CTRL with fltk3::COMMAND when generating menu shortcut code.");
          use_FL_COMMAND_button->down_box(fltk3::DOWN_BOX);
          use_FL_COMMAND_button->callback((fltk3::Callback*)use_FL_COMMAND_button_cb);
        } // fltk3::CheckButton* use_FL_COMMAND_button
        o->end();
      } // fltk3::Group* o
      { fltk3::Group* o = new fltk3::Group(10, 36, 378, 169, "Internationalization");
        { i18n_type_chooser = new fltk3::Choice(100, 48, 136, 25, "Use:");
          i18n_type_chooser->tooltip("Type of internationalization to use.");
          i18n_type_chooser->box(fltk3::THIN_UP_BOX);
          i18n_type_chooser->down_box(fltk3::BORDER_BOX);
          i18n_type_chooser->labelfont(1);
          i18n_type_chooser->callback((fltk3::Callback*)i18n_type_cb);
          i18n_type_chooser->menu(menu_i18n_type_chooser);
        } // fltk3::Choice* i18n_type_chooser
        { i18n_include_input = new fltk3::Input(100, 78, 272, 20, "#include:");
          i18n_include_input->tooltip("The include file for internationalization.");
          i18n_include_input->box(fltk3::THIN_DOWN_BOX);
          i18n_include_input->labelfont(1);
          i18n_include_input->textfont(4);
          i18n_include_input->callback((fltk3::Callback*)i18n_text_cb);
        } // fltk3::Input* i18n_include_input
        { i18n_file_input = new fltk3::Input(100, 104, 272, 20, "File:");
          i18n_file_input->tooltip("The name of the message catalog.");
          i18n_file_input->box(fltk3::THIN_DOWN_BOX);
          i18n_file_input->labelfont(1);
          i18n_file_input->textfont(4);
          i18n_file_input->callback((fltk3::Callback*)i18n_text_cb);
        } // fltk3::Input* i18n_file_input
        { i18n_set_input = new fltk3::IntInput(100, 128, 272, 20, "Set:");
          i18n_set_input->tooltip("The message set number.");
          i18n_set_input->type(2);
          i18n_set_input->box(fltk3::THIN_DOWN_BOX);
          i18n_set_input->labelfont(1);
          i18n_set_input->textfont(4);
          i18n_set_input->callback((fltk3::Callback*)i18n_int_cb);
        } // fltk3::IntInput* i18n_set_input
        { i18n_function_input = new fltk3::Input(100, 103, 272, 20, "Function:");
          i18n_function_input->tooltip("The function to call to internationalize the labels and tooltips.");
          i18n_function_input->box(fltk3::THIN_DOWN_BOX);
          i18n_function_input->labelfont(1);
          i18n_function_input->textfont(4);
          i18n_function_input->callback((fltk3::Callback*)i18n_text_cb);
        } // fltk3::Input* i18n_function_input
        o->end();
      } // fltk3::Group* o
      o->end();
    } // Fl_Tabs* o
    project_window->set_modal();
    project_window->end();
  } // fltk3::DoubleWindow* project_window
  return project_window;
}
void scheme_cb(fltk3::Choice *, void *); 

fltk3::DoubleWindow *settings_window=(fltk3::DoubleWindow *)0;

fltk3::Choice *scheme_choice=(fltk3::Choice *)0;

fltk3::MenuItem menu_scheme_choice[] = {
 {"Default", 0,  0, 0, 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {"None", 0,  0, 0, 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {"Plastic", 0,  0, 0, 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {"GTK+", 0,  0, 0, 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

fltk3::CheckButton *tooltips_button=(fltk3::CheckButton *)0;

static void cb_tooltips_button(fltk3::CheckButton*, void*) {
  Fl_Tooltip::enable(tooltips_button->value());
fluid_prefs.set("show_tooltips", tooltips_button->value());
}

fltk3::CheckButton *completion_button=(fltk3::CheckButton *)0;

static void cb_completion_button(fltk3::CheckButton*, void*) {
  fluid_prefs.set("show_completion_dialogs", completion_button->value());
}

fltk3::CheckButton *openlast_button=(fltk3::CheckButton *)0;

static void cb_openlast_button(fltk3::CheckButton*, void*) {
  fluid_prefs.set("open_previous_file", openlast_button->value());
}

fltk3::CheckButton *prevpos_button=(fltk3::CheckButton *)0;

static void cb_prevpos_button(fltk3::CheckButton*, void*) {
  fluid_prefs.set("prev_window_pos", prevpos_button->value());
}

fltk3::CheckButton *show_comments_button=(fltk3::CheckButton *)0;

static void cb_show_comments_button(fltk3::CheckButton*, void*) {
  show_comments = show_comments_button->value();
fluid_prefs.set("show_comments", show_comments);
redraw_browser();
}

Fl_Spinner *recent_spinner=(Fl_Spinner *)0;

static void cb_recent_spinner(Fl_Spinner*, void*) {
  fluid_prefs.set("recent_files", recent_spinner->value());
load_history();
}

static void cb_Close1(fltk3::Button*, void*) {
  settings_window->hide();
}

fltk3::DoubleWindow* make_settings_window() {
  { settings_window = new fltk3::DoubleWindow(339, 241, "GUI Settings");
    { scheme_choice = new fltk3::Choice(116, 10, 115, 25, "Scheme: ");
      scheme_choice->down_box(fltk3::BORDER_BOX);
      scheme_choice->labelfont(1);
      scheme_choice->callback((fltk3::Callback*)scheme_cb);
      scheme_choice->menu(menu_scheme_choice);
      int s;
      fluid_prefs.get("scheme", s, 0);
      scheme_choice->value(s);
      scheme_cb(0, 0);
    } // fltk3::Choice* scheme_choice
    { fltk3::Group* o = new fltk3::Group(116, 43, 220, 126);
      o->labelfont(1);
      o->align(fltk3::Align(fltk3::ALIGN_CENTER));
      { fltk3::Box* o = new fltk3::Box(116, 43, 1, 25, "Options: ");
        o->labelfont(1);
        o->align(fltk3::Align(fltk3::ALIGN_LEFT));
      } // fltk3::Box* o
      { tooltips_button = new fltk3::CheckButton(116, 43, 113, 25, "Show Tooltips");
        tooltips_button->down_box(fltk3::DOWN_BOX);
        tooltips_button->callback((fltk3::Callback*)cb_tooltips_button);
        int b;
        fluid_prefs.get("show_tooltips", b, 1);
        tooltips_button->value(b);
        Fl_Tooltip::enable(b);
      } // fltk3::CheckButton* tooltips_button
      { completion_button = new fltk3::CheckButton(116, 68, 186, 25, "Show Completion Dialogs");
        completion_button->down_box(fltk3::DOWN_BOX);
        completion_button->callback((fltk3::Callback*)cb_completion_button);
        int b;
        fluid_prefs.get("show_completion_dialogs", b, 1);
        completion_button->value(b);
      } // fltk3::CheckButton* completion_button
      { openlast_button = new fltk3::CheckButton(116, 93, 214, 25, "Open Previous File on Startup");
        openlast_button->down_box(fltk3::DOWN_BOX);
        openlast_button->callback((fltk3::Callback*)cb_openlast_button);
        int b;
        fluid_prefs.get("open_previous_file", b, 0);
        openlast_button->value(b);
      } // fltk3::CheckButton* openlast_button
      { prevpos_button = new fltk3::CheckButton(116, 118, 209, 25, "Remember Window Positions");
        prevpos_button->down_box(fltk3::DOWN_BOX);
        prevpos_button->callback((fltk3::Callback*)cb_prevpos_button);
        int b;
        fluid_prefs.get("prev_window_pos", b, 1);
        prevpos_button->value(b);
      } // fltk3::CheckButton* prevpos_button
      { show_comments_button = new fltk3::CheckButton(116, 143, 209, 25, "Show Comments in Browser");
        show_comments_button->down_box(fltk3::DOWN_BOX);
        show_comments_button->callback((fltk3::Callback*)cb_show_comments_button);
        fluid_prefs.get("show_comments", show_comments, 1);
        show_comments_button->value(show_comments);
      } // fltk3::CheckButton* show_comments_button
      o->end();
    } // fltk3::Group* o
    { recent_spinner = new Fl_Spinner(115, 173, 40, 25, "# Recent Files: ");
      recent_spinner->labelfont(1);
      recent_spinner->callback((fltk3::Callback*)cb_recent_spinner);
      recent_spinner->when(fltk3::WHEN_CHANGED);
      int c;
      fluid_prefs.get("recent_files", c, 5);
      recent_spinner->maximum(10);
      recent_spinner->value(c);
    } // Fl_Spinner* recent_spinner
    { fltk3::Button* o = new fltk3::Button(266, 205, 64, 25, "Close");
      o->tooltip("Close this dialog.");
      o->callback((fltk3::Callback*)cb_Close1);
    } // fltk3::Button* o
    settings_window->set_non_modal();
    settings_window->end();
  } // fltk3::DoubleWindow* settings_window
  return settings_window;
}

fltk3::DoubleWindow *shell_window=(fltk3::DoubleWindow *)0;

fltk3::Input *shell_command_input=(fltk3::Input *)0;

static void cb_shell_command_input(fltk3::Input*, void*) {
  fluid_prefs.set("shell_command", shell_command_input->value());
}

fltk3::CheckButton *shell_writecode_button=(fltk3::CheckButton *)0;

static void cb_shell_writecode_button(fltk3::CheckButton*, void*) {
  fluid_prefs.set("shell_writecode", shell_writecode_button->value());
}

fltk3::CheckButton *shell_writemsgs_button=(fltk3::CheckButton *)0;

static void cb_shell_writemsgs_button(fltk3::CheckButton*, void*) {
  fluid_prefs.set("shell_writemsgs", shell_writemsgs_button->value());
}

fltk3::CheckButton *shell_savefl_button=(fltk3::CheckButton *)0;

static void cb_shell_savefl_button(fltk3::CheckButton*, void*) {
  fluid_prefs.set("shell_savefl", shell_savefl_button->value());
}

static void cb_Cancel(fltk3::Button*, void*) {
  shell_window->hide();
}

fltk3::DoubleWindow *shell_run_window=(fltk3::DoubleWindow *)0;

Fl_Text_Display *shell_run_display=(Fl_Text_Display *)0;

fltk3::ReturnButton *shell_run_button=(fltk3::ReturnButton *)0;

static void cb_shell_run_button(fltk3::ReturnButton*, void*) {
  shell_run_window->hide();
}

fltk3::DoubleWindow* make_shell_window() {
  { shell_window = new fltk3::DoubleWindow(365, 125, "Shell Command");
    { shell_command_input = new fltk3::Input(10, 27, 347, 25, "Command:");
      shell_command_input->labelfont(1);
      shell_command_input->callback((fltk3::Callback*)cb_shell_command_input);
      shell_command_input->align(fltk3::Align(fltk3::ALIGN_TOP_LEFT));
      char buf[1024];
      fluid_prefs.get("shell_command", buf, "", sizeof(buf));
      shell_command_input->value(buf);
    } // fltk3::Input* shell_command_input
    { shell_writecode_button = new fltk3::CheckButton(128, 61, 93, 19, "Write Code");
      shell_writecode_button->down_box(fltk3::DOWN_BOX);
      shell_writecode_button->callback((fltk3::Callback*)cb_shell_writecode_button);
      int b;
      fluid_prefs.get("shell_writecode", b, 1);
      shell_writecode_button->value(b);
    } // fltk3::CheckButton* shell_writecode_button
    { shell_writemsgs_button = new fltk3::CheckButton(231, 61, 126, 19, "Write Messages");
      shell_writemsgs_button->down_box(fltk3::DOWN_BOX);
      shell_writemsgs_button->callback((fltk3::Callback*)cb_shell_writemsgs_button);
      int b;
      fluid_prefs.get("shell_writemsgs", b, 0);
      shell_writemsgs_button->value(b);
    } // fltk3::CheckButton* shell_writemsgs_button
    { shell_savefl_button = new fltk3::CheckButton(10, 62, 108, 19, "Save .FL File");
      shell_savefl_button->down_box(fltk3::DOWN_BOX);
      shell_savefl_button->callback((fltk3::Callback*)cb_shell_savefl_button);
      int b;
      fluid_prefs.get("shell_savefl", b, 1);
      shell_savefl_button->value(b);
    } // fltk3::CheckButton* shell_savefl_button
    { fltk3::ReturnButton* o = new fltk3::ReturnButton(132, 90, 143, 25, "Run Command");
      o->callback((fltk3::Callback*)do_shell_command);
    } // fltk3::ReturnButton* o
    { fltk3::Button* o = new fltk3::Button(285, 90, 72, 25, "Cancel");
      o->callback((fltk3::Callback*)cb_Cancel);
    } // fltk3::Button* o
    shell_window->end();
  } // fltk3::DoubleWindow* shell_window
  { shell_run_window = new fltk3::DoubleWindow(555, 430, "Shell Command Output");
    { shell_run_display = new Fl_Text_Display(10, 10, 535, 375);
      shell_run_display->box(fltk3::DOWN_BOX);
      shell_run_display->textfont(4);
      fltk3::Group::current()->resizable(shell_run_display);
      shell_run_buffer = new Fl_Text_Buffer();
      shell_run_display->buffer(shell_run_buffer);
    } // Fl_Text_Display* shell_run_display
    { shell_run_button = new fltk3::ReturnButton(468, 395, 77, 25, "Close");
      shell_run_button->callback((fltk3::Callback*)cb_shell_run_button);
    } // fltk3::ReturnButton* shell_run_button
    shell_run_window->end();
  } // fltk3::DoubleWindow* shell_run_window
  return shell_run_window;
}

fltk3::DoubleWindow *grid_window=(fltk3::DoubleWindow *)0;

fltk3::IntInput *horizontal_input=(fltk3::IntInput *)0;

fltk3::IntInput *vertical_input=(fltk3::IntInput *)0;

fltk3::IntInput *snap_input=(fltk3::IntInput *)0;

fltk3::CheckButton *guides_toggle=(fltk3::CheckButton *)0;

static void cb_Close2(fltk3::Button*, void*) {
  grid_window->hide();
}

fltk3::RoundButton *def_widget_size[6]={(fltk3::RoundButton *)0};

fltk3::DoubleWindow* make_layout_window() {
  { grid_window = new fltk3::DoubleWindow(285, 245, "Layout Settings");
    { fltk3::IntInput* o = horizontal_input = new fltk3::IntInput(106, 10, 50, 25, "x");
      horizontal_input->tooltip("Horizontal grid spacing.");
      horizontal_input->type(2);
      horizontal_input->box(fltk3::THIN_DOWN_BOX);
      horizontal_input->callback((fltk3::Callback*)grid_cb, (void*)(1));
      horizontal_input->align(fltk3::Align(fltk3::ALIGN_RIGHT));
      o->when(fltk3::WHEN_RELEASE|fltk3::WHEN_ENTER_KEY);
    } // fltk3::IntInput* horizontal_input
    { fltk3::IntInput* o = vertical_input = new fltk3::IntInput(166, 10, 50, 25, "pixels");
      vertical_input->tooltip("Vertical grid spacing.");
      vertical_input->type(2);
      vertical_input->box(fltk3::THIN_DOWN_BOX);
      vertical_input->callback((fltk3::Callback*)grid_cb, (void*)(2));
      vertical_input->align(fltk3::Align(fltk3::ALIGN_RIGHT));
      o->when(fltk3::WHEN_RELEASE|fltk3::WHEN_ENTER_KEY);
    } // fltk3::IntInput* vertical_input
    { fltk3::IntInput* o = snap_input = new fltk3::IntInput(106, 45, 50, 25, "pixel snap");
      snap_input->tooltip("Snap to grid within this many pixels.");
      snap_input->type(2);
      snap_input->box(fltk3::THIN_DOWN_BOX);
      snap_input->callback((fltk3::Callback*)grid_cb, (void*)(3));
      snap_input->align(fltk3::Align(fltk3::ALIGN_RIGHT));
      o->when(fltk3::WHEN_RELEASE|fltk3::WHEN_ENTER_KEY);
    } // fltk3::IntInput* snap_input
    { guides_toggle = new fltk3::CheckButton(106, 80, 110, 25, "Show Guides");
      guides_toggle->tooltip("Show distance and alignment guides in overlay");
      guides_toggle->down_box(fltk3::DOWN_BOX);
      guides_toggle->callback((fltk3::Callback*)guides_cb, (void*)(4));
    } // fltk3::CheckButton* guides_toggle
    { fltk3::Button* o = new fltk3::Button(215, 210, 60, 25, "Close");
      o->tooltip("Close this dialog.");
      o->callback((fltk3::Callback*)cb_Close2);
    } // fltk3::Button* o
    { fltk3::Box* o = new fltk3::Box(26, 10, 70, 25, "Grid:");
      o->labelfont(1);
      o->align(fltk3::Align(fltk3::ALIGN_RIGHT|fltk3::ALIGN_INSIDE));
    } // fltk3::Box* o
    { fltk3::Box* o = new fltk3::Box(-1, 115, 97, 25, "Widget Size:");
      o->labelfont(1);
      o->align(fltk3::Align(fltk3::ALIGN_RIGHT|fltk3::ALIGN_INSIDE));
    } // fltk3::Box* o
    { fltk3::Group* o = new fltk3::Group(105, 115, 170, 75);
      { def_widget_size[0] = new fltk3::RoundButton(105, 115, 70, 25);
        def_widget_size[0]->type(102);
        def_widget_size[0]->down_box(fltk3::ROUND_DOWN_BOX);
        def_widget_size[0]->callback((fltk3::Callback*)default_widget_size_cb, (void*)(8));
      } // fltk3::RoundButton* def_widget_size[0]
      { fltk3::Box* o = new fltk3::Box(120, 115, 50, 25, "tiny");
        o->labelsize(8);
        o->align(fltk3::Align(fltk3::ALIGN_LEFT|fltk3::ALIGN_INSIDE));
      } // fltk3::Box* o
      { def_widget_size[1] = new fltk3::RoundButton(180, 115, 70, 25);
        def_widget_size[1]->type(102);
        def_widget_size[1]->down_box(fltk3::ROUND_DOWN_BOX);
        def_widget_size[1]->callback((fltk3::Callback*)default_widget_size_cb, (void*)(11));
      } // fltk3::RoundButton* def_widget_size[1]
      { fltk3::Box* o = new fltk3::Box(195, 115, 50, 25, "small");
        o->labelsize(11);
        o->align(fltk3::Align(fltk3::ALIGN_LEFT|fltk3::ALIGN_INSIDE));
      } // fltk3::Box* o
      { def_widget_size[2] = new fltk3::RoundButton(105, 140, 70, 25);
        def_widget_size[2]->type(102);
        def_widget_size[2]->down_box(fltk3::ROUND_DOWN_BOX);
        def_widget_size[2]->callback((fltk3::Callback*)default_widget_size_cb, (void*)(14));
      } // fltk3::RoundButton* def_widget_size[2]
      { fltk3::Box* o = new fltk3::Box(120, 140, 50, 25, "normal");
        o->align(fltk3::Align(fltk3::ALIGN_LEFT|fltk3::ALIGN_INSIDE));
      } // fltk3::Box* o
      { def_widget_size[3] = new fltk3::RoundButton(180, 140, 90, 25);
        def_widget_size[3]->type(102);
        def_widget_size[3]->down_box(fltk3::ROUND_DOWN_BOX);
        def_widget_size[3]->callback((fltk3::Callback*)default_widget_size_cb, (void*)(18));
      } // fltk3::RoundButton* def_widget_size[3]
      { fltk3::Box* o = new fltk3::Box(195, 140, 68, 25, "medium");
        o->labelsize(18);
        o->align(fltk3::Align(fltk3::ALIGN_LEFT|fltk3::ALIGN_INSIDE));
      } // fltk3::Box* o
      { def_widget_size[4] = new fltk3::RoundButton(105, 165, 75, 25);
        def_widget_size[4]->type(102);
        def_widget_size[4]->down_box(fltk3::ROUND_DOWN_BOX);
        def_widget_size[4]->callback((fltk3::Callback*)default_widget_size_cb, (void*)(24));
      } // fltk3::RoundButton* def_widget_size[4]
      { fltk3::Box* o = new fltk3::Box(120, 165, 64, 25, "large");
        o->labelsize(24);
        o->align(fltk3::Align(fltk3::ALIGN_LEFT|fltk3::ALIGN_INSIDE));
      } // fltk3::Box* o
      { def_widget_size[5] = new fltk3::RoundButton(180, 165, 95, 25);
        def_widget_size[5]->type(102);
        def_widget_size[5]->down_box(fltk3::ROUND_DOWN_BOX);
        def_widget_size[5]->callback((fltk3::Callback*)default_widget_size_cb, (void*)(32));
      } // fltk3::RoundButton* def_widget_size[5]
      { fltk3::Box* o = new fltk3::Box(195, 165, 76, 25, "huge");
        o->labelsize(32);
        o->align(fltk3::Align(fltk3::ALIGN_LEFT|fltk3::ALIGN_INSIDE));
      } // fltk3::Box* o
      o->end();
    } // fltk3::Group* o
    grid_window->set_non_modal();
    grid_window->end();
  } // fltk3::DoubleWindow* grid_window
  return grid_window;
}
/**
   Copy of all options in user and system mode
*/
static int opt[10][2]; 

/**
   Update the UI using the values in the opt array
*/
static void refreshUI() {
  int mode = wUserOrSystem->value();
  wVisibleFocus->value(opt[fltk3::OPTION_VISIBLE_FOCUS][mode]);
  wArrowFocus->value(opt[fltk3::OPTION_ARROW_FOCUS][mode]);
  wShowTooltips->value(opt[fltk3::OPTION_SHOW_TOOLTIPS][mode]);
  wDNDText->value(opt[fltk3::OPTION_DND_TEXT][mode]);
}

/**
   read all preferences and refresh the GUI
*/
static void readPrefs() {
  // read all preferences and refresh the GUI
  {
    Fl_Preferences prefs(Fl_Preferences::SYSTEM, "fltk.org", "fltk");
    Fl_Preferences opt_prefs(prefs, "options");
    opt_prefs.get("ArrowFocus", opt[fltk3::OPTION_ARROW_FOCUS][1], 2);
    opt_prefs.get("VisibleFocus", opt[fltk3::OPTION_VISIBLE_FOCUS][1], 2);
    opt_prefs.get("DNDText", opt[fltk3::OPTION_DND_TEXT][1], 2);
    opt_prefs.get("ShowTooltips", opt[fltk3::OPTION_SHOW_TOOLTIPS][1], 2);
  }
  {
    Fl_Preferences prefs(Fl_Preferences::USER, "fltk.org", "fltk");
    Fl_Preferences opt_prefs(prefs, "options");
    opt_prefs.get("ArrowFocus", opt[fltk3::OPTION_ARROW_FOCUS][0], 2);
    opt_prefs.get("VisibleFocus", opt[fltk3::OPTION_VISIBLE_FOCUS][0], 2);
    opt_prefs.get("DNDText", opt[fltk3::OPTION_DND_TEXT][0], 2);
    opt_prefs.get("ShowTooltips", opt[fltk3::OPTION_SHOW_TOOLTIPS][0], 2);
  }
  refreshUI();
}

/**
   write all preferences using the array
*/
static void writePrefs() {
  // write all preferences using the array
  {
    Fl_Preferences prefs(Fl_Preferences::SYSTEM, "fltk.org", "fltk");
    Fl_Preferences opt_prefs(prefs, "options");
    if (opt[fltk3::OPTION_ARROW_FOCUS][1]==2) opt_prefs.deleteEntry("ArrowFocus");
    else opt_prefs.set("ArrowFocus", opt[fltk3::OPTION_ARROW_FOCUS][1]);
    if (opt[fltk3::OPTION_VISIBLE_FOCUS][1]==2) opt_prefs.deleteEntry("VisibleFocus");
    else opt_prefs.set("VisibleFocus", opt[fltk3::OPTION_VISIBLE_FOCUS][1]);
    if (opt[fltk3::OPTION_DND_TEXT][1]==2) opt_prefs.deleteEntry("DNDText");
    else opt_prefs.set("DNDText", opt[fltk3::OPTION_DND_TEXT][1]);
    if (opt[fltk3::OPTION_SHOW_TOOLTIPS][1]==2) opt_prefs.deleteEntry("ShowTooltips");
    else opt_prefs.set("ShowTooltips", opt[fltk3::OPTION_SHOW_TOOLTIPS][1]);
  }
  {
    Fl_Preferences prefs(Fl_Preferences::USER, "fltk.org", "fltk");
    Fl_Preferences opt_prefs(prefs, "options");
    if (opt[fltk3::OPTION_ARROW_FOCUS][0]==2) opt_prefs.deleteEntry("ArrowFocus");
    else opt_prefs.set("ArrowFocus", opt[fltk3::OPTION_ARROW_FOCUS][0]);
    if (opt[fltk3::OPTION_VISIBLE_FOCUS][0]==2) opt_prefs.deleteEntry("VisibleFocus");
    else opt_prefs.set("VisibleFocus", opt[fltk3::OPTION_VISIBLE_FOCUS][0]);
    if (opt[fltk3::OPTION_DND_TEXT][0]==2) opt_prefs.deleteEntry("DNDText");
    else opt_prefs.set("DNDText", opt[fltk3::OPTION_DND_TEXT][0]);
    if (opt[fltk3::OPTION_SHOW_TOOLTIPS][0]==2) opt_prefs.deleteEntry("ShowTooltips");
    else opt_prefs.set("ShowTooltips", opt[fltk3::OPTION_SHOW_TOOLTIPS][0]);
  }
}

void show_global_settings_window() {
  if (!global_settings_window)
    make_global_settings_window();
  readPrefs();
  refreshUI();
  fltk3::message(
  	"WARNING!\n\n"
  	"The following dialog changes the user interface behavior\n"
  	"of ALL FLTK applications, for the current user, or for \n"
  	"ALL users on this machine.\n\n"
  	"Please choose these settings carefully, or reset\n"
  	"user and system settings to \"default\".");
  global_settings_window->show();
}

fltk3::DoubleWindow *global_settings_window=(fltk3::DoubleWindow *)0;

fltk3::Choice *wVisibleFocus=(fltk3::Choice *)0;

static void cb_wVisibleFocus(fltk3::Choice*, void*) {
  int mode = wUserOrSystem->value();
opt[fltk3::OPTION_VISIBLE_FOCUS][mode] = wVisibleFocus->value();
}

fltk3::MenuItem menu_wVisibleFocus[] = {
 {"off", 0,  0, (void*)(0), 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {"on", 0,  0, (void*)(1), 128, fltk3::NORMAL_LABEL, 0, 14, 0},
 {"default", 0,  0, (void*)(2), 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

fltk3::Choice *wArrowFocus=(fltk3::Choice *)0;

static void cb_wArrowFocus(fltk3::Choice*, void*) {
  int mode = wUserOrSystem->value();
opt[fltk3::OPTION_ARROW_FOCUS][mode] = wArrowFocus->value();
}

fltk3::MenuItem menu_wArrowFocus[] = {
 {"off", 0,  0, (void*)(0), 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {"on", 0,  0, (void*)(1), 128, fltk3::NORMAL_LABEL, 0, 14, 0},
 {"default", 0,  0, (void*)(2), 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

fltk3::Choice *wShowTooltips=(fltk3::Choice *)0;

static void cb_wShowTooltips(fltk3::Choice*, void*) {
  int mode = wUserOrSystem->value();
opt[fltk3::OPTION_SHOW_TOOLTIPS][mode] = wShowTooltips->value();
}

fltk3::MenuItem menu_wShowTooltips[] = {
 {"off", 0,  0, (void*)(0), 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {"on", 0,  0, (void*)(1), 128, fltk3::NORMAL_LABEL, 0, 14, 0},
 {"default", 0,  0, (void*)(2), 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

fltk3::Choice *wDNDText=(fltk3::Choice *)0;

static void cb_wDNDText(fltk3::Choice*, void*) {
  int mode = wUserOrSystem->value();
opt[fltk3::OPTION_DND_TEXT][mode] = wDNDText->value();
}

fltk3::MenuItem menu_wDNDText[] = {
 {"off", 0,  0, (void*)(0), 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {"on", 0,  0, (void*)(1), 128, fltk3::NORMAL_LABEL, 0, 14, 0},
 {"default", 0,  0, (void*)(2), 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

fltk3::Choice *wUserOrSystem=(fltk3::Choice *)0;

static void cb_wUserOrSystem(fltk3::Choice*, void*) {
  refreshUI();
}

fltk3::MenuItem menu_wUserOrSystem[] = {
 {"User Settings", 0,  0, (void*)(0), 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {"System Settings", 0,  0, (void*)(1), 0, fltk3::NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

static void cb_Cancel1(fltk3::Button*, void*) {
  global_settings_window->hide();
}

static void cb_OK(fltk3::Button*, void*) {
  writePrefs();
global_settings_window->hide();
}

fltk3::DoubleWindow* make_global_settings_window() {
  { global_settings_window = new fltk3::DoubleWindow(403, 317, "FLTK Preferences");
    global_settings_window->color(fltk3::LIGHT1);
    { fltk3::Group* o = new fltk3::Group(10, 10, 380, 100, "Keyboard Focus Options");
      o->box(fltk3::GTK_DOWN_BOX);
      o->labelfont(2);
      o->align(fltk3::Align(fltk3::ALIGN_TOP_LEFT|fltk3::ALIGN_INSIDE));
      { wVisibleFocus = new fltk3::Choice(245, 40, 100, 25, "Visible Keyboard Focus:");
        wVisibleFocus->tooltip("OPTION_VISIBLE_FOCUS\n\nIf visible focus is switched on, FLTK will draw a dot\
ted rectangle inside the widget that will receive the next keystroke. If switc\
hed off, no such indicator will be drawn and keyboard navigation is disabled.\
\n\nDefault is on.");
        wVisibleFocus->down_box(fltk3::BORDER_BOX);
        wVisibleFocus->callback((fltk3::Callback*)cb_wVisibleFocus);
        wVisibleFocus->menu(menu_wVisibleFocus);
      } // fltk3::Choice* wVisibleFocus
      { wArrowFocus = new fltk3::Choice(245, 75, 100, 25, "Arrow Keys move Focus:");
        wArrowFocus->tooltip("OPTION_ARROW_FOCUS\n\nWhen switched on, moving the text cursor beyond the sta\
rt or end of the text in a text widget will change focus to the next widget. W\
hen switched off, the cursor will stop at the end of the text. Pressing Tab or\
 Ctrl-Tab will advance the keyboard focus. Switch this on, if you want the old\
 behavior of FLTK 1.1.\n\nDefault is off.");
        wArrowFocus->down_box(fltk3::BORDER_BOX);
        wArrowFocus->callback((fltk3::Callback*)cb_wArrowFocus);
        wArrowFocus->menu(menu_wArrowFocus);
      } // fltk3::Choice* wArrowFocus
      o->end();
    } // fltk3::Group* o
    { fltk3::Group* o = new fltk3::Group(10, 120, 380, 65, "Tooltip Options");
      o->box(fltk3::GTK_DOWN_BOX);
      o->labelfont(2);
      o->align(fltk3::Align(fltk3::ALIGN_TOP_LEFT|fltk3::ALIGN_INSIDE));
      { wShowTooltips = new fltk3::Choice(245, 150, 100, 25, "Show Tooltips:");
        wShowTooltips->tooltip("OPTION_SHOW_TOOLTIPS\n\nIf tooltips are enabled, hovering the mouse over a wi\
dget with a tooltip text will open a little tooltip window until the mouse lea\
ves the widget. If disabled, no tooltip is shown.\n\nDefault is on.");
        wShowTooltips->down_box(fltk3::BORDER_BOX);
        wShowTooltips->callback((fltk3::Callback*)cb_wShowTooltips);
        wShowTooltips->menu(menu_wShowTooltips);
      } // fltk3::Choice* wShowTooltips
      o->end();
    } // fltk3::Group* o
    { fltk3::Group* o = new fltk3::Group(10, 194, 380, 66, "Drag And Drop Options");
      o->box(fltk3::GTK_DOWN_BOX);
      o->labelfont(2);
      o->align(fltk3::Align(fltk3::ALIGN_TOP_LEFT|fltk3::ALIGN_INSIDE));
      { wDNDText = new fltk3::Choice(245, 225, 100, 25, "Allow dragging Text:");
        wDNDText->tooltip("OPTION_DND_TEXT\n\nIf text drag-and-drop is enabled, the user can select and \
drag text from any text widget. If disabled, no dragging is possible, however \
dropping text from other applications still works.\n\nDefault is on.");
        wDNDText->down_box(fltk3::BORDER_BOX);
        wDNDText->callback((fltk3::Callback*)cb_wDNDText);
        wDNDText->menu(menu_wDNDText);
      } // fltk3::Choice* wDNDText
      o->end();
    } // fltk3::Group* o
    { wUserOrSystem = new fltk3::Choice(14, 275, 141, 25);
      wUserOrSystem->tooltip("Change settings for the current user, or default values for all users of this\
 computer. Individual users can override system options, if they set their opt\
ions to specific values (not \'default\').");
      wUserOrSystem->down_box(fltk3::BORDER_BOX);
      wUserOrSystem->callback((fltk3::Callback*)cb_wUserOrSystem);
      wUserOrSystem->menu(menu_wUserOrSystem);
    } // fltk3::Choice* wUserOrSystem
    { fltk3::Button* o = new fltk3::Button(230, 275, 75, 25, "Cancel");
      o->callback((fltk3::Callback*)cb_Cancel1);
    } // fltk3::Button* o
    { fltk3::Button* o = new fltk3::Button(315, 275, 75, 25, "OK");
      o->callback((fltk3::Callback*)cb_OK);
    } // fltk3::Button* o
    global_settings_window->end();
  } // fltk3::DoubleWindow* global_settings_window
  readPrefs();
    fltk3::option(fltk3::OPTION_SHOW_TOOLTIPS,1); // make sure tooltips are on !
  return global_settings_window;
}

//
// End of "$Id$".
//
