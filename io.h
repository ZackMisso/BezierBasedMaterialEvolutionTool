#pragma once

#include "individual.h"

class IO {
public:
  static void writeIndividualToFile(const Individual& obj,int id,int gen);
  static void readIndividualFromFile(Individual& obj,int id,int gen);
};
