/**
Accelerated C++, Exercise 15-4, 15_4.cpp

Add an operation to reframe a Picture, which changes the frame characters.
The operation should change all of the frames in the interior picture.
*/

#include "stdafx.h"
#include "15_4.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "pic.h"

void Frame_Pic::reframe(const char corner, const char top_bot, const char side)
{
  this->corner = corner;
  this->top_bot = top_bot;
  this->side = side;

  p->reframe(corner, top_bot, side);
}

void VCat_Pic::reframe(const char corner, const char top_bot, const char side)
{
  top->reframe(corner, top_bot, side);
  bottom->reframe(corner, top_bot, side);
}

void HCat_Pic::reframe(const char corner, const char top_bot, const char side)
{
  left->reframe(corner, top_bot, side);
  right->reframe(corner, top_bot, side);
}

void Picture::reframe(const char corner, const char top_bot, const char side)
{
  p->reframe(corner, top_bot, side);
}

int ex15_4()
{
  vector<string> v1 = { "one test", "two test", "aye caramba" };
  Picture p = v1;
  Picture q = frame(p);
  Picture r = hcat(p, q);
  Picture s = vcat(q, r);
  Picture t = frame(hcat(s, vcat(r, q)));
  cout << t << endl;

  t.reframe('*', '*', '*');
  cout << t << endl;

  return 0;
}