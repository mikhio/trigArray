#include <stdio.h>
#include <assert.h>
#include "TrigArri.h"

int main(int argc, char **argv) {
  int data[] = {
    10,
    20, 30,
    40, 50, 60,
    70, 80, 90, 100,
    70, 80, 90, 100, 200
  };
  size_t data_rows = 6;

  TrigArri trig_arr = {};
  createTrig(&trig_arr, data, data_rows);

  printTrig(&trig_arr);

  return 0;
}
