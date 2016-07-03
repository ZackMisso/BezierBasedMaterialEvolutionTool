#include "individual.h"
#include "random.h"

Individual::Individual() {
  uvVoxelMap = 0x0;
  dim8x = 0;
  fitness = 0;
}

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

void Individual::initialize(int dim) {
  dim8x = dim << 3;
  if(uvVoxelMap) delete uvVoxelMap;
  uvVoxelMap = new char(dim*dim);
  fitness = 0x0;
}

void Individual::resetFitness() {
  fitness = 0x0;
}

void Individual::randomize(MatData* matData) {
  int dim = dim8x >> 3;
  Random::randomMat(uvVoxelMap,dim,matData);
}

int Individual::compare(const Individual& other) const {
  int dim = dim8x >> 3;
  int diff = 0;
  for(int i=0;i<dim*dim;i++) {
    char tmp = uvVoxelMap[i] ^ other.uvVoxelMap[i];
    for(int j=0;j<8;j++) diff += (tmp >> j) & 0x1;
  }
  return dim*dim - diff;
}

void Individual::calculateFitness(const Individual& desired) {
  fitness = compare(desired);
}

void Individual::mutate(int mutationRate) {
  int dim = dim8x >> 3;
  for(int i=0;i<mutationRate;i++) {
    int index = Random::getRandomInt(dim*dim);
    int index8 = Random::getRandomInt(8);
    char tmp = !((uvVoxelMap[index] >> index8) & 0x1);
    if(tmp) uvVoxelMap[index] = (uvVoxelMap[index] & (0xFF & ~(0x1 << index8)));
    else uvVoxelMap[index] = (uvVoxelMap[index] | (0x00 | (0x1 << index8)));
  }
}

void Individual::crossover(const Individual& other,int crossoverRate) {
  int dim = dim8x >> 3;
  int startX = Random::getRandomInt(dim - crossoverRate);
  int startY = Random::getRandomInt(dim - crossoverRate);
  for(int i=startY;i<crossoverRate+startY;i++) {
    for(int j=startX;j<crossoverRate+startX;j++) {
      uvVoxelMap[i*dim + j] = other.uvVoxelMap[i*dim + j];
    }
  }
}

bool Individual::operator>(const Individual& other) const {
  return fitness > other.fitness;
}

bool Individual::operator<(const Individual& other) const {
  return fitness < other.fitness;
}

void Individual::operator=(const Individual& other) {
  if(uvVoxelMap) delete uvVoxelMap;
  uvVoxelMap = other.uvVoxelMap;
  dim8x = other.dim8x;
  fitness = other.fitness;
}

int Individual::getFitness() { return fitness; }
