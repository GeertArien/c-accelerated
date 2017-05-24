/**
Accelerated C++, Exercise 14-1, 14_1.cpp

Implement the comparison operation that operates on Ptr<Core>.
*/

#include "stdafx.h"
#include "14_1.h"

#include <sstream>
using std::stringstream;

#include <iostream>
using std::cout;
using std::endl;

#include "student_info.h"
#include "ptr.h"

int ex14_1()
{
  stringstream ss1("Jan 15 20 30 40");
  stringstream ss2("Jan 80 90 70 50");

  Ptr<Core> p1 = new Core(ss1);
  Ptr<Core> p2 = new Core(ss2);

  cout << "Is " << p1->name() << " == " << p2->name() << " ? " << (compare_Core_Ptr(p1, p2) == 0) << endl;

  return 0;
}