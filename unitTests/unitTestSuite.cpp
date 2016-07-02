#include "unitTestSuite.h"

bool UnitTestSuite::runTests() {
  if(!mergeSortTest()) return false;
  return true;
}

bool UnitTestSuite::mergeSortTest() {
  int* testData = new int[10];
  testData[0] = 7;
  testData[1] = 5;
  testData[2] = 4;
  testData[3] = 9;
  testData[4] = 1;
  testData[5] = 2;
  testData[6] = 0;
  testData[7] = 6;
  testData[8] = 3;
  testData[9] = 8;
  mergeSort(testData,0,10);
  for(int i=0;i<10;i++)
    if(testData[i] != i) 
      return false;
  return true;
}

void UnitTestSuite::mergeSort(int* objects,int start,int end) {
  int range = end - start;
  int midPoint = (range >> 1) + start;
  if(end - start != 1) {
    mergeSort(objects,start,midPoint);
    mergeSort(objects,midPoint,end);
  }
  int nums[range];
  int tmp = start;
  int tmp2 = midPoint;
  int i=0;
  while(tmp != midPoint && tmp2 != end) {
    if(objects[tmp] > objects[tmp2]) {
      nums[i] = objects[tmp2];
      tmp2++;
    } else {
      nums[i] = objects[tmp];
      tmp++;
    }
    i++;
  }
  while(tmp != midPoint) nums[i++] = objects[tmp++];
  while(tmp2 != end) nums[i++] = objects[tmp2++];
  for(int i=0;i<range;i++) objects[i+start] = nums[i];
}
