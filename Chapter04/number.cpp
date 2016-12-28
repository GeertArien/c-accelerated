#include "stdafx.h"
#include "number.h"

using std::vector;

double average(const vector<double>& nums) {
  double sum = 0;

  for (vector<double>::size_type i = 0; i < nums.size(); i++)
    sum += nums[i];

  return sum / nums.size();
}