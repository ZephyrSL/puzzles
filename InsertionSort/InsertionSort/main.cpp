/* Enter your code here. Read input from STDIN. Print output to STDOUT */

//
//  main.cpp
//  InsertionSort
//
//  Created by Ziyun Li on 12-10-11.
//  Copyright (c) 2012 Ziyun Li. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <queue>
using std::queue;
using std::ostream_iterator;
using std::cin;
using std::cout;
using std::endl;

const int kMaxN = 100002;

long long Combine(int a[], int start, int m, int end)
{
  queue<int> left,right;
  
  for (int i = start; i <= m; ++i) {
    left.push(a[i]);
  }
  
  for (int j = m + 1; j <= end; ++j)
  {
    right.push(a[j]);
  }
  
  int length_left = left.size();
  long long num_inv = 0;
  
  int s = start;
  int i = 0;
  
  while (!left.empty() && !right.empty()) {
    if (left.front() <= right.front()) {
      a[s++] = left.front();
      left.pop();
      i++;
    } else if (left.front() > right.front()) {
      a[s++] = right.front();
      right.pop();
      num_inv += length_left - i;
    }
  }
  
  while (!left.empty()) {
    a[s++] = left.front();
    left.pop();
  }
  
  while (!right.empty()) {
    a[s++] = right.front();
    right.pop();
  }
  
  return num_inv;
}

long long MergeSort(int a[], int start, int end)
{
  if (start >= end) {
    return 0;
  }
  
  int m;
  long long x = 0;
  long long y = 0;
  long long z = 0;
  if (start < end) {
    m = (start + end) / 2;
    x = MergeSort(a, start, m);
    y = MergeSort(a, m + 1, end);
    z = Combine(a, start, m, end);
  }
  
  return (x + y + z);
}

int main(int argc, const char * argv[])
{
  int a[kMaxN];
  
  int runs;
  // cout << "Please setup the runs: ";
  cin >> runs;
  
  int n; // number of elements in an array
  while (runs--)
  {
    // cout << "Please input the length of array: ";
    cin >> n;
    // cout << "Please enter the array:" << endl;
    for (int i = 0; i < n; ++i)
    {
      int temp;
      cin >> temp;
      a[i] = temp;
    }
    
    // cout << "Num inverstion: " << MergeSort(a, 0, n - 1) << endl;
    cout << MergeSort(a, 0, n - 1) << endl;
    // copy(a, a + n, ostream_iterator<int>(cout, " "));
    // cout << endl;
    
  }
  
  return 0;
}

