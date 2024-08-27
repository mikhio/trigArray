#include <stdio.h>
#include <assert.h>
#include "TrigArri.h"


int main(int argc, char **argv) {

  TrigArri trig_arr1 = {};
  TrigArri trig_arr2 = {};

  createTrig(&trig_arr1, 5, NULL);
  createTrig(&trig_arr2, 5, NULL);

  initRandomTrig(&trig_arr1, 1);

  printTrig(&trig_arr1);
  printTrig(&trig_arr2);

  getNegTrig(&trig_arr1, &trig_arr2);

  printTrig(&trig_arr2);

  deleteTrig(&trig_arr1);
  deleteTrig(&trig_arr2);

  return 0;
}
