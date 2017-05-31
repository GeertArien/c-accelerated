/**
Accelerated C++, Exercise 16-1, 16_1.cpp

Write a self-reproducing program. Such a program is one 
that does no input, and that, when run, writes a copy of 
its own source text on the standard output stream.
*/

#include "stdafx.h"
#include "16_1.h"

#include <vector>
#include <string>
#include <iostream>

int ex16_1()
{
  std::vector<std::string> v = {
    "/**",
    "Accelerated C++, Exercise 16-1, 16_1.cpp",
    "",
    "Write a self-reproducing program. Such a program is one",
    "that does no input, and that, when run, writes a copy of",
    "its own source text on the standard output stream.",
    "*/",
    "",
    {35,105,110,99,108,117,100,101,32,34,115,116,100,97,102,120,46,104,34},
    {35,105,110,99,108,117,100,101,32,34,49,54,95,49,46,104,34},
    "",
    "#include <vector>",
    "#include <string>",
    "#include <iostream>",
    "",
    "int ex16_1()",
    "{",
    "std::vector<std::string> v = { ",
    "};",
    "",
    "for (size_t i = 0; i < 18; i++)",
    "std::cout << v[i] << std::endl;",
    "",
    "for (size_t i = 0; i < v.size(); i++)",
    "if (i == 8 || i == 9)",
    "{",
    "std::cout << (char)9 << (char)123 << (int)v[i][0];",
    "for (size_t j = 1; j < v[i].size(); j++)",
    "std::cout << (char)44 << (int)v[i][j];",
    "std::cout << (char)125 << (char)44 << std::endl;",
    "}",
    "else",
    "std::cout << (char)9 << (char)34 << v[i]",
    "<< (char)34 << (char)44 << std::endl;",
    "",
    "for (size_t i = 18; i < v.size(); i++)",
    "std::cout << v[i] << std::endl;",
    "",
    "return 0;",
    "}"
  };

  for (size_t i = 0; i < 18; i++)
    std::cout << v[i] << std::endl;

  for (size_t i = 0; i < v.size(); i++)
    if (i == 8 || i == 9)
    {
      std::cout << (char)9 << (char)123 << (int)v[i][0];
      for (size_t j = 1; j < v[i].size(); j++)
        std::cout << (char)44 << (int)v[i][j];
      std::cout << (char)125 << (char)44 << std::endl;
    }
    else
      std::cout << (char)9 << (char)34 << v[i] 
      << (char)34 << (char)44 << std::endl;

  for (size_t i = 18; i < v.size(); i++)
    std::cout << v[i] << std::endl;

  return 0;
}