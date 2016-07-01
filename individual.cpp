#include "individual.h"

Individual::Individual(int dim) {
  dim8x = dim << 3;
  uvVoxelMap = new char(dim*dim);
  fitness = 0x0;
}

Individual::Individual(char* map,int dim) {
  dim8x = dim << 3;
  uvVoxelMap = map;
  fitness = 0x0;
}

Individual::~Individual() {
  delete uvVoxelMap;
}

void Individual::randomize(MatData* matData) {
  int dim = dim8x >> 3;
  Random::randomMat(uvVoxelMap,dim);
}

int Individual::compare(const Individual& other) {
  int dim = dim8x >> 3;
  int diff = 0;
  for(int i=0;i<dim*dim;i++) {
    char tmp = uvVoxelMap[i] ^ other.uvVoxelMap[i];
    for(int j=0;j<8;j++) diff += (tmp >> j) & 0x1;
  }
  return dim*dim - diff;
}

void calculateFitness(const Individual& desired) {
  fitness = compare(desired);
}

void Individual::mutate(int mutationRate) {
  int dim = dim8x >> 3;
  for(int i=0;i<mutationRate;i++) {
    int index = Random::getRandomInt(dim*dim);
    int index8 = Random::getRandomInt(8);
    char tmp = !((uvVoxelMap[index] >> index8) & 0x1);
    if(tmp) uvVoxelMap[index] = (uvVoxelMap[index] & (0xFF & (0x1 << index8)));
    else uvVoxelMap[index] = (uvVoxelMap[index] | (0x00 | (0x1 << index8)));
  }
}

void Individual::crossover(const Individual& other,int crossoverRate) {
  // to be implemented
}

int Individual::getFitness() { return fitness; }
