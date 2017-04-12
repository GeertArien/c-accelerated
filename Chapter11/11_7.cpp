/**
Accelerated C++, Exercise 11-7, 11_7.cpp

Once you've added erase and clear to Vec, you can use that class instead of
vector in most of the earlier programs in this book. Rewrite the Student_info
programs from Chapter 9 and the programs that work with character pictures from
Chapter 5 to use Vecs instead of vectors.
*/

#include "stdafx.h"
#include "11_7.h"

#include <string>
using std::string;

#include <algorithm>
using std::max;
using std::sort;
using std::stable_partition;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::streamsize;
using std::ostream;
using std::istream;

#include <iomanip>
using std::setprecision;

#include <exception>
using std::domain_error;

#include "vec.h"
#include "student_info.h"

string::size_type width(const Vec<string>& v)
{
  string::size_type maxlen = 0;

  for (Vec<string>::size_type i = 0; i != v.size(); ++i)
    maxlen = max(maxlen, v[i].size());

  return maxlen;
}

Vec<string> frame(const Vec<string>& v)
{
  Vec<string> ret;
  string::size_type maxlen = width(v);
  string border(maxlen + 4, '*');

  ret.push_back(border);

  for (Vec<string>::size_type i = 0; i != v.size(); ++i)
  {
    ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
  }

  ret.push_back(border);

  return ret;
}

Vec<string> vcat(const Vec<string>& top, const Vec<string>& bottom)
{
  Vec<string> ret = top;

  for (Vec<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
    ret.push_back(*it);

  return ret;
}

Vec<string> hcat(const Vec<string>& left, const Vec<string>& right)
{
  Vec<string> ret;

  string::size_type width1 = width(left) + 1;

  Vec<string>::size_type i = 0, j = 0;

  while (i != left.size() || j != right.size())
  {
    string s;

    if (i != left.size())
      s = left[i++];

    s += string(width1 - s.size(), ' ');

    if (j != right.size())
      s += right[j++];

    ret.push_back(s);
  }

  return ret;
}

int test_frame()
{
  Vec<string> v1;
  v1.push_back("one test");
  v1.push_back("two test");
  v1.push_back("aye caramba");

  Vec<string> v2;
  v2.push_back("one direction");
  v2.push_back("mama mia");
  v2.push_back("mamo testo");
  v2.push_back("lake district mall");

  Vec<string> vert = vcat(frame(v1), frame(v2));

  Vec<string>::const_iterator iter = vert.begin();

  while (iter != vert.end())
    cout << *iter++ << endl;

  Vec<string> horz = hcat(frame(v1), frame(v2));

  iter = horz.begin();

  while (iter != horz.end())
    cout << *iter++ << endl;

  return 0;
}

bool passing(Student_info p)
{
  return p.grade() >= 60;
}

Grader::Grader(istream& is)
{
  Student_info record;

  while (record.read(is)) {
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare);
}

ostream& Grader::generate_report(ostream& os)
{
  Vec<Student_info> students_copy(students);
  const Vec<Student_info>::iterator iter = stable_partition(students_copy.begin(), students_copy.end(), passing);

  generate_report(os, students_copy.begin(), iter);
  generate_report(os, iter, students_copy.end());

  return os;
}

ostream& Grader::generate_report(ostream& os,
  Vec<Student_info>::const_iterator begin, Vec<Student_info>::const_iterator end) const
{
  Vec<Student_info>::const_iterator iter = begin;
  string::size_type maxlen = 0;
  while (iter != end)
    maxlen = max(maxlen, iter++->name().size());

  while (begin != end)
  {
    os << begin->name()
      << string(maxlen + 1 - begin->name().size(), ' ')
      << (passing(*begin) ? 'P' : 'F') << endl;
    begin++;
  }

  return os;
}

int ex11_7()
{
  test_frame();

  Grader g = Grader(cin);
  g.generate_report(cout);
  
  return 0;
}