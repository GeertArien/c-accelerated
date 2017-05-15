/**
Accelerated C++, Exercise 12-3, 12_3.cpp

Define the relational operators for Str. In doing so, you will want to know that
the <cstring> header defines a function called strcmp, which compares two character
pointers. The function returns a negative integer if the null-terminated character array
denoted by the first pointer is less than the second, zero if the two strings are equal, or
a positive value if the first string is greater than the second.
*/

#include "stdafx.h"
#include "12_3.h"

#include <iostream>
using std::cout;
using std::endl;

#include "str_c.h"

int ex12_3()
{
  Str_c short_str = "audio";
  Str_c default_str1 = "Aviation";
  Str_c default_str2 = "aviation";
  Str_c long_str = "aviation industry";

  cout << short_str << " is smaller than " << default_str2 << " ? " << (short_str < default_str2) << endl;
  cout << long_str << " is smaller or equal to " << default_str2 << " ? " << (long_str <= default_str2) << endl;
  cout << short_str << " is bigger than " << long_str << " ? " << (short_str > long_str) << endl;
  cout << long_str << " is bigger or equal to " << long_str << " ? " << (long_str >= long_str) << endl;

  return 0;
}