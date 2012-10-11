//
//  main.cpp
//  StackMachineEmulator
//
//  Created by Ziyun Li on 12-10-11.
//  Copyright (c) 2012 Ziyun Li. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using std::cout;
using std::endl;
using std::string;
using std::stack;

int StackMachineEmulator(const string &S)
{
  const int kMax = (1 << 12) - 1;
  const int kMin = 0;
  stack<int> operands;
  
  for (string::const_iterator iter = S.begin(); iter != S.end(); ++iter) {
    if ((*iter) >= '0' && (*iter) <= '9') {
      operands.push((*iter) - '0');
    } else if ((*iter) == '+') {
      int op1, op2;
      
      if (!operands.empty()) {
        op1 = operands.top();
        operands.pop();
      } else return -1;
      
      if (!operands.empty()) {
        op2 = operands.top();
        operands.pop();
      } else return -1;
      
      int result = op1 + op2;
      if (result < kMin || result > kMax)
        return -1;
      else
        operands.push(result);
      
    } else if ((*iter) == '*') {
      int op1, op2;
      
      if (!operands.empty()) {
        op1 = operands.top();
        operands.pop();
      } else return -1;
      
      if (!operands.empty()) {
        op2 = operands.top();
        operands.pop();
      } else return -1;
      
      int result = op1 * op2;
      if (result < kMin || result > kMax)
        return -1;
      else
        operands.push(result);
    }
  }
  
  int result = operands.top();
  operands.pop();
  if (operands.empty()) {
    return result;
  }
  else
    return -1;
}

int main(void)
{
  string operations = "13+62*7+＊";
  cout << StackMachineEmulator(operations);
  
  return 0;
}
