#include "programData.h"

ProgramData::ProgramData() {
  evolved = 0x0;
  desired = 0x0;
  mutationChance = .800f;
  crossoverChance = .200f;
  crossoverWeight = .500f;
  mutationRate = 3;
  crossoverRate = 2;
  printingPopulationData = false;
  printingBestIndividual = true;
  printingAllIndividuals = false;
  brokenTests = false;
  uvDimension = 4;
  totalGenerations = 1000;
  populationSize = 1000;
}

ProgramData::~ProgramData() {
  if(evolved) delete evolved;
  if(desired) delete desired;
}
