#ifndef TESTSOK_H
#define TESTSOK_H
#include "mysok.h"

/* position : ...#
 *            ...@
 * can_move_U() return false */
bool test_u001() {
  board[0][0]=WALL; board[0][1]=END_OF_LINE;
  board[1][0]=MAN_ON_FREE;board[1][1]=END_OF_LINE;
  board_nbl=2;
  man_l=1; man_c=0;
  return (can_move_U()==false);
}

/* position : ...#
 *            ...a
 * can_move_U() return false */
bool test_u002() {
  board[0][0]=WALL; board[0][1]=END_OF_LINE;
  board[1][0]=MAN_ON_TARGET;board[1][1]=END_OF_LINE;
  board_nbl=2;
  man_l=1; man_c=0;
  return (can_move_U()==false);
}

/* position : ...#
 *            ...
 *            ...@
 * can_move_U() return true 
 * move_U() modifie la position : ...#
 *                                ...@
 *                                ...
*/
bool test_u003() {
  board[0][0]=WALL; board[0][1]=END_OF_LINE;
  board[1][0]=FREE; board[1][1]=END_OF_LINE;
  board[2][0]=MAN_ON_FREE;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=2; man_c=0;
  if(can_move_U()==false) return false;
  move_U();
  if(board[1][0]!=MAN_ON_FREE) return false;
  if(board[2][0]!=FREE) return false;
  if(man_l!=1) return false;
  return true;
}

/* position : ...#
 *            ...
 *            ...a
 * can_move_U() return true 
 * move_U() modifie la position : ...#
 *                                ...a
 *                                ...
*/
bool test_u004() {
  board[0][0]=WALL; board[0][1]=END_OF_LINE;
  board[1][0]=FREE; board[1][1]=END_OF_LINE;
  board[2][0]=MAN_ON_TARGET;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=2; man_c=0;
  if(can_move_U()==false) return false;
  move_U();
  if(board[1][0]!=MAN_ON_FREE) return false;
  if(board[2][0]!=TARGET) return false;
  if(man_l!=1) return false;
  return true;
}
/* position : ...
 *            ...$
 *            ...@
 * can_move_U() return true 
 * move_U() modifie la position : ...#
 *                                ...@
 *                                ...
*/
bool test_u005() {
  board[0][0]=FREE; board[0][1]=END_OF_LINE;
  board[1][0]=CRATE_ON_FREE; board[1][1]=END_OF_LINE;
  board[2][0]=MAN_ON_FREE;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=2; man_c=0;
  if(can_move_U()==false) return false;
  move_U();
  if(board[0][0] != CRATE_ON_FREE) return false;
  if(board[1][0] != MAN_ON_FREE) return false;
  if(board[2][0] != FREE) return false;
  if(man_l!=1) return false;
  return true;
}

/* position : ...
 *            ...$
 *            ...a
 * can_move_U() return true 
 * move_U() modifie la position : ...#
 *                                ...a
 *                                ...
*/
bool test_u006() {
  board[0][0]=FREE; board[0][1]=END_OF_LINE;
  board[1][0]=CRATE_ON_FREE; board[1][1]=END_OF_LINE;
  board[2][0]=MAN_ON_TARGET;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=2; man_c=0;
  if(can_move_U()==false) return false;
  move_U();
  if(board[0][0] != CRATE_ON_FREE) return false;
  if(board[1][0] != MAN_ON_FREE) return false;
  if(board[2][0] != TARGET) return false;
  if(man_l!=1) return false;
  return true;
}

/* position : ...
 *            ...*
 *            ...@
 * can_move_U() return true 
 * move_U() modifie la position : ...
 *                                ...a
 *                                ...
*/
bool test_u007() {
  board[0][0]=FREE; board[0][1]=END_OF_LINE;
  board[1][0]=TARGET; board[1][1]=END_OF_LINE;
  board[2][0]=MAN_ON_FREE;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=2; man_c=0;
  if(can_move_U()==false) return false;
  move_U();
  if(board[1][0] != MAN_ON_TARGET) return false;
  if(board[2][0] != FREE) return false;
  if(man_l!=1) return false;
  return true;
}

/* position : ...
 *            ...*
 *            ...a
 * can_move_U() return true 
 * move_U() modifie la position : ...
 *                                ...a
 *                                ...*
*/
bool test_u008() {
  board[0][0]=FREE; board[0][1]=END_OF_LINE;
  board[1][0]=TARGET; board[1][1]=END_OF_LINE;
  board[2][0]=MAN_ON_TARGET;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=2; man_c=0;
  if(can_move_U()==false) return false;
  move_U();
  if(board[1][0] != MAN_ON_TARGET) return false;
  if(board[2][0] != TARGET) return false;
  if(man_l!=1) return false;
  return true;
}

