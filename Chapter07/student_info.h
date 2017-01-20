#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <string>
#include <vector>
#include <iostream>

struct Student_info {
  std::string name;
  double grade;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif // !GUARD_student_info

