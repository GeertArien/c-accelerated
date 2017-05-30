/**
Accelerated C++, Exercise 15-2, 15_2.cpp

Reimplement the Frame_Pic class so that the frame uses three different
characters: one for the corners, another for the top and bottom borders, and a third for
the side borders.
*/

#include "stdafx.h"
#include "15_2.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "pic.h"

int ex15_2()
{
  vector<string> v1 = { "one test", "two test", "aye caramba" };
  Picture p = v1;
  Picture q = frame(p);
  Picture r = hcat(p, q);
  Picture s = vcat(q, r);
  cout << frame(hcat(s, vcat(r, q))) << endl;

  return 0;
}