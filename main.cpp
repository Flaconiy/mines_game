#include "../_lib/Graph_lib/Graph.h"
#include "../_lib/Graph_lib/Window.h"
#include "../_lib/Graph_lib/GUI.h"


#include <ctime>
#include <iostream>

#include "sidebar.h"
#include "field.h"
#include "config.h"

using namespace Graph_lib;


int main()
{
  Graph_lib::Window win{ field_size + margin_left * 2 + side_bar, field_size + 2 * margin_top, "MINER" };

  Field f{ Point(0,0), 10 };
  Sidebar s{ Point(field_size + 2 * margin_left, 0), side_bar, field_size + 2 * margin_top, f };

  f.attach(win);
  s.attach(win);

  return gui_main();
}