/* position : ...#
 *            ...$
 *            ...@
 * can_move_U() return false 
*/
bool test_u009() {
  board[0][0]=WALL; board[0][1]=END_OF_LINE;
  board[1][0]=CRATE_ON_FREE; board[1][1]=END_OF_LINE;
  board[2][0]=MAN_ON_FREE;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=2; man_c=0;
  if(can_move_U()==false) return false;
}

/* position : ...#
 *            ...$
 *            ...a
 * can_move_U() return false                              ...
*/
bool test_u010() {
  board[0][0]=WALL; board[0][1]=END_OF_LINE;
  board[1][0]=CRATE_ON_FREE; board[1][1]=END_OF_LINE;
  board[2][0]=MAN_ON_TARGET;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=2; man_c=0;
  if(can_move_U()==false) return false;
}

/* position : ...
 *            ...*
 *            ...@
 * can_move_U() return true 
 * move_U() modifie la position : ...
 *                                ...a
 *                                ...
*/
bool test_u011() {
  board[0][0]=WALL; board[0][1]=END_OF_LINE;
  board[1][0]=TARGET; board[1][1]=END_OF_LINE;
  board[2][0]=MAN_ON_FREE;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=2; man_c=0;
  if(can_move_U()==false) return false;
  move_U();
  if(board[0][0] != WALL) return false;
  if(board[1][0] != MAN_ON_TARGET) return false;
  if(board[2][0] != FREE) return false;
  if(man_l!=1) return false;
  return true;
}

/* position : ...
 *            ...*
 *            ...@
 * can_move_U() return true 
 * move_U() modifie la position : ...
 *                                ...a
 *                                ...
*/
bool test_u012 () {
  board[0][0]=WALL; board[0][1]=END_OF_LINE;
  board[1][0]=TARGET; board[1][1]=END_OF_LINE;
  board[2][0]=MAN_ON_TARGET;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=2; man_c=0;
  if(can_move_U()==false) return false;
  move_U();
  if(board[0][0] != WALL) return false;
  if(board[1][0] != MAN_ON_TARGET) return false;
  if(board[2][0] != TARGET) return false;
  if(man_l!=1) return false;
  return true;
}

/* -------------- DOWN ------------- */

/* position : ...@
 *            ...#
 * can_move_D() return false */
bool test_d001() {
  board[0][0]=MAN_ON_FREE; board[0][1]=END_OF_LINE;
  board[1][0]=WALL;board[1][1]=END_OF_LINE;
  board_nbl=2;
  man_l=0; man_c=0;
  return (can_move_D()==false);
}

/* position : ...a
 *            ...#
 * can_move_U() return false */
bool test_d002() {
  board[0][0]=MAN_ON_TARGET; board[0][1]=END_OF_LINE;
  board[1][0]=WALL;board[1][1]=END_OF_LINE;
  board_nbl=2;
  man_l=0; man_c=0;
  return (can_move_D()==false);
}

/* position : ...@
 *            ...
 *            ...#
 * can_move_D() return true 
 * move_D() modifie la position : ...
 *                                ...@
 *                                ...#
*/
bool test_d003() {
  board[0][0]=MAN_ON_FREE; board[0][1]=END_OF_LINE;
  board[1][0]=FREE; board[1][1]=END_OF_LINE;
  board[2][0]=WALL;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=0; man_c=0;
  if(can_move_D()==false) return false;
  move_D();
  if(board[1][0]!=MAN_ON_FREE) return false;
  if(board[0][0]!=FREE) return false;
  if(man_l!=1) return false;
  return true;
}

/* position : ...a
 *            ...
 *            ...#
 * can_move_D() return true 
 * move_D() modifie la position : ...*
 *                                ...@
 *                                ...#
*/
bool test_d004() {
  board[0][0]=MAN_ON_TARGET; board[0][1]=END_OF_LINE;
  board[1][0]=FREE; board[1][1]=END_OF_LINE;
  board[2][0]=WALL;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=0; man_c=0;
  if(can_move_D()==false) return false;
  move_D();
  if(board[0][0] != TARGET) return false;
  if(board[1][0] != MAN_ON_FREE) return false;
  if(man_l!=1) return false;
  return true;
}

/* position : ...@
 *            ...$
 *            ...
 * can_move_D() return true 
 * move_D() modifie la position : ...
 *                                ...@
 *                                ...$
*/
bool test_d005() {
  board[0][0]=MAN_ON_FREE; board[0][1]=END_OF_LINE;
  board[1][0]=CRATE_ON_FREE; board[1][1]=END_OF_LINE;
  board[2][0]=FREE;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=0; man_c=0;
  if(can_move_D()==false) return false;
  move_D();
  if(board[0][0] != FREE) return false;
  if(board[1][0] != MAN_ON_FREE) return false;
  if(board[2][0] != CRATE_ON_FREE) return false;
  if(man_l!=1) return false;
  return true;
}

