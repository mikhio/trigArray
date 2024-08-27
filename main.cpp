#include <stdio.h>
#include <assert.h>

//const int SIZE_OF_CELL = 4;


int getElement(int *trig_arr, size_t trig_rows, size_t x, size_t y) {
  assert(y < trig_rows);

  size_t row_len = y + 1;
  assert(x < row_len);

  size_t arifm_sum = (1 + y) * y / 2;

  return *(trig_arr + arifm_sum + x);
}

void printTrig(int *trig_arr, size_t trig_rows) {
  for (size_t y = 0; y < trig_rows; y++) {
    size_t row_len = y + 1;

    for (size_t x = 0; x < row_len; x++) {
      printf("%4d ", getElement(trig_arr, trig_rows, x, y));
    }

    printf("\n");
  }
}

int main(int argc, char **argv) {
  int trig_arr[] = {
    10,
    20, 30,
    40, 50, 60,
    70, 80, 90, 100
  };
  size_t trig_rows = 4;

  printTrig(trig_arr, trig_rows);


  return 0;
}
