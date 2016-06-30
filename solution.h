#pragma once

#include "matData.h"

class Solution {
public:
  static char* createDesiredOutput(MatData* matData,int dim,int complexityNum);
  static void addInRandomSquare(char* individual,MatData* matData);
  static void addInRandomCircle(char* individual,MatData* matData);
  static void addInRandomLine(char* individual,MatData* matData);
  static void addInRandomPoint(char* individual,MatData* matData);
};
