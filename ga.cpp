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
  for(int i=0;i<totalGenerations;i++) {
    calculateFitnesses();
    if(programData->printingPopulationData) printPopulationData();
    if(programData->printingAllIndividuals) printAllIndividualData();
    if(programData->printingBestIndividual) printBestIndividualData();
    sortIndividuals();
    if(i!=totalGenerations-1) mutateIndividuals();
  }
  
}

void GA::initializeData() {
  for(int i=0;i<populationSize;i++) population[i].randomize(data);
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

void GA::sortIndividuals() {
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
