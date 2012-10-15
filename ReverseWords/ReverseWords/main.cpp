//
//  main.cpp
//  ReverseWords
//
//  Created by Ziyun Li on 12-10-14.
//  Copyright (c) 2012 Ziyun Li. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

string& ReverseWords(string &str) {
  int n = static_cast<int>(str.size());
  int m = (n - 2) / 2;
  
  for (int i = 0; i <= m; ++i) {
    // swap characters
    char temp = str[i];
    str[i] = str[n - 1 - i];
    str[n - 1 - i] = temp;
  }
  
  // test print
  // copy(str.begin(), str.end(), ostream_iterator<char>(cout, ""));
  
  int prev_space = -1;
  for (int i = 0; i <= n; ++i) {
    if (str[i] == ' ' || i == n){
      int s = prev_space + 1;
      int d = i - prev_space - 1;
      int m = (d - 2) / 2;
      for (int j = 0; j <= m; ++j) {
        // swap characters in the same word
        char temp = str[s + j];
        str[s + j] = str[i - 1 - j];
        str[i - 1 - j] = temp;
      }
      prev_space = i;
    }
  }
  
  return str;
  
}

int main(int argc, const char * argv[])
{
  string str = "what the fuck";
  
  cout << "Original string: " << str << endl;
  
  cout << "Reversed string: " << ReverseWords(str) << endl;
  return 0;
}

