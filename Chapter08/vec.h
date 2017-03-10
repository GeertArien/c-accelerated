#ifndef GUARD_vec_H
#define GUARD_vec_H

#include <vector>
#include <exception>
#include <algorithm>
#include <numeric>

template<class T>
T median(std::vector<T> v)
{
  typedef typename std::vector<T>::size_type vec_sz;
  vec_sz size = v.size();
  if (size == 0)
    throw std::domain_error("median of an empty vector");
  std::sort(v.begin(), v.end());

  vec_sz mid = size / 2;
  return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

inline
double average(const std::vector<double>& v)
{
  return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}

#endif // !GUARD_vec_H