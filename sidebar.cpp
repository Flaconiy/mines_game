#include "sidebar.h"
#include "config.h"

#include "../_lib/Graph_lib/GUI.h"
#include "../_lib/Graph_lib/Graph.h"

using namespace Graph_lib;


Sidebar::Sidebar(Graph_lib::Point p, int w, int h, Field& target_)
  : Widget         { p, w, h, "", nullptr }
    , target       { &target_ }
    , btn_new_game { Point(p.x + (w-button_w) / 2, p.y + h - 3 * button_h - margin_top), button_w, button_h, "NEW GAME", cb_new_game }
    , btn_change   { Point(p.x + (w-button_w) / 2, p.y + h - 4 * button_h - margin_top), button_w, button_h, "MODE: BOMB", cb_change_mode }
    , btn_quit     { Point(p.x + (w-button_w) / 2, p.y + h - 2 * button_h - margin_top), button_w, button_h, "QUIT", cb_quit }
    , curr_out     { Point(p.x + (w - button_w)/2, p.y + margin_top), button_w, button_w, "" }
{
  //    curr_out.put(target->get_num_of_bombs());
}

void Sidebar::cb_quit (void*, void* addr)
{
  reference_to<Sidebar>(addr).quit();
}

void Sidebar::cb_new_game (void*, void* addr)
{
  reference_to<Sidebar>(addr).new_game();
}

void Sidebar::cb_change_mode (void*, void* addr)
{
  reference_to<Sidebar>(addr).change_mode();
}

void Sidebar::attach (Graph_lib::Window &win)
{
  win.attach(btn_change);
  win.attach(btn_new_game);
  win.attach(btn_quit);
  win.attach(curr_out);
}

void Sidebar::quit ()
{
  hide();
}

void Sidebar::new_game ()
{
  target->new_game();
}

void Sidebar::change_mode ()
{
  target->change_mode();
  if(btn_change.label == "MODE: BOMB") btn_change.label = "MODE: FLAG";
  else btn_change.label = "MODE: BOMB";
}

