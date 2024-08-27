#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "TrigArri.h"

//--------------------------------------------------------------------------------

void createTrig(TrigArri *trig_arr, size_t rows, const int *data) {
  assert(trig_arr);

  trig_arr->data = (int*) calloc(GET_ARR_LEN(rows), sizeof(int));
  trig_arr->rows = rows;

  if (data != NULL) {
    for (size_t i = 0; i < GET_ARR_LEN(rows); i++)
      trig_arr->data[i] = data[i];
  } else {
    for (size_t i = 0; i < GET_ARR_LEN(rows); i++)
      trig_arr->data[i] = 0;
  }
}

void deleteTrig(TrigArri *trig_arr) {
  assert(trig_arr);

  trig_arr->rows = 0;
  free(trig_arr->data);
}

//--------------------------------------------------------------------------------

void initRandomTrig(TrigArri *trig_arr, int seed_num) {
  assert(trig_arr);
  assert(trig_arr->data);

  srand(time(NULL) + seed_num);
  
  for (int i = 0; i < GET_ARR_LEN(trig_arr->rows); i++) {
    trig_arr->data[i] = rand() % 10;
  }
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

//--------------------------------------------------------------------------------


void getNegTrig(const TrigArri *src_trig, TrigArri *dest_trig) {
  assert(src_trig);
  assert(dest_trig);

  assert(src_trig->data);
  assert(dest_trig->data);

  assert(src_trig->rows == dest_trig->rows);

  for (int i = 0; i < GET_ARR_LEN(dest_trig->rows); i++)
    dest_trig->data[i] = -src_trig->data[i];
}


void sumTrigs(const TrigArri *src_trig, TrigArri *dest_trig) {
  assert(src_trig);
  assert(dest_trig);

  assert(src_trig->data);
  assert(dest_trig->data);

  assert(src_trig->rows == dest_trig->rows);

  for (int i = 0; i < GET_ARR_LEN(dest_trig->rows); i++)
    dest_trig->data[i] += src_trig->data[i];
}

void substractTrigs(const TrigArri *src_trig, TrigArri *dest_trig) {
  assert(src_trig);
  assert(dest_trig);

  assert(src_trig->data);
  assert(dest_trig->data);

  assert(src_trig->rows == dest_trig->rows);

  for (int i = 0; i < GET_ARR_LEN(dest_trig->rows); i++)
    dest_trig->data[i] += -src_trig->data[i];
}

void swapTrigs(TrigArri *trig1, TrigArri *trig2) {
  assert(trig1);
  assert(trig2);

  assert(trig1->data);
  assert(trig2->data);

  assert(trig1->rows == trig2->rows);

  for (int i = 0; i < GET_ARR_LEN(trig1->rows); i++) {
    int temp = trig1->data[i];
    trig1->data[i] = trig2->data[i];
    trig2->data[i] = temp;
  }
}
