#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <string>
#include <vector>
#include <iostream>

struct Student_info {
  std::string name;
  std::vector<double> homework;
  double midterm;
  double final;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, std::vector<Student_info>&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
bool did_all_hw(const Student_info&);
double grade_aux(const Student_info&);
double optimistic_median(const Student_info&);
double average_grade(const Student_info&);
double median_analysis(const std::vector<Student_info>&);
double optimistic_median_analysis(const std::vector<Student_info>&);
double average_analysis(const std::vector<Student_info>&);
void write_analysis(std::ostream&, const std::string&, double analysis(const std::vector<Student_info>&),
  const std::vector<Student_info>&, const std::vector<Student_info>&);
void write_analysis(std::ostream&, const std::string&, double method(const Student_info&),
  const std::vector<Student_info>&, const std::vector<Student_info>&);
bool fgrade(const Student_info&);
bool pgrade(const Student_info&);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);
double analysis(const std::vector<Student_info>&, double grade(const Student_info&));

#endif // !GUARD_student_info

