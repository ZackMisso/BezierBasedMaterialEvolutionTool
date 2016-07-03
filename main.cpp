#include <iostream>
#include <stdlib.h>
#include "matData.h"
#include "programData.h"
#include "manualEditor.h"
#include "unitTests/unitTestSuite.h"
#include "ga.h"

using namespace std;

int main(int argc,char* argv[]) {
  // temporary for testing
  //if(UnitTestSuite::runTests()) {
  //  cout << "Tests succeeded" << endl;
  //} else {
  //  cout << "Tests failed" << endl;
  //}
  //return 0;

  ProgramData programData;
  cout << "argc: " << argc << endl;
  // read in command line arguements
  for(int i=1;i<argc;i++) {
    cout << "YEA" << endl;
    // mutation rate flag
    if(!strcmp(argv[i],"-m")) programData.mutationRate = atoi(argv[++i]);
    // mutation chance flag
    else if(!strcmp(argv[i],"-mc")) programData.mutationChance = atof(argv[++i]);
    // crossover rate flag
    else if(!strcmp(argv[i],"-c")) programData.crossoverRate = atoi(argv[++i]);
    // crossover chance flag
    else if(!strcmp(argv[i],"-cc")) programData.crossoverChance = atof(argv[++i]);
    // population size flag
    else if(!strcmp(argv[i],"-pop")) programData.populationSize = atoi(argv[++i]);
    // number of generations flag
    else if(!strcmp(argv[i],"-gens")) programData.totalGenerations = atoi(argv[++i]);
    // printing population data flag
    else if(!strcmp(argv[i],"-pd")) programData.printingPopulationData = true;
    // printing best individual flag
    else if(!strcmp(argv[i],"-pb")) programData.printingBestIndividual = true;
    // printing all individuals flag
    else if(!strcmp(argv[i],"-pa")) programData.printingAllIndividuals = true;
    // run test suite
    else if(!strcmp(argv[i],"-test")) {
      cout << "Running Unit Tests" << endl;
      if(!UnitTestSuite::runTests()) programData.brokenTests = true;
    }
    // run manual tests
    else if(!strcmp(argv[i],"-mtest")) {
      cout << "Starting up Manual Tester" << endl;
      ManualEditor editor(&programData);
      editor.runEditor();
      return 0;
    }
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
