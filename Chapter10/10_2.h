#ifndef GUARD_10_2_H
#define GUARD_10_2_H

#include <exception>
#include <vector>
#include <algorithm>

int ex10_2();

template<class T, class In>
T median(In begin, const In end)
{
  if (begin == end)
    throw std::domain_error("median of an empty container");

  std::vector<T> v;

  while (begin != end)
    v.push_back(*begin++);

  std::sort(v.begin(), v.end());

  std::vector<T>::size_type mid = v.size() / 2;
  return v.size() % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

#endif // !GUARD_10_2_H