/**
Accelerated C++, Exercise 15-1, 15_1.cpp

Test your system by writing a program that executes

  Picture p = // some initial starting picture
  Picture q = frame(p);
  Picture r = hcat(p, q) ;
  Picture s = vcat(q, r);
  cout << frame(hcat(s, vcat(r, q))) << endl;

*/

#include "stdafx.h"
#include "15_1.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "pic.h"

int ex15_1()
{
  vector<string> v1 = { "one test", "two test", "aye caramba" };
  Picture p = v1;
  Picture q = frame(p);
  Picture r = hcat(p, q);
  Picture s = vcat(q, r);
  cout << frame(hcat(s, vcat(r, q))) << endl;

  return 0;
}