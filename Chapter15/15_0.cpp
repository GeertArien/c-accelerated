/**
Accelerated C++, Exercise 15-0, 15_0.cpp

Compile, execute, and test the programs in this chapter.
*/

#include "stdafx.h"
#include "15_0.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "pic.h"

int ex15_0()
{
  vector<string> v1 = { "one test", "two test", "aye caramba" };
  vector<string> v2 = { "one direction", "mama mia", "mamo testo", "lake district mall" };

  cout << frame(v1) << endl;

  cout << hcat(v1, v2) << endl;

  cout << vcat(frame(v1), frame(v2)) << endl;

  return 0;
}