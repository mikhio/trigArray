#ifndef TRIG_ARR_I_H
#define TRIG_ARR_I_H

#define GET_ARR_LEN(rows) ((rows + 1) * (rows + 2) / 2)

struct TrigArri {
  size_t rows;
  int *data;
};



void createTrig (TrigArri *trig_arr, size_t rows, const int *data);
void deleteTrig (TrigArri *trig_arr);
void printTrig  (const TrigArri *trig_arr);

void initRandomTrig (TrigArri *trig_arr, int seed_num);

int  getElement (const TrigArri *trig_arr, size_t x, size_t y);
void setElement (TrigArri *trig_arr, size_t x, size_t y, int value);

void getNegTrig     (const TrigArri *src_trig, TrigArri *dest_trig);
void sumTrigs       (const TrigArri *src_trig, TrigArri *dest_trig);
void substractTrigs (const TrigArri *src_trig, TrigArri *dest_trig);
void swapTrigs      (TrigArri *src_trig, TrigArri *dest_trig);

#endif // TRIG_ARR_I_H
