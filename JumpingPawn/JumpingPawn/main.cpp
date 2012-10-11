//
//  main.cpp
//  JumpingPawn
//
//  Created by Ziyun Li on 12-10-11.
//  Copyright (c) 2012 Ziyun Li. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;

int arrayJmp(const vector<int> &A)
{
  int N = A.size();
  // create a visted buffer
  vector<bool> visited(N, false);
  
  int index = 0;
  int prev_index = 0;
  
  while (index < N && index >=0) {
    prev_index = index;
    if (visited[prev_index] == true) {
      return -1;
    } else {
    visited[prev_index] = true;
    }
    
    index = index + A[index];
  }
  
  if (index >= N || index < 0) {
    return prev_index;
  }
}

int main(void)
{
  vector<int> A {1, 1, -1, 1};
  std::cout << arrayJmp(A) << std::endl;
  
  vector<int> B {2, 3, -1, 1, 3};
  std::cout << arrayJmp(B) << std::endl;
  
  return 0;
}