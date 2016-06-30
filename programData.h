#pragma once

// a class to hold the temp program data while the user looks at
// things in the interactive mode

#include "individual.h"

class ProgramData {
public:
  Individual* evolved;
  Individual* desired;
  int mutationRate;
  int crossoverRate;
  bool printingPopulationData;
  bool printingBestIndividual;
  bool pringitnAllIndividuals;

  ProgramData();
  ~ProgramData();
};
