/**
Accelerated C++, Exercise 2-10, 2_10.cpp

Explain each of the uses of std:: in the following program:

    int main() {
      int k = 0;
      while (k != n) { // invariant: we have written k asterisks so far
        using std::cout;
        cout << "*";
        ++k;
      }
      std::cout << std::endl; // std:: is required here
      return 0;
    }

*/

#include "stdafx.h"
#include "2_9.h"

#include <iostream>
using std::cout;
using std::endl;

const int n = 5;

int ex2_10() 
{
  int k = 0;
  while (k != n) 
  {        
    using std::cout;      // the using statement is only relevant to the local while scope
    cout << "*";
    ++k;
  }
  std::cout << std::endl; // std:: is required here
  return 0;
}