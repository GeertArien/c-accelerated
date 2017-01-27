#ifndef GUARD_6_6_H
#define GUARD_6_6_H

#include <iostream>
#include <string>
#include <vector>

#include "student_info.h"

int ex6_6();
void write_analysis(std::ostream&, const std::string&, double method(const Student_info&),
  const std::vector<Student_info>&, const std::vector<Student_info>&);

#endif // !GUARD_6_6_H