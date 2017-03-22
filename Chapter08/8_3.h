#ifndef GUARD_8_3_H
#define GUARD_8_3_H

#include <iterator>
#include <exception>
#include <algorithm>

int ex8_3();

template<class Ran, class T>
T median_iter(Ran b, Ran e)
{
  T count = std::distance(b, e);

  if (count == 0)
    throw std::domain_error("median of an empty container");

  std::sort(b, e);

  T mid = count / 2;

  std::advance(b, mid - 1);

  return count % 2 == 0 ? (*b++ + *b) / 2 : *++b;
}

#endif // !GUARD_8_3_H