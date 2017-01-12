// Chapter06.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <ios>
#include <vector>
#include <fstream>

#include "student_info.h"
#include "words.h"

using std::vector;    using std::cin;
using std::cout;      using std::endl;
using std::string;    using std::ifstream;

void test_copy() {
  vector<int> u(10, 100);

  //vector<int> v(u);           // Direct initialization as copy of vector u
  //vector<int> v = u;          // Implicit initialization as copy of vector u

  vector<int> v(u.size());      // first initialized with default value
  copy(u.begin(), u.end(), v.begin());
}

void test_find_urls() {
  string s = "http:// http://test.com toast.com ftp://fttpt :// ://google.be f://l";
  vector<string> v = find_urls(s);
  vector<string>::iterator iter = v.begin();

  while (iter != v.end())
    cout << *iter++ << endl;
}

void test_frame() {
  vector<string> v1 = { "one test", "two test", "aye caramba" };
  vector<string> v2 = { "one direction", "mama mia", "mamo testo", "lake district mall" };

  vector<string> horz = hcat(frame(v1), frame(v2));
  vector<string>::iterator iter = horz.begin();

  while (iter != horz.end())
    cout << *iter++ << endl;
}

int test_grading_schemes(string file) {
  vector<Student_info> all, did, didnt;
  Student_info student;

  ifstream infile;

  infile.open(file);
  read(infile, all);

  vector<Student_info>::const_iterator iter = all.begin();

  while (iter != all.end()) {
    if (did_all_hw(*iter))
      did.push_back(*iter++);
    else
      didnt.push_back(*iter++);
  }

  if (did.empty()) {
    cout << "No student did all the homework!" << endl;
    return 1;
  }

  if (didnt.empty()) {
    cout << "Every student did all the homework!" << endl;
    return 1;
  }

  write_analysis(cout, "median", grade_aux, did, didnt);
  write_analysis(cout, "average", average_grade, did, didnt);
  write_analysis(cout, "median of homework turned in", optimistic_median, did, didnt);

  return 0;
}

int main()
{
  test_grading_schemes("students10.txt");
  return 0;
}

