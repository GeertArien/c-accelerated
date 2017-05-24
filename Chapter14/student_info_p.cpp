#include"stdafx.h"
#include "student_info_p.h"

#include <iostream>
using std::istream;

istream& Student_info_p::read(istream& is)
{
  char ch;
  is >> ch; // get record type

  if (ch == 'U')
    cp = new Core(is);
  else
    cp = new Grad(is);
  return is;
}
