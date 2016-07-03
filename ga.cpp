#include "ga.h"
#include "random.h"
#include <iostream>

using namespace std;

GA::GA(ProgramData* pd,MatData* md) {
  populationSize = pd->populationSize;
  //cout << "PopulationSize: " << populationSize;
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
    // sort individuals by fitness
    sortIndividuals();
    // print info if specified
    if(programData->printingPopulationData) printPopulationData();
    if(programData->printingAllIndividuals) printAllIndividualData();
    if(programData->printingBestIndividual) printBestIndividualData();
    // mutate the individuals if it is not the last generation
    if(i!=totalGenerations-1) mutateIndividuals();
    currentGeneration++;
  }
}

void GA::initializeData() {
  for(int i=0;i<populationSize;i++) population[i].initialize(programData->uvDimension);
  programData->desired = new Individual();
  // initialize the desired solution (test)
  programData->desired->initializeZero(programData->uvDimension);
}

void GA::initializeRun() {
  for(int i=0;i<populationSize;i++) population[i].randomize(matData);
  // fill in the data for the desired solution (test)
  //programData->desired->randomize(matData);
}

void GA::printPopulationData() {
  // to be implemented
}

void GA::printBestIndividualData() {
  cout << "Best Individual Fitness for Gen " << currentGeneration << ": " << population[0].getFitness() << endl;
}

void GA::printAllIndividualData() {
  // to be implemented
}

void GA::calculateFitnesses() {
  for(int i=0;i<populationSize;i++) population[i].calculateFitness(*(programData->desired));
}

void GA::mutateIndividuals() {
  for(int i=0;i<populationSize;i++) {
    float tmp = Random::getRandomFloat();
    if(tmp < programData->mutationChance) population[i].mutate(programData->mutationRate);
    else {
      // TODO :: implement weight logic
      int randInd = Random::getRandomIntNotIncluding(populationSize,i);
      population[i].crossover(population[randInd],programData->crossoverRate);
    }
  }
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
  delete[] inds;
}

