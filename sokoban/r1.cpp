#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <string>
#include <unordered_map>
#include "mysok.h"

int main(int _ac, char** _av) {
  if(_ac != 2) { printf("usage: %s SOK_FILE\n", _av[0]); return 0; }
  srand(2);
  load(_av[1]);
  print_board();
  //printf("%d\n", can_move_U(man_l, man_c));
  move_U();
  move_D();
  move_L();
  move_R();
  print_board();
  return 0;
}
