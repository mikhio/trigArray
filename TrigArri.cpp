#include <stdio.h>
#include <assert.h>
#include "TrigArri.h"

//--------------------------------------------------------------------------------

void createTrig(TrigArri *trig_arr, const int *data, size_t rows) {
  assert(trig_arr);
  assert(data);

  trig_arr->data = (int*) calloc(GET_ARR_LEN(rows), sizeof(int));
  trig_arr->rows = rows;

  for (size_t i = 0; i < GET_ARR_LEN(rows); i++)
    trig_arr->data[i] = data[i];
}

void deleteTrig(TrigArri *trig_arr) {
  assert(trig_arr);

  trig_arr->rows = 0;
  free(trig_arr->data);
}

//--------------------------------------------------------------------------------

int getElement(const TrigArri *trig_arr, size_t x, size_t y) {
  assert(trig_arr);
  assert(y < trig_arr->rows);

  size_t row_len = y + 1;
  assert(x < row_len);

  return *(trig_arr->data + GET_ARR_LEN(y-1) + x);
}

void setElement(TrigArri *trig_arr, size_t x, size_t y, int value) {
  assert(trig_arr);
  assert(y < trig_arr->rows);

  size_t row_len = y + 1;
  assert(x < row_len);

  *(trig_arr->data + GET_ARR_LEN(y-1) + x) = value;
}

//--------------------------------------------------------------------------------

void printTrig(const TrigArri *trig_arr) {
  assert(trig_arr);

  size_t row_len = 0;

  for (size_t y = 0; y < trig_arr->rows; y++) {
    row_len = y + 1;

    for (int i = 0; i < row_len; i++)
      printf("+ -- ");
    printf("+\n");

    printf("|");
    for (size_t x = 0; x < row_len; x++) {
      printf("%4d|", getElement(trig_arr, x, y));
    }
    printf("\n");
  }

  for (int i = 0; i < row_len; i++)
    printf("+ -- ");
  printf("+\n");
}
