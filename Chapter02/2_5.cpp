/**
Accelerated C++, Exercise 2-5, 2_5.cpp

Write a set of "*" characters so that they form a square, a rectangle, and a
triangle.
*/

#include "stdafx.h"
#include "2_5.h"

#include <iostream>
using std::cout;
using std::endl;

int ex2_5() 
{
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 10; j++) 
    {
      if (j == 0 || j == 10 - 1 || i == 0 || i == 7 - 1)
        cout << "*";
      else
        cout << " ";
    }
    cout << endl;
  }

  cout << endl;

  for (int i = 0; i < 10; i++) 
  {
    for (int j = 0; j < 10; j++) 
    {
      if (j == 0 || j == 10 - 1 || i == 0 || i == 10 - 1)
        cout << "*";
      else
        cout << " ";
    }
    cout << endl;
  }

  cout << endl;

  const int height = 7;
  const int width = height * 2 - 1;

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++) 
    {
      if ((i == height - 1) || (i == 0 && j == height - 1))
        cout << "*";
      else if (i > 0 && (j == height - 1 + i || j == height - 1 - i))
        cout << "*";
      else
        cout << " ";
    }
    cout << endl;
  }

  return 0;
}