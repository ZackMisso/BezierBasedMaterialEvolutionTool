#pragma once

#include "programData.h"
#include <iostream>
#include <string>

using namespace std;

class ManualEditor {
private:
  ProgramData* programData;
  unsigned char* one;
  unsigned char* two;
  bool running;
  bool editingOne;
  bool printingByte;
public:
  ManualEditor(ProgramData* param);
  ~ManualEditor();
  void runEditor();
  void printData();
  void mutate();
  void crossover();
  void help();
  void switchFocus();
  string getStringInput();
  int getIntInput();
  float getFloatInput();
};
