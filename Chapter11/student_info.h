#ifndef GUARD_student_info_H
#define GUARD_student_info_H

#include <string>
#include <vector>
#include <list>
#include <iostream>

class Student_info {

private:
  std::string n;
  double midterm, final;
  std::vector<double> homework;

  static int default_constructor_calls;
  static int stream_constructor_calls;
  static int copy_constructor_calls;
  static int assignment_calls;
  static int destructor_calls;

public:
  Student_info();
  Student_info(std::istream&);
  Student_info(const Student_info&);

  Student_info& operator=(const Student_info&);
  ~Student_info();

  std::istream& read(std::istream&);
  double grade() const;
  std::string name() const { return n; }
  bool valid() const { return !homework.empty(); }

  static void reset_class_info();
  static std::ostream& print_class_info(std::ostream&);
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(double midterm, double final, double homework);
double median(std::vector<double>);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);
std::list<Student_info> extract_fails(std::list<Student_info>&);
std::istream& read(std::istream&, std::vector<Student_info>&);
std::istream& read(std::istream&, std::list<Student_info>&);

#endif // !GUARD_student_info_H