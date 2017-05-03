/**
Accelerated C++, Exercise 11-9, 11_9.cpp

The grow function in §11.5.1/208 doubles the amount of memory each time it
needs more. Estimate the efficiency gains of this strategy. Once you've predicted how
much of a difference it makes, change the grow function appropriately and measure the
difference.
*/

#include "stdafx.h"
#include "11_9.h"

#include <iostream>
using std::cout;
using std::endl;

#include <chrono>
using std::chrono::steady_clock;

#include "vec.h"

int test_grow(int appends)
{
  Vec<int> v1;
  Vec<int> v2;

  steady_clock::time_point begin = std::chrono::steady_clock::now();
  for (int i = 0; i < appends; i++)
    v1.push_back(i);
  steady_clock::time_point end = std::chrono::steady_clock::now();
  cout << "Microseconds to add " << appends << " to vector using double memory method = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;


  begin = std::chrono::steady_clock::now();
  for (int i = 0; i < appends; i++)
    v2.push_back(i, false);
  end = std::chrono::steady_clock::now();
  cout << "Microseconds to add " << appends << " to vector without using double memory method = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

  return 0;
}

int ex11_9()
{
  test_grow(1000);

  return 0;
}