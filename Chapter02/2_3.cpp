/**
Accelerated C++, Exercise 2-3, 2_3.cpp

Rewrite the framing program to ask the user to supply the amount of spacing to
leave between the frame and the greeting.
*/

#include "stdafx.h"
#include "2_3.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <string>
using std::string;

int FrameDynamic(istream& in, ostream& out, const int pad)
{
  cout << "Please enter your first name: ";

  string name;
  in >> name;

  const string greeting = "Hello, " + name + "!";
  const int rows = pad * 2 + 3;
  const string::size_type cols = greeting.size() + pad * 2 + 2;

  out << endl;

  for (int r = 0; r != rows; ++r)
  {
    string::size_type c = 0;

    while (c != cols)
    {

      if (r == pad + 1 && c == pad + 1)
      {
        out << greeting;
        c += greeting.size();
      }
      else
      {
        if (r == 0 || r == rows - 1 ||
          c == 0 || c == cols - 1)
          out << "*";
        else
          out << " ";
        ++c;
      }
    }

    out << endl;
  }

  return 0;
}

int ex2_3() 
{
  int padding;
  cout << "Please enter frame padding: ";
  cin >> padding;
  cout << endl;

  return FrameDynamic(cin, cout, padding);
}