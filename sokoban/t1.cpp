#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <string>
#include <unordered_map>
#include "testsok.h"

int main(int _ac, char** _av) {
  int nb_test_ok = 0;
  if(test_p001()==false) printf("test_p001 FAILED\n");
  else nb_test_ok++;

  if(test_p002()==false) printf("test_p002 FAILED\n");
  else nb_test_ok++;

  if(test_p003()==false) printf("test_p003 FAILED\n");
  else nb_test_ok++;

  if(test_p004()==false) printf("test_p004 FAILED\n");
  else nb_test_ok++;

  if(test_p005()==false) printf("test_p005 FAILED\n");
  else nb_test_ok++;

  if(test_p006()==false) printf("test_p005 FAILED\n");
  else nb_test_ok++;
  //...
  printf("nb_test_ok: %d\n", nb_test_ok);
  return 0;
}
