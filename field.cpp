#include "field.h"
#include "config.h"

#include <iostream>
#include <ctime>

#include "../_lib/Graph_lib/GUI.h"
#include "../_lib/Graph_lib/Graph.h"

using namespace Graph_lib;


Cell::Cell (Graph_lib::Point p, int size_, Graph_lib::Callback cb, bool bomb)
 : Button{ p, size_, size_, "", cb }
{
  set_bomb(bomb);
}

void Field::attach (Graph_lib::Window &win)
{
  for(int i = 0; i < cells.size(); ++i){
    win.attach(cells[i]);
  }
}

void Field::cb_clicked (void* widget, void* addr)
{
  reference_to<Field>(addr).clicked(widget);
}

void Field::new_game ()
{ //TODO
  std::cout << "new game\n";
  hide();
}

void Field::change_mode ()
{
  std::cerr << "2" << gamemode << "3" << "\n";
  gamemode = !(gamemode);
}

Field::Field (Graph_lib::Point p, int n)
  : Graph_lib::Widget(p, field_size + 2 * margin_left + side_bar,field_size + 2*margin_top,"", nullptr)
    , num_of_bombs{(n - 2)*2}
    , rows{n}
    , cell_size{int(field_size / n)}
{
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cells.push_back(new Cell{Graph_lib::Point(margin_left + int(i * field_size / n) , margin_top + int(j * field_size / n)), int(field_size / n), cb_clicked, false});
    }
  }

  int counter = 0;
  std::srand(time(0));

  while(counter < num_of_bombs)
  {
    int k = abs(std::rand());
    int g = k%(n*n);
    if(cells[g].get_bombed() == false)
    {
      cells[g].set_bomb(true);
      ++counter;
    }
  }
}


void Field::clicked(void* widget){
  //logic of click
  Fl_Widget& w = reference_to<Fl_Widget>(widget);
  int x = w.x() - margin_left;
  int y = w.y() - margin_top;
  int i = x / cell_size;
  int j = y / cell_size;
  Cell& c = cells[i*rows + j];
  if(gamemode && c.is_opened() == false){
    if(c.get_flaged() == false){
      c.set_open();
      if(c.get_bombed() == false)  {
        w.color(Color::green);
      }
      else {
        w.color(Color::red);
      }
    }
  }
  else{
    if(c.is_opened() == true) return;
    if(c.get_flaged() == false) {
      c.set_flag(true);
      w.color(Color::black);
    }
    else {
      c.set_flag(false);
      w.color(fl_rgb_color(190,190,190));
    }
  }
}
