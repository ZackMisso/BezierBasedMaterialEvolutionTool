#include "unitTestSuite.h"
#include <iostream>

using namespace std;

bool UnitTestSuite::runTests() {
  if(!mergeSortTest()) return false;
  if(!crossoverTest()) {
    cout << "Crossover Test Failed" << endl;
    return false;
  }
  if(!mutationTest()) {
    cout << "Mutation Test Failed" << endl;
    return false;
  }
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
  for(int j=0;j<range;j++) objects[j+start] = nums[j];
}

bool UnitTestSuite::crossoverTest() {
  unsigned char* one = new unsigned char[16];
  unsigned char* two = new unsigned char[16];
  for(int i=0;i<16;i++) {
    one[i] = 0x0;
    two[i] = 0x0;
  }
  two[5] = 0xFF;
  two[6] = 0xFF;
  two[9] = 0xFF;
  two[10] = 0xFF;
  crossover(one,two,1,1,4,2);
  //for(int i=0;i<4;i++) {
  //  for(int j=0;j<4;j++)
  //    cout << (int)one[i*4+j] << " ";
  //  cout << endl;
  //}
  bool pass = true;
  for(int i=0;i<16;i++) {
    if(i==5 || i==6 || i==9 || i==10) {
      //cout << (int)one[i] << endl;
      if(one[i] != 0xFF) pass = false;
    }
    else if(one[i] != 0x00) pass = false;
  }
  delete[] one;
  delete[] two;
  return pass;
}

void UnitTestSuite::crossover(unsigned char* one,unsigned char* two,int startX,int startY,int dim,int len) {
  for(int i=startY;i<startY+len;i++)
    for(int j=startX;j<startX+len;j++) {
      //cout << i*dim+j << " " << endl;
      one[i*dim+j] = two[i*dim+j];
    }
}

bool UnitTestSuite::mutationTest() {
  unsigned char* one = new unsigned char[3];
  one[0] = 0x00;
  one[1] = 0xFF;
  one[2] = 0x01;
  mutate(one,0,3);
  mutate(one,1,3);
  mutate(one,2,1);
  //cout << (int)one[0] << endl;
  //cout << (int)one[1] << endl;
  //cout << (int)one[2] << endl;
  if(one[0] != 0x08) return false;
  if(one[1] != 0xF7) return false;
  if(one[2] != 0x03) return false;
  delete[] one;
  return true;
}

void UnitTestSuite::mutate(unsigned char* one,int index,int index8) {
  char tmp = !((one[index] >> index8) & 0x1);
  //cout << "Tmp: " << (int)tmp << endl;
  //cout << "If True: " << (int)(one[index] & (0xFF & ~(0x1 << index8))) << endl;
  //cout << "0xF7: " << (int)0xF7 << endl;
  if(!tmp) one[index] = (one[index] & (0xFF & ~(0x1 << index8)));
  else one[index] = (one[index] | (0x00 | (0x1 << index8)));
  //cout << "ACTUAL :: " << (int)one[index] << endl;
}
