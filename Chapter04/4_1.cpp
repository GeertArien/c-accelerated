/**
Accelerated C++, Exercise 4-1, 4_1.cpp

We noted in §4.2.3/65 that it is essential that the argument types in a call to max
match exactly. Will the following code work? If there is a problem, how would you fix it?

  int maxlen;
  Student_info s;
  max(s.name.size(), maxlen);

*/

#include "stdafx.h"
#include "4_1.h"

#include <string>
using std::string;

#include <algorithm>
using std::max;

#include "student_info.h"

int ex4_1() 
{
  //int max_len;
  string::size_type max_len;
  Student_info s;
  max(s.name.size(), max_len);

  return 0;
}