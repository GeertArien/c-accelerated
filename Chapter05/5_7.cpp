/**
Accelerated C++, Exercise 5-7, 5_7.cpp

Given the implementation of frame in §5.8.1/93, and the following code fragment

      vector<string> v;
      frame(v);

describe what happens in this call. In particular, trace through how both the width
function and the frame function operate. Now, run this code. If the results differ from
your expectations, first understand why your expectations and the program differ, and
then change one to match the other.
*/

#include "stdafx.h"

#include "5_7.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "words.h"

int ex5_7() 
{
  vector<string> v;
  vector<string> v_framed = frame(v);

  vector<string>::const_iterator iter = v_framed.begin();

  while (iter != v_framed.end())
    cout << *iter++ << endl;

  return 0;
}