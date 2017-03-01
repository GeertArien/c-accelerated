/**
Accelerated C++, Exercise 6-0, 6_0.cpp

Compile, execute, and test the programs in this chapter.
*/

#include "stdafx.h"
#include "6_0.h"

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "student_info.h"

int ex6_0() 
{
  vector<Student_info> did, didnt;
  Student_info student;

  while (read(cin, student)) 
  {
    if (did_all_hw(student))
      did.push_back(student);
    else
      didnt.push_back(student);
  }

  if (did.empty()) 
  {
    cout << "No student did all the homework!" << endl;
    return 1;
  }

  if (didnt.empty()) 
  {
    cout << "Every student did all the homework!" << endl;
    return 1;
  }

  write_analysis(cout, "median", median_analysis, did, didnt);
  write_analysis(cout, "average", average_analysis, did, didnt);

  return 0;
}