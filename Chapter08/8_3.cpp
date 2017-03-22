/**
Accelerated C++, Exercise 8-3, 8_3.cpp

As we learned in §4.1.4/58, it can be expensive to return (or pass) a container by
value. Yet the median function that we wrote in §8.1.1/140 passes the vector by
value. Could we rewrite the median function to operate on iterators instead of passing
the vector ? If we did so, what would you expect the performance impact to be?
*/

#include "stdafx.h"
#include "8_3.h"

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <chrono>
using std::chrono::steady_clock;

#include <iterator>

#include "vec.h"

int ex8_3()
{
  vector<int> vec1 = { 85, 74, 75, 45, 49 , 66};

  // sorting the vector so the sorting step in the median functions won't affect performance
  std::sort(vec1.begin(), vec1.end());

  steady_clock::time_point begin = std::chrono::steady_clock::now();

  for (int i = 0; i < 100; i++)
  {
    median(vec1);
  }
  
  steady_clock::time_point end = std::chrono::steady_clock::now();
  cout << "Microseconds to run median 100 times using pass by value = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

  begin = std::chrono::steady_clock::now();

  for (int i = 0; i < 100; i++)
  {
    median_iter<vector<int>::iterator, int>(vec1.begin(), vec1.end());
  }

  end = std::chrono::steady_clock::now();
  cout << "Microseconds to run median 100 times using iterators = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

  return 0;
}