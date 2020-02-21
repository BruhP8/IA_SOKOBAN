#ifndef MYSOK_H
#define MYSOK_H
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <string>
#include <vector>
#include <list>

#define NBL 100
#define NBC 100

#define MOVE_U 0
#define MOVE_D 1
#define MOVE_L 2
#define MOVE_R 3

#define FREE 0
#define TARGET 1
#define WALL 2
#define CRATE_ON_FREE 3
#define CRATE_ON_TARGET 4
#define MAN_ON_FREE 5
#define MAN_ON_TARGET 6
#define END_OF_LINE 7

char board_str[] = {' ','.','#','$','*','@','a'};

enum move_t{U=MOVE_U, D=MOVE_D, L=MOVE_L, R=MOVE_R};

struct board_t{
  int board[NBL][NBC];
  int board_nbl;
  int man_l;
  int man_c;

  bool can_move_U();
  bool can_move_D();
  bool can_move_L();
  bool can_move_R();
  void move_U();
  void move_D();
  void move_L();
  void move_R();
  void play(move_t dir);
  void unplay(move_t dir);
  std::list<move_t> nextMoves();
};

board_t board;


void init_board() {
  for(int i = 0; i < NBL; i++)
    for(int j = 0; j < NBC; j++)
      board.board[i][j] = FREE;
}

void print_board() {
  for(int i = 0; i < board.board_nbl; i++) {
    for(int j = 0; j < NBC; j++) {
      if(board.board[i][j]==END_OF_LINE) break;
      printf("%c", board_str[board.board[i][j]]);
    }
    printf("\n");
  }
}

void load(char* _file) {
  FILE *fp = fopen(_file, "r");
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;
  if (fp == NULL) {
    perror("fopen"); exit(EXIT_FAILURE);
  }
  board.board_nbl = 0;
  while ((nread = getline(&line, &len, fp)) != -1) {
    if(((int)nread) > 0) {
      bool read_ok = false;
      for(int i = 0; i < nread; i++) {
        if(line[i] == board_str[FREE]) board.board[board.board_nbl][i] = FREE;
        if(line[i] == board_str[TARGET]) board.board[board.board_nbl][i] = TARGET;
        if(line[i] == board_str[WALL]) {
    read_ok = true; board.board[board.board_nbl][i] = WALL;
  }
        if(line[i] == board_str[CRATE_ON_FREE]) board.board[board.board_nbl][i] = CRATE_ON_FREE;
        if(line[i] == board_str[CRATE_ON_TARGET]) board.board[board.board_nbl][i] = CRATE_ON_TARGET;
        if(line[i] == board_str[MAN_ON_FREE]) {
    board.man_l = board.board_nbl; board.man_c = i; 
    board.board[board.board_nbl][i] = MAN_ON_FREE;
  }
        if(line[i] == board_str[MAN_ON_TARGET]) {
    board.man_l = board.board_nbl; board.man_c = i; 
    board.board[board.board_nbl][i] = MAN_ON_TARGET;
  }
      }
      if(read_ok) {
  board.board[board.board_nbl][nread]=END_OF_LINE;
  board.board_nbl++;
      }
    }
  }
  free(line);
  fclose(fp);
}

bool board_t::can_move_U() {
  if(man_l <= 1) return false;
  if(board[man_l-1][man_c]==FREE) return true;
  if(man_l >= 3) {
    if(board[man_l-1][man_c]==CRATE_ON_FREE &&
      (board[man_l-2][man_c]==FREE || board[man_l-2][man_c]==TARGET)) return true;
    if(board[man_l-1][man_c]==CRATE_ON_TARGET &&
      (board[man_l-2][man_c]==FREE || board[man_l-2][man_c]==TARGET)) return true;
  }
  return false;
}

