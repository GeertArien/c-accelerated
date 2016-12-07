 A small C++ program

#include "stdafx.h"
#include <iostream>

void WriteHelloWorld(std::ostream& outstream) {
  outstream << "Hello, World!" << std::endl;
}

void WriteHelloWorldProgram(std::ostream& outstream) {
  outstream << "// A small C++ program" << std::endl << std::endl
    << "#include <iostream>" << std::endl << std::endl
    << "int main()" << std::endl
    << "{" << std::endl
    << "\tstd::cout << \"Hello, World!\" << std::endl;" << std::endl
    << "\treturn 0;" << std::endl
    << "}" << std::endl << std::endl;
}

void WriteQuoteBackslash(std::ostream& outstream) {
  outstream << "This (\") is a quote, and this (\\) is a backslash." << std::endl;
}

void TestTabs(std::ostream& outstream) {
  outstream << "this is a tab \t test." << std::endl
            << "\t tab" << std::endl
            << "\t tab \t test." << std::endl;
}

int
SplitHelloWorld
(
)
{
  std
    ::
    cout
    <<
    "Hello, world!"
    <<
    std
    ::
    endl
    ;
  return
    0
    ;
}

int main()
{
  SplitHelloWorld();
  WriteHelloWorldProgram(std::cout);
  return 0;
}