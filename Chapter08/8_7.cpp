/**
Accelerated C++, Exercise 8-7, 8_7.cpp

Why doesn't the max function use two template parameters, one for each argument
type?
*/

#include "stdafx.h"
#include "8_7.h"

template<class L, class R, class O>
O max(const L& left, const R& right)
{
  return left > right ? left : right;
}// there's no way for the implementation to know what type will be returned when// two different arguments types are usedint ex8_7(){  max<int, double, double>(5, 4.5);  return 0;}