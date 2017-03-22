/**
Accelerated C++, Exercise 8-8, 8_8.cpp

In the binary_search function in §8.2.6/148, why didn't we write (begin +
end) / 2 instead of the more complicated begin + (end - begin) /2 ?
*/

#include "stdafx.h"
#include "8_8.h"

#include <vector>
using std::vector;

template<class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
  while (begin < end)
  {
    // Doesn't point to the correct element, invalid operation
    // Ran mid = (begin + end) / 2;

    // find the midpoint of the range
    Ran mid = begin + (end - begin) / 2;
    // see which part of the range contains x; keep looking only in that part
    if (x < *mid)
      end = mid;
    else if (*mid < x)
      begin = mid + 1;
    // if we got here, then *mid == x so we're done
    else return true;
  }
  return false;
}

int ex8_8()
{
  vector<int> v = { 4, 17, 9, 23, 36 };

  binary_search(v.begin(), v.end(), 23);
  return 0;
}