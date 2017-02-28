/**
Accelerated C++, Exercise 2-9, 2_9.cpp

Write a program that asks the user to enter two numbers and tells the user which
number is larger than the other.
*/

#include "stdafx.h"
#include "2_9.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int ex2_9() 
{
  int num1, num2;

  cout << "Enter the first number: ";
  cin >> num1;
  cout << "Enter the second number: ";
  cin >> num2;
  if (num1 == num2)
  {
    cout << "Both numbers are equal" << endl;
  }
  else if (num1 > num2)
  {
    cout << num1 << " is bigger than " << num2 << endl;
  }
  else 
  {
    cout << num2 << " is bigger than " << num1 << endl;
  }

  return 0;
}