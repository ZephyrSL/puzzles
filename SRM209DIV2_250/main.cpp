#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class MovingAverages {

public:
  MovingAverages() {}
  ~MovingAverages() {}

  vector<int> calculate(vector<string> &times, int &n);
};


vector<int> MovingAverages::calculate(vector<string> &times, int &n)
{
  int t = times.size();
  vector<int> ntimes; // numerical times
  vector<int> result; // result vector

  if (t < n)  return result;

  // iterate every string
  for (int i = 0; i < t; ++i) {
    // convert string to integer
    int h, m, s;
    sscanf(times[i].c_str(), "%d:%d:%d", &h, &m, &s);
    int ntime = 3600 * h + 60 * m + s;
    ntimes.push_back(ntime);  // save the converted result
  }

  // Calculate n-average
  for (int i = n - 1; i < t; ++i) {
    int sum = 0;
    for (int j = 0; j < n; ++j) {
      sum += ntimes[i - j];
    }
    result.push_back(sum / n);
  }

  return result;
}