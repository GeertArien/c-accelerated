/**
Accelerated C++, Exercise 2-2, 2_2.cpp

Change the framing program so that it uses a different amount of space to
separate the sides from the greeting than it uses to separate the top and bottom
borders from the greeting.
*/

#include "stdafx.h"
#include "2_2.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;


int ex2_2()
{
  cout << "Please enter your first name: ";

  string name;
  cin >> name;

  const string greeting = "Hello, " + name + "!";

  const int vert_pad = 1;
  const int horz_pad = 3;

  const int rows = vert_pad * 2 + 3;
  const string::size_type cols = greeting.size() + horz_pad * 2 + 2;

  cout << endl;

  for (int r = 0; r != rows; ++r)
  {
    string::size_type c = 0;

    while (c != cols)
    {

      if (r == vert_pad + 1 && c == horz_pad + 1)
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