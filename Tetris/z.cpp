#include <cstdlib>

#include "tetromino.h"

Z::Z() {
  size = 3;
  state = rand() % 4 + 1;

  set_shape_1();
  set_shape_2();
  set_shape_3();
  set_shape_4();
}

void Z::set_shape_1() {
  int shape[] = { 1, 1, 0,
                  0, 1, 1,
                  0, 0, 0 };

  shape_1 = new int[size];
  for (int i = 0; i < size; i++) {
    shape_1[i] = shape[i];
  }
}

void Z::set_shape_2() {
  int shape[] = { 0, 0, 1,
                  0, 1, 1,
                  0, 1, 0 };

  shape_2 = new int[size];
  for (int i = 0; i < size; i++) {
    shape_2[i] = shape[i];
  }
}

void Z::set_shape_3() {
  int shape[] = { 0, 0, 0,
                  1, 1, 0,
                  0, 1, 1 };

  shape_3 = new int[size];
  for (int i = 0; i < size; i++) {
    shape_3[i] = shape[i];
  }
}

void Z::set_shape_4() {
  int shape[] = { 0, 1, 0,
                  1, 1, 0,
                  1, 0, 0 };

  shape_4 = new int[size];
  for (int i = 0; i < size; i++) {
    shape_4[i] = shape[i];
  }
}
