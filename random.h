#pragma once

#include "matData.h"

class Random {

public:
  static void init();
  static int getRandomInt(int end);
  static int getRandomInt(int start,int end);
  static int getRandomIntNotIncluding(int end,int ignore);
  static float getRandomFloat();
  static float getRandomFloat(float start,float end);
  static void randomMat(char* mat,int dim,MatData* matData);
};
