#include "ga.h"

GA::GA(int pop,int gens) {
  population = new Individual[pop];
  populationSize = pop;
  currentGeneration = 0;
  totalGenerations = gens;
}

GA::~GA() {
  delete population;
}

void GA::insertionSort(Individual* objects,int start,int end) {
  // to be implemented
}

void GA::mergeSort(Individual* objects,int size) {
  // to be implemented
}

void GA::merge(Individual* one,int szOne,Individual* two,int szTwo) {
  // to be implemented
}

void GA::inOrderMergeSort(Individual* objects,int start,int end) {
  // to be implemented
}