void board_t::move_U() {
  if(board[man_l-1][man_c]==FREE) {
    if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
    if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
    board[man_l-1][man_c] = MAN_ON_FREE;
    man_l-=1;
    return;
  }
  if(board[man_l-1][man_c]==TARGET) {
    if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
    if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
    board[man_l-1][man_c] = MAN_ON_TARGET;
    man_l-=1;
    return;
  }
  if(board[man_l-2][man_c]==FREE) {
    if(board[man_l-1][man_c]==CRATE_ON_FREE) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l-1][man_c]=MAN_ON_FREE;
      board[man_l-2][man_c]=CRATE_ON_FREE;
      man_l-=1;
      return;
    }
    if(board[man_l-1][man_c]==CRATE_ON_TARGET) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l-1][man_c]=MAN_ON_TARGET;
      board[man_l-2][man_c]=CRATE_ON_FREE;
      man_l-=1;
      return;
    }
  }
  if(board[man_l-2][man_c]==TARGET) {
    if(board[man_l-1][man_c]==CRATE_ON_FREE) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l-1][man_c]=MAN_ON_FREE;
      board[man_l-2][man_c]=CRATE_ON_TARGET;
      man_l-=1;
      return;
    }
    if(board[man_l-1][man_c]==CRATE_ON_TARGET) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l-1][man_c]=MAN_ON_TARGET;
      board[man_l-2][man_c]=CRATE_ON_TARGET;
      man_l-=1;
      return;
    }
  }
}

bool board_t::can_move_D(){
  if(man_l >= 1) return false;
  if(board[man_l+1][man_c]==FREE) return true;
  if(man_l >= 3) {
    if(board[man_l+1][man_c]==CRATE_ON_FREE &&
      (board[man_l+2][man_c]==FREE || board[man_l+2][man_c]==TARGET)) return true;
    if(board[man_l+1][man_c]==CRATE_ON_TARGET &&
      (board[man_l+2][man_c]==FREE || board[man_l+2][man_c]==TARGET)) return true;
  }
  return false;
}

void board_t::move_D(){
  if(board[man_l+1][man_c]==FREE) {
    if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
    if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
    board[man_l+1][man_c] = MAN_ON_FREE;
    man_l+=1;
    return;
  }
  if(board[man_l+1][man_c]==TARGET) {
    if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
    if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
    board[man_l+1][man_c] = MAN_ON_TARGET;
    man_l+=1;
    return;
  }
  if(board[man_l+2][man_c]==FREE) {
    if(board[man_l+1][man_c]==CRATE_ON_FREE) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l+1][man_c]=MAN_ON_FREE;
      board[man_l+2][man_c]=CRATE_ON_FREE;
      man_l+=1;
      return;
    }
    if(board[man_l+1][man_c]==CRATE_ON_TARGET) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l+1][man_c]=MAN_ON_TARGET;
      board[man_l+2][man_c]=CRATE_ON_FREE;
      man_l+=1;
      return;
    }
  }
  if(board[man_l+2][man_c]==TARGET) {
    if(board[man_l+1][man_c]==CRATE_ON_FREE) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l+1][man_c]=MAN_ON_FREE;
      board[man_l+2][man_c]=CRATE_ON_TARGET;
      man_l+=1;
      return;
    }
    if(board[man_l+1][man_c]==CRATE_ON_TARGET) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l+1][man_c]=MAN_ON_TARGET;
      board[man_l+2][man_c]=CRATE_ON_TARGET;
      man_l+=1;
      return;
    }
  }
}

bool board_t::can_move_L(){
  if(man_c <= 1) return false;
  if(board[man_l][man_c-1]==FREE) return true;
  if(man_c >= 3) {
    if(board[man_l][man_c-1]==CRATE_ON_FREE &&
      (board[man_l][man_c-2]==FREE || board[man_l][man_c-2]==TARGET)) return true;
    if(board[man_l][man_c-1]==CRATE_ON_TARGET &&
      (board[man_l][man_c-2]==FREE || board[man_l][man_c-2]==TARGET)) return true;
  }
  return false;
}

