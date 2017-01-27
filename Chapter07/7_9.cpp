/**
Accelerated C++, Exercise 7-9, 7_9.cpp

(difficult) The implementation of nrand in §7.4.4/135 will not work for arguments
greater than RAND_MAX. Usually, this restriction is no problem, because RAND_MAX is
often the largest possible integer anyway. Nevertheless, there are implementations
under which RAND_MAX is much smaller than the largest possible integer. For example,
it is not uncommon for RAND_MAX to be 32767 (215 -1) and the largest possible integer
to be 2147483647 (231 -1). Reimplement nrand so that it works well for all values of n
*/

#include "stdafx.h"

#include <stdexcept>
using std::domain_error;

#include <iostream>
using std::cout;
using std::endl;

int nrand_improved(int n, const int max = RAND_MAX) {

  if (n <= 0)
    throw domain_error("Argument to nrand is out of range");

  if (n <= max) 
  {
    const int bucket_size = max / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);

    return r;
  }
  else
  {
    const int buckets = n / max;
    const int remainder_rand = n % max == 0 ? 0 : nrand_improved(n % max);
    const int lost = n % max == 0 ? buckets : buckets + 1;

    return nrand_improved(max) * buckets + remainder_rand + nrand_improved(lost);
  }
}

int ex7_9()
{
  for (int i = 0; i < 100; i++)
    cout << nrand_improved(100, 3) << endl;

  return 0;
}