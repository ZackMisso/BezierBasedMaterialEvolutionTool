#pragma once

class UnitTestSuite {
private:
public:
  static bool runTests();
  // in order merge sort test
  static bool mergeSortTest();
  static void mergeSort(int* objects,int start,int end);
};
