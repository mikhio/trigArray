#ifndef TRIG_ARR_I_H
#define TRIG_ARR_I_H

#define GET_ARR_LEN(rows) ((rows + 1) * (rows + 2) / 2)

struct TrigArri {
  size_t rows;
  int *data;
};


int  getElement (const TrigArri *trig_arr, size_t x, size_t y);
void setElement (TrigArri *trig_arr, size_t x, size_t y, int value);

void createTrig (TrigArri *trig_arr, const int *data, size_t rows);
void deleteTrig (TrigArri *trig_arr);
void printTrig  (const TrigArri *trig_arr);

#endif // TRIG_ARR_I_H
