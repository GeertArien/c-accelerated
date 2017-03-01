/**
Accelerated C++, Exercise 1-0, 1_0.cpp

Compile, execute, and test the programs in this chapter.
*/

#include "stdafx.h"
#include "1_0.h"

#include <iostream>
#include <string>

void AskName(std::ostream& outStream, std::istream& inStream) 
{
  outStream << "Please enter your first name: ";
  std::string name;
  inStream >> name;
  outStream << "Hello, " + name + "!" << std::endl;
}

void AskNameFramed(std::ostream& outStream, std::istream& inStream) 
{
  outStream << "Please enter your first name: ";
  std::string name;
  inStream >> name;

  const std::string greeting = "Hello, " + name + "!";
  const std::string spaces(greeting.size(), ' ');
  const std::string line3 = '*' + greeting + '*';
  const std::string line2 = '*' + spaces + '*';
  const std::string line1(line2.size(), '*');

  outStream << line1 << std::endl << line2 << std::endl << line3
    << std::endl << line2 << std::endl << line1 << std::endl;
}

int ex1_0()
{
  AskName(std::cout, std::cin);
  AskNameFramed(std::cout, std::cin);

  return 0;
}