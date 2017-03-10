#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <string>
#include <vector>
#include <iostream>

struct Student_info 
{
  std::string name;
  std::vector<double> homework;
  double midterm;
  double final;
};

double grade_aux(const Student_info&);
double average_grade(const Student_info&);
double optimistic_median(const Student_info& s);
std::istream& read(std::istream&, std::vector<Student_info>&);
std::vector<Student_info> extract(std::vector<Student_info>&, bool criteria(const Student_info&));
bool did_all_hw(const Student_info&);

#endif // !GUARD_student_info