void board_t::move_L(){
  if(board[man_l][man_c-1]==FREE) {
    if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
    if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
    board[man_l][man_c-1] = MAN_ON_FREE;
    man_c-=1;
    return;
  }
  if(board[man_l][man_c-1]==TARGET) {
    if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
    if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
    board[man_l][man_c-1] = MAN_ON_TARGET;
    man_c-=1;
    return;
  }
  if(board[man_l][man_c-2]==FREE) {
    if(board[man_l-1][man_c]==CRATE_ON_FREE) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l][man_c-1]=MAN_ON_FREE;
      board[man_l][man_c-2]=CRATE_ON_FREE;
      man_c-=1;
      return;
    }
    if(board[man_l][man_c-1]==CRATE_ON_TARGET) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l][man_c-1]=MAN_ON_TARGET;
      board[man_l][man_c-2]=CRATE_ON_FREE;
      man_c-=1;
      return;
    }
  }
  if(board[man_l][man_c-2]==TARGET) {
    if(board[man_l][man_c-1]==CRATE_ON_FREE) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l][man_c-1]=MAN_ON_FREE;
      board[man_l][man_c-2]=CRATE_ON_TARGET;
      man_c-=1;
      return;
    }
    if(board[man_l][man_c-1]==CRATE_ON_TARGET) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l][man_c-1]=MAN_ON_TARGET;
      board[man_l][man_c-2]=CRATE_ON_TARGET;
      man_c-=1;
      return;
    }
  }
}

bool board_t::can_move_R(){
  if(man_c >= 1) return false;
  if(board[man_l][man_c+1]==FREE) return true;
  if(man_c >= 3) {
    if(board[man_l][man_c+1]==CRATE_ON_FREE &&
      (board[man_l][man_c+2]==FREE || board[man_l][man_c+2]==TARGET)) return true;
    if(board[man_l][man_c+1]==CRATE_ON_TARGET &&
      (board[man_l][man_c+2]==FREE || board[man_l][man_c+2]==TARGET)) return true;
  }
  return false;
}

void board_t::move_R(){
  if(board[man_l][man_c+1]==FREE) {
    if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
    if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
    board[man_l][man_c+1] = MAN_ON_FREE;
    man_c+=1;
    return;
  }
  if(board[man_l][man_c+1]==TARGET) {
    if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
    if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
    board[man_l][man_c+1] = MAN_ON_TARGET;
    man_c+=1;
    return;
  }
  if(board[man_l][man_c+2]==FREE) {
    if(board[man_l+1][man_c]==CRATE_ON_FREE) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l][man_c+1]=MAN_ON_FREE;
      board[man_l][man_c+2]=CRATE_ON_FREE;
      man_c+=1;
      return;
    }
    if(board[man_l][man_c+1]==CRATE_ON_TARGET) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l][man_c+1]=MAN_ON_TARGET;
      board[man_l][man_c+2]=CRATE_ON_FREE;
      man_c+=1;
      return;
    }
  }
  if(board[man_l][man_c+2]==TARGET) {
    if(board[man_l][man_c+1]==CRATE_ON_FREE) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l][man_c+1]=MAN_ON_FREE;
      board[man_l][man_c+2]=CRATE_ON_TARGET;
      man_c+=1;
      return;
    }
    if(board[man_l][man_c+1]==CRATE_ON_TARGET) {
      if(board[man_l][man_c]==MAN_ON_FREE) board[man_l][man_c]=FREE;
      if(board[man_l][man_c]==MAN_ON_TARGET) board[man_l][man_c]=TARGET;
      board[man_l][man_c+1]=MAN_ON_TARGET;
      board[man_l][man_c+2]=CRATE_ON_TARGET;
      man_c+=1;
      return;
    }
  }
}

void board_t::play(move_t dir){
  if (dir == U && can_move_U())
    move_U();
  else if (dir == D && can_move_D())
    move_D();
  else if (dir == L && can_move_L())
    move_L();
  else if (dir == R && can_move_R())
    move_R();
}

void board_t::unplay(move_t dir){
  if (dir == U)
    move_D();
  else if (dir == D)
    move_U();
  else if (dir == L)
    move_R();
  else if (dir == R)
    move_L();
}

std::list<move_t> board_t::nextMoves(){
  move_t moves;
  std::list<move_t> pos;
  if (can_move_U()){
    moves = U;
    pos.push_back(moves);
  }
  if (can_move_D()){
    moves = D;
    pos.push_back(moves);
  }
  if (can_move_L()){
    moves = L;
    pos.push_back(moves);
  }
  if (can_move_R()){
    moves = R;
    pos.push_back(moves);
  }
  return pos;
}
#endif
