/**
Accelerated C++, Exercise 15-6, 15_6.cpp

The Vec and str classes that we developed in Chapters 11 and 12 are powerful
enough to be used to implement Pictures. Reimplement the material in this chapter to
use Vec<str> instead of vector<string>, and test your implementation.
*/

#include "stdafx.h"
#include "15_6.h"

#include <iostream>
using std::cout;
using std::endl;

#include "pic_v.h"

int ex15_6()
{
  Vec<Str> v1;
  v1.push_back("one test");
  v1.push_back("greeting");
  v1.push_back("how are you?");

  Picture_v p = v1;
  Picture_v q = frame(p);
  Picture_v r = hcat(p, q);
  Picture_v s = vcat(q, r);
  cout << frame(hcat(s, vcat(r, q))) << endl;

  return 0;
}