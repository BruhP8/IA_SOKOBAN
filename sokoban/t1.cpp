#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <string>
#include <unordered_map>
#include "testsok.h"

int main(int _ac, char** _av) {
  int nb_test_ok = 0;
  if(test_u001()==false) printf("test_u001 FAILED\n");
  else nb_test_ok++;

  if(test_u002()==false) printf("test_u002 FAILED\n");
  else nb_test_ok++;

  if(test_u003()==false) printf("test_u003 FAILED\n");
  else nb_test_ok++;

  if(test_u004()==false) printf("test_u004 FAILED\n");
  else nb_test_ok++;

  if(test_u005()==false) printf("test_u005 FAILED\n");
  else nb_test_ok++;

  if(test_u006()==false) printf("test_u006 FAILED\n");
  else nb_test_ok++;
  
  if(test_u007()==false) printf("test_u007 FAILED\n");
  else nb_test_ok++;
  
  if(test_u008()==false) printf("test_u008 FAILED\n");
  else nb_test_ok++;

  if(test_u009()==false) printf("test_u009 FAILED\n");
  else nb_test_ok++;

  if(test_u010()==false) printf("test_u010 FAILED\n");
  else nb_test_ok++;

  if(test_u011()==false) printf("test_u011 FAILED\n");
  else nb_test_ok++;

  if(test_u012()==false) printf("test_u012 FAILED\n");
  else nb_test_ok++;
  //...
  printf("nb_test_ok: %d\n", nb_test_ok);
  return 0;
}
