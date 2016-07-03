#pragma once

class UnitTestSuite {
private:
public:
  static bool runTests();
  // in order merge sort test
  static bool mergeSortTest();
  static void mergeSort(int* objects,int start,int end);
  static bool crossoverTest();
  static void crossover(unsigned char* one,unsigned char* two,int startX,int startY,int dim);
  static bool mutationTest();
  static void mutate(unsigned char* one,int index,int index8);
};
