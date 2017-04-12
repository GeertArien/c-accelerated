/**
Accelerated C++, Exercise 11-5, 11_5.cpp

Instrument the Student_info class to count how often objects are created,
copied, assigned, and destroyed. Use this instrumented class to execute the student
record programs from Chapter 6. Using the instrumented Student_info class will let
you see how many copies the library algorithms are doing. Comparing the number of
copies will let you estimate what proportion of the cost differences we saw are
accounted for by the use of each library class. Do this instrumentation and analysis.
*/

#include "stdafx.h"
#include "11_5.h"

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <chrono>
using std::chrono::steady_clock;

#include "student_info.h"

vector<Student_info> test_student_info(string file, vector<Student_info>& s)
{
  Student_info::reset_class_info();
  ifstream infile;
  vector<Student_info> failed;

  infile.open(file);
  steady_clock::time_point begin = std::chrono::steady_clock::now();
  read(infile, s);
  steady_clock::time_point end = std::chrono::steady_clock::now();
  cout << "Microseconds to read " << file << " into vector = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;
  Student_info::print_class_info(cout);
  infile.close();
  infile.clear();
  Student_info::reset_class_info();

  begin = std::chrono::steady_clock::now();
  failed = extract_fails(s);
  end = std::chrono::steady_clock::now();
  cout << "Microseconds to extract failed from " << file << " student vector = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;
  Student_info::print_class_info(cout);

  return failed;
}

list<Student_info> test_student_info(string file, list<Student_info>& s)
{
  Student_info::reset_class_info();
  ifstream infile;
  list<Student_info> failed;

  infile.open(file);
  steady_clock::time_point begin = std::chrono::steady_clock::now();
  read(infile, s);
  steady_clock::time_point end = std::chrono::steady_clock::now();
  cout << "Microseconds to read " << file << " into list = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;
  Student_info::print_class_info(cout);
  infile.close();
  infile.clear();
  Student_info::reset_class_info();

  begin = std::chrono::steady_clock::now();
  failed = extract_fails(s);
  end = std::chrono::steady_clock::now();
  cout << "Microseconds to extract failed from " << file << " student list = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;
  Student_info::print_class_info(cout);

  return failed;
}

void test_student_info(string amount)
{
  string file = "students" + amount + ".txt";
  ifstream infile;

  vector<Student_info> students_v;
  list<Student_info> students_l;

  test_student_info(file, students_v);
  test_student_info(file, students_l);
}

int ex11_5()
{
  test_student_info("1000");

  return 0;
}
