#include "individual.h"

Individual::Individual(int dim) {
  dim8x = dim << 3;
  uvVoxelMap = new char(dim8x*dim8x);
  fitness = 0x0;
}

Individual::~Individual() {
  delete uvVoxelMap;
}

int Individual::compare(const Individual& desired) {
  // to be implemented
}

void Individual::mutate(int mutationRate) {
  // to be implemented
}

void Individual::crossover(const Individual& other,int crossoverRate) {
  // to be implemented
}

int Individual::getFitness() { return fitness; }
