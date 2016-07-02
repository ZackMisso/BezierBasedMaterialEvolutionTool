#include "programData.h"

ProgramData::ProgramData() {
  evolved = 0x0;
  desired = 0x0;
  mutationRate = 10;
  crossoverRate = 10;
  printingPopulationData = false;
  printingBestIndividual = false;
  printingAllIndividuals = false;
  brokenTests = false;
  uvDimension = 40;
}

ProgramData::~ProgramData() {
  if(evolved) delete evolved;
  if(desired) delete desired;
}
