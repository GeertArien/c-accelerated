#include "stdafx.h"

#include <iostream>
#include <list>
#include <sstream>

#include "student_info.h"
#include "grade.h"

using std::cout;          using std::cin;
using std::endl;          using std::list;
using std::istream;       using std::vector;
using std::stringstream;

bool compare(const Student_info& x, const Student_info& y) 
{
  return x.name < y.name;
}

istream& read(istream& is, Student_info& s) 
{
  double midterm, final;
  vector<double> homework;

  is >> s.name >> midterm >> final;
  read_hw(is, homework);

  if (is)
    s.grade = grade(midterm, final, homework);

  return is;
}

istream& read(istream& is, vector<Student_info>& v) 
{
  const int BUFFSIZE = 80;

  stringstream ss;
  char buff[BUFFSIZE];

  while (is.getline(buff, BUFFSIZE))
  {
    ss << buff;
    Student_info student;
    read(ss, student);
    v.push_back(student);
  }

  return is;
}

istream& read(istream& is, list<Student_info>& l) 
{
  const int BUFFSIZE = 80;

  stringstream ss;
  char buff[BUFFSIZE];

  while (is.getline(buff, BUFFSIZE)) 
  {
    ss << buff;
    Student_info student;
    read(ss, student);
    l.push_back(student);
  }

  return is;
}

istream& read_hw(istream& is, vector<double>& hw) 
{

  if (is) 
  {
    is.clear();

    double x;
    while (is >> x)
      hw.push_back(x);

    is.clear();
  }

  return is;
}

bool fgrade(const Student_info& s) 
{
  return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
  vector<Student_info> fail;
  vector<Student_info>::iterator iter = students.begin();

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

list<Student_info> extract_fails(list<Student_info>& students)
{
  list<Student_info> fail;
  list<Student_info>::iterator iter = students.begin();

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