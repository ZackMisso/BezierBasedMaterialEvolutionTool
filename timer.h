#pragma once

#include "array.h"
#include <iostream>

using namespace std;

class Timer {
private:
  Array<float>* history;
  clock_t current;
  string name;
public:
  Timer();
  Timer(string param);
  ~Timer();
  void clearHistory();
  void start();
  float stop();
  void reset();
  void lap();
  void push();
  float peek();
  void printHistory();
};
