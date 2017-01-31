/**
Accelerated C++, Exercise 5-2, 5_2.cpp

Write the complete new version of the student-grading program, which extracts
records for failing students, using vectors. Write another that uses lists. Measure
the performance difference on input files of ten lines, 1,000 lines, and 10,000 lines.
*/

#include "stdafx.h"

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
  ifstream infile;
  vector<Student_info> failed;

  infile.open(file);
  steady_clock::time_point begin = std::chrono::steady_clock::now();
  read(infile, s);
  steady_clock::time_point end = std::chrono::steady_clock::now();
  cout << "Microseconds to read " << file << " into vector = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;
  infile.close();
  infile.clear();

  begin = std::chrono::steady_clock::now();
  failed = extract_fails(s);
  end = std::chrono::steady_clock::now();
  cout << "Microseconds to extract failed from " << file << " student vector = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

  return failed;
}

list<Student_info> test_student_info(string file, list<Student_info>& s)
{
  ifstream infile;
  list<Student_info> failed;

  infile.open(file);
  steady_clock::time_point begin = std::chrono::steady_clock::now();
  read(infile, s);
  steady_clock::time_point end = std::chrono::steady_clock::now();
  cout << "Microseconds to read " << file << " into list = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;
  infile.close();
  infile.clear();

  begin = std::chrono::steady_clock::now();
  failed = extract_fails(s);
  end = std::chrono::steady_clock::now();
  cout << "Microseconds to extract failed from " << file << " student list = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

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

int ex5_2() 
{
  test_student_info("10");
  test_student_info("100");
  test_student_info("1000");
  test_student_info("10000");

  return 0;
}
