#pragma once

#include "matData.h"

class Individual {
private:
  char* uvVoxelMap;
  int dim8x; // voxel map dimension / 8
  int fitness;
public:
  Individual();
  Individual(int dim);
  Individual(char* map,int dim);
  ~Individual();
  void initialize(int dim);
  void randomize(MatData* matData);
  int compare(const Individual& other) const;
  void calculateFitness(const Individual& desired);
  void resetFitness();
  // mutation methods
  void mutate(int mutationRate);
  void crossover(const Individual& other,int crossoverRate);
  // operators
  bool operator >(const Individual& other) const;
  bool operator <(const Individual& other) const;
  void operator =(const Individual& other);
  // getter methods
  int getFitness();
};
