/**
Accelerated C++, Exercise 15-3, 15_3.cpp

Give users the option to specify what characters to use for these border
characters.
*/

#include "stdafx.h"
#include "15_3.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "pic.h"

int ex15_3()
{
  vector<string> v1 = { "one test", "two test", "aye caramba" };
  Picture p = v1;
  Picture q = frame(p, '+', '*', '*');
  Picture r = hcat(p, q);
  Picture s = vcat(q, r);
  cout << frame(hcat(s, vcat(r, q))) << endl;

  return 0;
}