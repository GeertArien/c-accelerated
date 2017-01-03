#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <string>
#include <vector>
#include <iostream>
#include <list>

struct Student_info {
  std::string name;
  double grade;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
bool fgrade(const Student_info&);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);
std::list<Student_info> extract_fails(std::list<Student_info>&);

#endif // !GUARD_student_info

