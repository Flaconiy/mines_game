﻿#ifndef FIELD_H
#define FIELD_H

#include "../_lib/Graph_lib/Graph.h"
#include "../_lib/Graph_lib/GUI.h"


class Cell : public Graph_lib::Button
{
public:
  Cell(Graph_lib::Point p, int size_, Graph_lib::Callback cb, bool bomb);

  void set_bomb(bool bomb_) {bombed = bomb_;}
  void set_flag(bool flag_) {flaged = flag_;}
  void set_open() { opened = true;}

  bool get_bombed() const {return bombed;}
  bool get_flaged() const{return flaged;}
  bool is_opened() const {return opened;}

private:
  bool bombed;
  bool flaged {false};
  bool opened {false};
};


class Field : public Graph_lib::Widget
{
public:
  Field (Graph_lib::Point p, int n);  // n is a number of rows and columns
  bool get_mode () const { return gamemode; }
  void attach (Graph_lib::Window &win) override;

  void new_game ();
  void change_mode ();
  unsigned int get_num_of_bombs () const { return num_of_bombs; }

private:
  bool gamemode{ true };
  int num_of_bombs{0};
  int rows;
  int cell_size;
  Graph_lib::Vector_ref<Cell> cells;
  static void cb_clicked (void* widget, void* addr);
  void clicked (void* addr);
};


#endif // FIELD_H
