// Chapter01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

void TestOutputBuffer(std::ostream& outStream) {
  outStream << "Test the buffer";
  outStream << "Flush at end of line?" << std::endl;
}

void AskName(std::ostream& outStream, std::istream& inStream) {
  outStream << "Please enter your first name: ";
  std::string name;
  inStream >> name;
  outStream << "Hello, " + name + "!" << std::endl;
}

void AskNameFramed(std::ostream& outStream, std::istream& inStream) {
  
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

void TestScope1() {
  { const std::string s = "a string";
  std::cout << s << std::endl; }

  { const std::string s = "another string";
  std::cout << s << std::endl; }
}

void TestScope2() {
  { const std::string s = "a string";
  std::cout << s << std::endl;

    { const std::string s = "another string";
    std::cout << s << std::endl; }
    ;
  }
}

void TestScope3() {
  { std::string s = "a string";
  { std::string x = s + ", really";
  std::cout << s << std::endl;
  std::cout << x << std::endl;
  }
  }
}

void AskNames(std::ostream& outStream, std::istream& inStream) {
  std::cout << "What is your name? ";
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name
    << std::endl << "And what is yours? ";
  std::cin >> name;
  std::cout << "Hello, " << name
    << "; nice to meet you too!" << std::endl;
}

int main()
{
  AskNames(std::cout, std::cin);
  return 0;
}

