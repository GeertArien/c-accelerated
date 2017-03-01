/**
Accelerated C++, Exercise 1-1, 1_1.cpp

Are the following definitions valid? Why or why not?

    const std::string hello = "Hello";
    const std::string message = hello + ", world" + "!";
*/

#include "stdafx.h"
#include "1_1.h"

#include <string>

int ex1_1()
{
  const std::string hello = "Hello";
  const std::string message = hello + ", world" + "!";

  return 0;
}