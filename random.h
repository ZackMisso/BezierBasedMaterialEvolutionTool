#pragma once

class Random {

public:
  static void init();
  static int getRandomInt(int end);
  static int getRandomInt(int start,int end);
  static float getRandomFloat();
  static float getRandomFloat(float start,float end);
  static void randomMat(char* mat,int dim);
};
