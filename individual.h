#pragma once

class Individual {
private:
  char* uvVoxelMap;
  int dim8x; // voxel map dimension / 8
  int fitness;
public:
  Individual(int dim);
  ~Individual();
  int compare(const Individual& other) const;
  void calculateFitness(const Individual& desired);
  // mutation methods
  void mutate(int mutationRate);
  void crossover(const Individual& other,int crossoverRate);
  // getter methods
  int getFitness();
};
