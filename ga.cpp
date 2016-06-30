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

void GA::runExperiments() {
  // to be implemented
}

void GA::initializeData() {
  // to be implemented
}

void GA::initializeRun() {
  // to be implemented
}

void GA::printPopulationData() {
  // to be implemented
}

void GA::printBestIndividualData() {
  // to be implemented
}

void GA::printAllIndividualData() {
  // to be implemented
}

void GA::calculateFitnesses() {
  // to be implemented
}

void GA::mutateIndividuals() {
  // to be implemented
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
