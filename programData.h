#pragma once

// a class to hold the temp program data while the user looks at
// things in the interactive mode

#include "individual.h"

class ProgramData {
public:
  Individual* evolved;
  Individual* desired;
  float mutationChance;
  float crossoverChance;
  float crossoverWeight;
  int mutationRate;
  int crossoverRate;
  int populationSize;
  int totalGenerations;
  int uvDimension;
  bool printingPopulationData;
  bool printingBestIndividual;
  bool printingAllIndividuals;
  bool brokenTests;

  ProgramData();
  ~ProgramData();
};
