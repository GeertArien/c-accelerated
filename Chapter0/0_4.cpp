/**
Accelerated C++, Exercise 0-4, 0_4.cpp

Write a program that, when run, writes the Hello, world! program as its
output.
*/

#include "stdafx.h"
#include "0_4.h"

#include <iostream>

void ex0_4() 
{
  std::cout << "// A small C++ program" << std::endl
    << "#include <iostream>" << std::endl << std::endl
    << "int main()" << std::endl
    << "{" << std::endl
    << "\tstd::cout << \"Hello, World!\" << std::endl;" << std::endl
    << "\treturn 0;" << std::endl
    << "}" << std::endl << std::endl;
}