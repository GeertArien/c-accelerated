#ifndef GUARD_9_5_H
#define GUARD_9_5_H

#include <vector>
#include <iostream>

class Student_info_p {
private:
  std::string n;
  double midterm, final;

public:
  Student_info_p();
  Student_info_p(std::istream&);

  std::istream& read(std::istream&);
  double grade() const { return (midterm + final) / 2; };
  std::string name() const { return n; }
  bool passing() const { return grade() >= 60; };
};

class Grader
{
private:
  std::vector<Student_info_p> students;

public:
  Grader() {};
  Grader(std::istream&);

  std::ostream& generate_report(std::ostream&) const;
};

bool compare_p(const Student_info_p&, const Student_info_p&);

int ex9_5();

#endif // !GUARD_9_5_H