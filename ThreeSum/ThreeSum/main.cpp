//
//  main.cpp
//  ThreeSum
//
//  Created by Ziyun Li on 12-10-14.
//  Copyright (c) 2012 Ziyun Li. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {
  // Using a Quadratic algorithm from http://en.wikipedia.org/wiki/3SUM
  
  vector<vector<int> > results;
  sort(num.begin(), num.end());
  
  // Test output
  cout << "Original array: ";
  copy(num.begin(), num.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  
  int n = (int)num.size();
  for(int i = 0; i < n - 2; ++i) {
    // quick termination
    if (i > 0 && num[i] == num[i - 1]) continue;
    
    int a = num[i];
    int k = i + 1;
    int l = n - 1;
    
    while (k < l) {
      int b = num[k];
      int c = num[l];
      
      if (a + b + c == 0) {
        vector<int> triple {a, b, c};
        results.push_back(triple);
        l = l - 1;
        k = k + 1;
      } else if (a + b + c > 0) {
        l = l - 1;
      } else {
        k = k + 1;
      }
    }
  }
  
  return results;
  
}

int main(int argc, const char * argv[])
{

  vector<int> num {-1, 0, 1, 2, -1, -4};
  vector<vector<int> > results = threeSum(num);
  
  cout << endl << "Result triples: " << endl;
  for (vector<vector<int> >::iterator iter = results.begin();
       iter != results.end();
       ++iter) {
    copy((*iter).begin(), (*iter).end(), ostream_iterator<int>(cout, " "));
    cout << endl;
  }
  
  return 0;
}

