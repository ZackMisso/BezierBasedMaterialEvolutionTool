#pragma once

class Random {
public:
  static int getRandomInt(int end);
  static int getRandomInt(int start,int end);
  static float getRandomFloat();
  static float getRandomFloat(float start,float end);
};
