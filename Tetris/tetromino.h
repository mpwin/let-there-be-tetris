#ifndef TETROMINO_H
#define TETROMINO_H

class Tetromino {
protected:
  int shape;
};

class I : public Tetromino {
public:
  I();
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
