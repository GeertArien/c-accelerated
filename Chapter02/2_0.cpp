/**
Accelerated C++, Exercise 2-0, 2_0.cpp

Compile and run the program presented in this chapter.
*/

#include "stdafx.h"
#include "2_0.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


int ex2_0()
{
  cout << "Please enter your first name: ";

  string name;
  cin >> name;

  const string greeting = "Hello, " + name + "!";
  const int pad = 1;
  const int rows = pad * 2 + 3;
  const string::size_type cols = greeting.size() + pad * 2 + 2;

  cout << endl;

  for (int r = 0; r != rows; ++r)
  {
    string::size_type c = 0;

    while (c != cols)
    {

      if (r == pad + 1 && c == pad + 1)
      {
        cout << greeting;
        c += greeting.size();
      }
      else
      {
        if (r == 0 || r == rows - 1 ||
          c == 0 || c == cols - 1)
          cout << "*";
        else
          cout << " ";
        ++c;
      }
    }

    cout << endl;
  }

  return 0;
}
