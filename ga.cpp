#include "ga.h"
#include <iostream>

using namespace std;

GA::GA(ProgramData* pd,MatData* md) {
  populationSize = pd->populationSize;
  totalGenerations = pd->totalGenerations;
  //population = new Individual[populationSize](pd->uvDiminsion);
  population = new Individual[populationSize];
  programData = pd;
  matData = md;
  currentGeneration = 0;
}

GA::~GA() {
  delete population;
  programData = 0x0;
  matData = 0x0;
}

void GA::runExperiment() {
  // initialize data
  initializeData();
  // initialize run
  initializeRun();
  // for every generation
  for(int i=0;i<totalGenerations;i++) {
    // calculate the fitness for every individual
    calculateFitnesses();
    // print info if specified
    if(programData->printingPopulationData) printPopulationData();
    if(programData->printingAllIndividuals) printAllIndividualData();
    if(programData->printingBestIndividual) printBestIndividualData();
    // sort individuals by fitness
    sortIndividuals();
    // mutate the individuals if it is not the last generation
    if(i!=totalGenerations-1) mutateIndividuals();
  }
}

void GA::initializeData() {
  for(int i=0;i<populationSize;i++) population[i].randomize(matData);
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
  mergeSort(population,0,populationSize);
}

void GA::insertionSort(Individual* objects,int start,int end) {
  // to be implemented
}

void GA::mergeSort(Individual* objects,int start,int end) {
  int range = end - start;
  int midPoint = (range >> 1) + start;
  if(end - start != 1) {
    mergeSort(objects,start,midPoint);
    mergeSort(objects,midPoint,end);
  }
  Individual* inds = new Individual[range];
  int tmp = start;
  int tmp2 = midPoint;
  int i=0;
  while(tmp != midPoint && tmp2 != end) {
    if(objects[tmp] < objects[tmp2]) inds[i] = objects[tmp2++];
    else inds[i] = objects[tmp++];
    i++;
  }
  while(tmp != midPoint) inds[i++] = objects[tmp++];
  while(tmp2 != end) inds[i++] = objects[tmp2++];
  for(int j=0;j<range;j++) objects[j+start] = inds[j];
  delete inds;
}

