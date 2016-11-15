#ifndef TETROMINO_H
#define TETROMINO_H

class Tetromino {
protected:
  int size;
  int state;
  int *shape_1, *shape_2, *shape_3, *shape_4;
};

class I : public Tetromino {
public:
  I();
private:
  void set_shape_1();
  void set_shape_2();
  void set_shape_3();
  void set_shape_4();
};

class L : public Tetromino {
public:
  L();
};

class O : public Tetromino {
public:
  O();
};

class T : public Tetromino {
public:
  T();
};

class Z : public Tetromino {
public:
  Z();
};

#endif
