// Chapter02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

void WelcomeFrameDynamic(std::istream& in, std::ostream& out, const int horz_pad, const int vert_pad) {
  out << "Please enter your name: ";
  string name;
  in >> name;
  out << endl;

  const string welcome = "Hello, " + name + "!";
  const int rows = vert_pad * 2 + 3;
  const string::size_type columns = 2 + horz_pad * 2 + welcome.length();

  for (int r = 0; r != rows; r++) {     // r = rows written
    string::size_type c = 0;      // columns written
    while (c != columns) {
      if (r == rows / 2 && c == horz_pad + 1) {
        out << welcome;
        c += welcome.length();
      }
      else if (r != 0 && r != rows - 1 && r != rows /2 && c != 0 && c != columns - 1) {
        out << string(columns - 2, ' ');
        c += columns - 2;
      }
      else {
        if (r == 0 || r == rows - 1 || c == 0 || c == columns - 1)
          out << "*";
        else
          out << " ";
        c++;
      }
    }
    out << std::endl;
  }
}

void WelcomeFrameDynamic(std::istream& in, std::ostream& out, const int padding) {
  WelcomeFrameDynamic(in, out, padding, padding);
}

void WelcomeFrameDynamic(std::istream& in, std::ostream& out) {
  int padding;
  out << "Please enter frame padding: ";
  in >> padding;
  out << endl;

  WelcomeFrameDynamic(in, out, padding);
}

void DrawGeo(std::ostream& out) {

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == 0 || j == 10 - 1 || i == 0 || i == 7 - 1)
        out << "*";
      else
        out << " ";
    }
    out << endl;
  }

  out << endl;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == 0 || j == 10 - 1 || i == 0 || i == 10 - 1)
        out << "*";
      else
        out << " ";
    }
    out << endl;
  }

  out << endl;

  const int height = 7;
  const int width = height * 2 - 1;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if ((i == height - 1) || (i == 0 && j == height - 1))
        out << "*";
      else if (i > 0 && (j == height - 1 + i || j == height - 1 - i))
        out << "*";
      else
        out << " ";
    }
    out << endl;
  }
}

void CountDown(std::ostream& out, int start, const int stop) {
  while (start >= stop) {
    out << start-- << endl;
  }
}

int ProductRang(const int startIncl, const int stopExcl) {
  int product = startIncl;

  for (int i = startIncl + 1; i < stopExcl; i++)
    product *= i;

  return product;
}

void Compare(std::istream& in, std::ostream& out) {
  int num1, num2;

  out << "Enter the first number: ";
  in >> num1;
  out << "Enter the second number: ";
  in >> num2;
  if (num1 == num2) {
    out << "Both numbers are equal" << endl;
  }
  else if (num1 > num2) {
    out << num1 << " is bigger than " << num2 << endl;
  }
  else {
    out << num2 << " is bigger than " << num1 << endl;
  }
}

int main()
{
  Compare(cin, cout);
  return 0;
}