/* position : ...a
 *            ...$
 *            ...
 * can_move_D() return true 
 * move_D() modifie la position : ...*
 *                                ...@
 *                                ...$
*/
bool test_d006() {
  board[0][0]=MAN_ON_TARGET; board[0][1]=END_OF_LINE;
  board[1][0]=CRATE_ON_FREE; board[1][1]=END_OF_LINE;
  board[2][0]=FREE;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=0; man_c=0;
  if(can_move_D()==false) return false;
  move_D();
  if(board[0][0] != TARGET) return false;
  if(board[1][0] != MAN_ON_FREE) return false;
  if(board[2][0] != CRATE_ON_FREE) return false;
  if(man_l!=1) return false;
  return true;
}

/* position : ...@
 *            ...*
 *            ...
 * can_move_D() return true 
 * move_D() modifie la position : ...
 *                                ...a
 *                                ...
*/
bool test_d007() {
  board[0][0]=MAN_ON_FREE; board[0][1]=END_OF_LINE;
  board[1][0]=TARGET; board[1][1]=END_OF_LINE;
  board[2][0]=FREE;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=0; man_c=0;
  if(can_move_D()==false) return false;
  move_D();
  if(board[0][0] != FREE) return false;
  if(board[1][0] != MAN_ON_TARGET) return false;
  if(board[2][0] != FREE) return false;
  if(man_l!=1) return false;
  return true;
}

/* position : ...a
 *            ...*
 *            ...
 * can_move_U() return true 
 * move_U() modifie la position : ...*
 *                                ...a
 *                                ...
*/
bool test_d008() {
  board[0][0]=MAN_ON_TARGET; board[0][1]=END_OF_LINE;
  board[1][0]=TARGET; board[1][1]=END_OF_LINE;
  board[2][0]=FREE; board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=0; man_c=0;
  if(can_move_D()==false) return false;
  move_D();
  if(board[1][0] != TARGET) return false;
  if(board[2][0] != MAN_ON_TARGET) return false;
  if(man_l!=1) return false;
  return true;
}

/* position : ...@
 *            ...$
 *            ...#
 * can_move_D() return false 
*/
bool test_d009() {
  board[0][0]=MAN_ON_FREE; board[0][1]=END_OF_LINE;
  board[1][0]=CRATE_ON_FREE; board[1][1]=END_OF_LINE;
  board[2][0]=WALL;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=0; man_c=0;
  if(can_move_D()==false) return false;
}

/* position : ...a
 *            ...$
 *            ...#
 * can_move_D() return false                              ...
*/
bool test_d010() {
  board[0][0]=MAN_ON_TARGET; board[0][1]=END_OF_LINE;
  board[1][0]=CRATE_ON_FREE; board[1][1]=END_OF_LINE;
  board[2][0]=WALL;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=0; man_c=0;
  if(can_move_D()==false) return false;
}

/* position : ...@
 *            ...*
 *            ...#
 * can_move_D() return true 
 * move_D() modifie la position : ...
 *                                ...a
 *                                ...#
*/
bool test_d011() {
  board[0][0]=MAN_ON_FREE; board[0][1]=END_OF_LINE;
  board[1][0]=TARGET; board[1][1]=END_OF_LINE;
  board[2][0]=WALL;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=0; man_c=0;
  if(can_move_D()==false) return false;
  move_D();
  if(board[0][0] != FREE) return false;
  if(board[1][0] != MAN_ON_TARGET) return false;
  if(board[2][0] != WALL) return false;
  if(man_l!=1) return false;
  return true;
}

/* position : ...a
 *            ...*
 *            ...#
 * can_move_D() return true 
 * move_D() modifie la position : ...*
 *                                ...a
 *                                ...#
*/
bool test_d012 () {
  board[0][0]=MAN_ON_TARGET; board[0][1]=END_OF_LINE;
  board[1][0]=TARGET; board[1][1]=END_OF_LINE;
  board[2][0]=WALL;board[2][1]=END_OF_LINE;
  board_nbl=3;
  man_l=0; man_c=0;
  if(can_move_D()==false) return false;
  move_D();
  if(board[0][0] != TARGET) return false;
  if(board[1][0] != MAN_ON_TARGET) return false;
  if(board[2][0] != WALL) return false;
  if(man_l!=1) return false;
  return true;
}
#endif
