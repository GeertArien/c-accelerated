/**
Accelerated C++, Exercise 15-5, 15_5.cpp

Reimplement HCat_Pic so that when pictures of a different size are
concatenated, the shorter one is centered in the space consumed by the longer one.
That is, if we horizontally concatenate two pictures, one of which is four lines long and
the other is two lines long, the first and last rows of the output picture will be blank on
the side of the shorter picture. What can we now conclude about the necessity of the
tests between row and 0.
*/

#include "stdafx.h"
#include "15_5.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "pic.h"

int ex15_5()
{
  vector<string> v1 = { "one test", "aye caramba" };
  vector<string> v2 = { "one direction", "mama mia", "mamo testo", "lake district mall" };

  cout << frame(hcat(v1, v2)) << endl;

  cout << hcat(v2, v1) << endl;

  cout << hcat(frame(v1), v2) << endl;

  return 0;
}