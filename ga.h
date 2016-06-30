#pragma once

// the genetic algorithm implementation

#include "individual.h"
#include "matData.h"

class GA {
private:
  Individual* population;
  MaterialData* data;
  int populationSize;
  int currentGeneration;
  int totalGenerations;
  // genetic algorithm methods
  void initializeData();
  void initializeRun();
  void simulateEvolution();
  void printPopulationData();
  void printBestIndividualData();
  void printAllIndividualData();
  void calculateFitnesses();
  void mutateIndividuals();
public:
  GA(int pop,int gens);
  ~GA();
  void runExperiment();
  // implementing multiple sorts because I want to see which one is faster
  // logically, insertion sort should be the slowest because of its Big Oh
  // However, after the first generation the population will be already
  // sorted. So, if the mutation rate is low enough, and there is not
  // significant changes amongst individuals, the population should stay
  // decently sorted. Meaning insertion sort will be fast since its best
  // case scenario (already sorted) is O(N).
  void insertionSort(Individual* objects,int start,int end);
  void mergeSort(Individual* objects,int size);
  void merge(Individual* one,int szOne,Individual* two,int szTwo);
  void inOrderMergeSort(Individual* objects,int start,int end);
};
