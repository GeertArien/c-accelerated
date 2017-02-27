/**
Accelerated C++, Exercise 4-7, 4_7.cpp

Write a program to calculate the average of the numbers stored in a
vector<double>.
*/

#include "stdafx.h"
#include "4_7.h"

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

double average(const vector<double>& nums) 
{
  double sum = 0;

  for (vector<double>::size_type i = 0; i < nums.size(); i++)
    sum += nums[i];

  return sum / nums.size();
}

int ex4_7()
{
  vector<double> numbers = { 10.2, 15.7, 18.5, 9.7, 25.2 };
  cout << average(numbers) << endl;

  return 0;
}