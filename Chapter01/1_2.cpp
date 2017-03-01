/**
Accelerated C++, Exercise 1-2, 1_2.cpp

Are the following definitions valid? Why or why not?

    const std::string exclam = "!";
    const std::string message = "Hello" + ", world" + exclam;
*/

#include "stdafx.h"
#include "1_2.h"

#include <string>

int ex1_2()
{
  const std::string exclam = "!";

  // Can't add two string literals, the + operator has left-to-right associativity
  // const std::string message = "Hello" + ", world" + exclam;
  const std::string message = "Hello" + (", world" + exclam);

  return 0;
}