/**
Accelerated C++, Exercise 5-4, 5_4.cpp

Look again at the driver functions you wrote in the previous exercise. Note that it is
possible to write a driver that differs only in the declaration of the type for the data
structure that holds the input file. If your vector and list test drivers differ in any
other way, rewrite them so that they differ only in this declaration.
*/

#include "stdafx.h"

#include "5_4.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <chrono>
using std::chrono::steady_clock;

#include "student_info.h"

//typedef list<Student_info> students_t;
typedef vector<Student_info> students_t;


students_t extract_fails_driver(students_t& students) 
{
  students_t fail;
  students_t::iterator iter = students.begin();

  while (iter != students.end())
  {
    if (fgrade(*iter)) 
    {
      fail.push_back(*iter);
      iter = students.erase(iter);
    }
    else
      ++iter;
  }
  return fail;
}

int ex5_4()
{
  string file = "students10.txt";
  ifstream infile;

  students_t students, failed;

  infile.open(file);
  read(infile, students);
  infile.close();
  infile.clear();

  steady_clock::time_point begin = std::chrono::steady_clock::now();
  failed = extract_fails_driver(students);
  steady_clock::time_point end = std::chrono::steady_clock::now();
  cout << "Microseconds to extract failed from " << file << " = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

  return 0;
}