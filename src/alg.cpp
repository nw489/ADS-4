// Copyright 2021 NNTU-CS
#include <cstdint>
#include "alg.h"

int countPairs1(int *arr, int len, int value) {
  int pairCount = 0;
  for (int firstIdx = 0; firstIdx < len; firstIdx++) {
    for (int secondIdx = firstIdx + 1; secondIdx < len; secondIdx++) {
      if (arr[firstIdx] + arr[secondIdx] == value) {
        pairCount++;
      }
    }
  }
  return pairCount;
}

int countPairs2(int *arr, int len, int value) {
  int pairCount = 0;
  int leftPtr = 0;
  int rightPtr = len - 1;
  
  while (leftPtr < rightPtr) {
    int currentSum = arr[leftPtr] + arr[rightPtr];
    
    if (currentSum == value) {
      int leftDupCount = 1;
      int rightDupCount = 1;
      
      while (leftPtr + leftDupCount < rightPtr && 
             arr[leftPtr] == arr[leftPtr + leftDupCount]) {
        leftDupCount++;
      }
      
      while (rightPtr - rightDupCount > leftPtr && 
             arr[rightPtr] == arr[rightPtr - rightDupCount]) {
        rightDupCount++;
      }
      
      if (arr[leftPtr] == arr[rightPtr]) {
        int totalSize = leftDupCount + rightDupCount;
        pairCount += totalSize * (totalSize - 1) / 2;
      } else {
        pairCount += leftDupCount * rightDupCount;
      }
      
      leftPtr += leftDupCount;
      rightPtr -= rightDupCount;
    } 
    else if (currentSum < value) {
      leftPtr++;
    } 
    else {
      rightPtr--;
    }
  }
  
  return pairCount;
}

int findFirstOccurrence(int *arr, int leftBound, int rightBound, int targetVal) {
  int resultIdx = -1;
  while (leftBound <= rightBound) {
    int midPoint = leftBound + (rightBound - leftBound) / 2;
    if (arr[midPoint] == targetVal) {
      resultIdx = midPoint;
      rightBound = midPoint - 1;
    } 
    else if (arr[midPoint] < targetVal) {
      leftBound = midPoint + 1;
    } 
    else {
      rightBound = midPoint - 1;
    }
  }
  return resultIdx;
}

int findLastOccurrence(int *arr, int leftBound, int rightBound, int targetVal) {
  int resultIdx = -1;
  while (leftBound <= rightBound) {
    int midPoint = leftBound + (rightBound - leftBound) / 2;
    if (arr[midPoint] == targetVal) {
      resultIdx = midPoint;
      leftBound = midPoint + 1;
    } 
    else if (arr[midPoint] < targetVal) {
      leftBound = midPoint + 1;
    } 
    else {
      rightBound = midPoint - 1;
    }
  }
  return resultIdx;
}

int countPairs3(int *arr, int len, int value) {
  int pairCount = 0;
  
  for (int currentIdx = 0; currentIdx < len; currentIdx++) {
    if (currentIdx > 0 && arr[currentIdx] == arr[currentIdx - 1]) {
      continue;
    }
    
    int neededVal = value - arr[currentIdx];
    if (neededVal < arr[currentIdx]) {
      break;
    }
    
    int firstPos = findFirstOccurrence(arr, currentIdx + 1, len - 1, neededVal);
    if (firstPos == -1) {
      continue;
    }
    
    int lastPos = findLastOccurrence(arr, currentIdx + 1, len - 1, neededVal);
    
    if (arr[currentIdx] == neededVal) {
      int groupSize = lastPos - firstPos + 1 + 1;
      pairCount += groupSize * (groupSize - 1) / 2;
      break;
    } 
    else {
      int leftGroupFirst = findFirstOccurrence(arr, 0, len - 1, arr[currentIdx]);
      int leftGroupLast = findLastOccurrence(arr, 0, len - 1, arr[currentIdx]);
      int leftGroupCount = leftGroupLast - leftGroupFirst + 1;
      pairCount += leftGroupCount * (lastPos - firstPos + 1);
    }
  }
  
  return pairCount;
}
