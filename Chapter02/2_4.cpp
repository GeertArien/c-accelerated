/**
Accelerated C++, Exercise 2-4, 2_4.cpp

The framing program writes the mostly blank lines that separate the borders from
the greeting one character at a time. Change the program so that it writes all the spaces
needed in a single output expression.
*/

#include "stdafx.h"
#include "2_4.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <string>
using std::string;

int FrameDynamicAlt(istream& in, ostream& out, const int pad)
{
  cout << "Please enter your first name: ";
  string name;
  in >> name;
  out << endl;

  const string greeting = "Hello, " + name + "!";
  const int rows = pad * 2 + 3;
  const string::size_type cols = greeting.size() + pad * 2 + 2;

  for (int r = 0; r != rows; r++)   // r = rows written
  {    
    string::size_type c = 0;        // columns written
    while (c != cols) 
    {
      if (r == rows / 2 && c == pad + 1)
      {
        out << greeting;
        c += greeting.length();
      }
      else if (r != 0 && r != rows - 1 && r != rows / 2 && c != 0 && c != cols - 1) 
      {
        out << string(cols - 2, ' ');
        c += cols - 2;
      }
      else
      {
        if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
          out << "*";
        else
          out << " ";
        c++;
      }
    }
    out << std::endl;
  }

  return 0;
}

int ex2_4()
{
  int padding;
  cout << "Please enter frame padding: ";
  cin >> padding;
  cout << endl;

  return FrameDynamicAlt(cin, cout, padding);
}