#ifndef GUARD_student_info_H
#define GUARD_student_info_H

#include <string>
#include <vector>
#include <iostream>

class Student_info {

private:
  std::string n;
  double midterm, final;
  std::vector<double> homework;

public:
  Student_info();
  Student_info(std::istream&);

  std::istream& read(std::istream&);
  double grade() const;
  std::string name() const { return n; }
  bool valid() const { return !homework.empty(); }
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(double midterm, double final, double homework);
double median(std::vector<double>);

#endif // !GUARD_student_info_H