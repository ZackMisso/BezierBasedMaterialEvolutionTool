#include <iostream>
#include <stdlib.h>
#include "matData.h"
#include "programData.h"
#include "unitTests/unitTestSuite.h"
#include "ga.h"

using namespace std;

int main(int argc,char* argv[]) {
  // temporary for testing
  if(UnitTestSuite::runTests()) {
    cout << "Tests succeeded" << endl;
  } else {
    cout << "Tests failed" << endl;
  }
  return 0;

  ProgramData programData;
  // read in command line arguements
  for(int i=0;i<argc;i++) {
    // mutation rate flag
    if(argv[i] == "-m") programData.mutationRate = atoi(argv[i++]);
    // crossover rate flag
    else if(argv[i] == "-c") programData.crossoverRate = atoi(argv[++i]);
    // population size flag
    else if(argv[i] == "-pop") programData.populationSize = atoi(argv[++i]);
    // number of generations flag
    else if(argv[i] == "-gens") programData.totalGenerations = atoi(argv[++i]);
    // printing population data flag
    else if(argv[i] == "-pd") programData.printingPopulationData = true;
    // printing best individual flag
    else if(argv[i] == "-pb") programData.printingBestIndividual = true;
    // printing all individuals flag
    else if(argv[i] == "-pa") programData.printingAllIndividuals = true;
    // run test suite
    else if(argv[i] == "-test") if(!UnitTestSuite::runTests()) programData.brokenTests = true;
    // unrecognized arguement flag
    else cout << "Unrecognized Arguement: " << argv[i] << endl;
  }
  // initialize material data
  MatData matData;
  matData.numOfMat = 2;
  // check if tests failed
  if(programData.brokenTests) {
    cout << "Ending program because of broken tests" << endl;
    return -1;
  }
  // create ga
  GA ga(&programData,&matData);
  // run the experiment
  ga.runExperiment();
}
