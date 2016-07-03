#include "random.h"
#include <stdlib.h>

int Random::getRandomInt(int end) {
  return rand() % end;
}

int Random::getRandomInt(int start,int end) {
  return (rand() % (end - start)) + start;
}

int Random::getRandomIntNotIncluding(int end,int ignore) {
  int num = ignore;
  while(num == ignore) num = getRandomInt(end);
  return num;
}

// the floating point are not truly random, but it is ok for our tests
// because we do not need that much percision

float Random::getRandomFloat() {
  return static_cast<float>(rand())/static_cast<float>(RAND_MAX);
}

float Random::getRandomFloat(float start,float end) {
  return getRandomFloat() * (end - start) + start;
}

void Random::randomMat(unsigned char* mat,int dim,MatData* matData) {
  // Mat Data will be incorporated later
  for(int i=0;i<dim;i++)
    for(int j=0;j<dim;j++)
      mat[i*dim+j] = (unsigned char)(rand() & 0xFF);
}
