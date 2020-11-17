#ifndef SIDEBAR_H
#define SIDEBAR_H


#include "../_lib/Graph_lib/GUI.h"
#include "../_lib/Graph_lib/Graph.h"

#include "field.h"


class Sidebar : public Graph_lib::Widget
{
public:
  Sidebar (Graph_lib::Point p, int w, int h, Field& target_);

  void attach (Graph_lib::Window& win) override;

private:
  Field* target;
  Graph_lib::Button  btn_new_game;
  Graph_lib::Button  btn_change;
  Graph_lib::Button  btn_quit;
  Graph_lib::Out_box curr_out;

  static void cb_new_game    (void*, void*);
  static void cb_change_mode (void*, void*);
  static void cb_quit        (void*, void*);

  void new_game    ();
  void change_mode ();
  void quit        ();
};


#endif // SIDEBAR_H
