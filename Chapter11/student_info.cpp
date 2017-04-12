#include "stdafx.h"
#include "student_info.h"

#include <iostream>
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <exception>
using std::domain_error;

#include <algorithm>
using std::sort;

#include <sstream>
using std::stringstream;

int Student_info::default_constructor_calls;
int Student_info::stream_constructor_calls;
int Student_info::copy_constructor_calls;
int Student_info::assignment_calls;
int Student_info::destructor_calls;

Student_info::Student_info() : midterm(0), final(0) 
{
  ++default_constructor_calls;
}

Student_info::Student_info(istream& is) 
{ 
  ++stream_constructor_calls;
  read(is); 
}

Student_info::Student_info(const Student_info& s)
{
  ++copy_constructor_calls;

  n = s.n;
  midterm = s.midterm;
  final = s.final;
  homework = s.homework;
}

Student_info& Student_info::operator=(const Student_info& s)
{
  ++assignment_calls;

  if (&s != this)
  {
    n = s.n;
    midterm = s.midterm;
    final = s.final;
    homework = s.homework;
  }

  return *this;
}

Student_info::~Student_info()
{
  ++destructor_calls;
}

istream& Student_info::read(istream& in)
{
  in >> n >> midterm >> final;
  read_hw(in, homework);
  return in;
}

double Student_info::grade() const
{
  return ::grade(midterm, final, homework);
}

void Student_info::reset_class_info()
{
  default_constructor_calls = 0;
  stream_constructor_calls = 0;
  copy_constructor_calls = 0;
  assignment_calls = 0;
  destructor_calls = 0;
}

ostream& Student_info::print_class_info(ostream& os)
{
  os << default_constructor_calls << '\t' << "default constructor calls" << endl;
  os << stream_constructor_calls << '\t' << "stream constructor calls" << endl;
  os << copy_constructor_calls << '\t' << "copy constructor calls" << endl;
  os << assignment_calls << '\t' << "assignment calls" << endl;
  os << destructor_calls << '\t' << "destructor calls" << endl;

  return os;
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

double grade(double midterm, double final, const std::vector<double>& hw)
{
  if (hw.size() == 0)
    throw domain_error("Student has done no homework");
  return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework)
{
  return 0.2 *midterm + 0.4 * final + 0.4 * homework;
}

bool compare(const Student_info& x, const Student_info& y)
{
  return x.name() < y.name();
}

double median(vector<double> vec)
{
  typedef vector<double>::size_type vec_sz;

  vec_sz size = vec.size();
  if (size == 0)
    throw domain_error("median of empty vector");

  sort(vec.begin(), vec.end());
  vec_sz mid = size / 2;

  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

istream& read(istream& is, vector<Student_info>& v)
{
  const int BUFFSIZE = 80;

  stringstream ss;
  char buff[BUFFSIZE];

  while (is.getline(buff, BUFFSIZE))
  {
    ss << buff;
    Student_info student(ss);
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
    Student_info student(ss);
    l.push_back(student);
  }

  return is;
}

bool fgrade(const Student_info& s)
{
  return s.grade() < 60;
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