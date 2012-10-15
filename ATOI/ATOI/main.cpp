//
//  main.cpp
//  ATOI
//
//  Created by Ziyun Li on 12-10-14.
//  Copyright (c) 2012 Ziyun Li. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

long long ATOI(const string &str)
{
  int i;
  int n = static_cast<int>(str.size());
  bool neg = false;
  long long result = 0;
  
  if (str[0] == '-') {
    neg = true;
    i = 1;
  } else {
    i = 0;
  }
  
  for (; i < n; ++i) {
    result = result * 10 + (str[i] - '0');
  }
  
  if (neg) result *= -1;
  
  return result;
}


int main(int argc, const char * argv[])
{
  string str;
  cout << "Please input an integer(be careful of overflow): " << endl;
  cin >> str;
  cout << "Result: " << ATOI(str) << endl;
  return 0;
}

