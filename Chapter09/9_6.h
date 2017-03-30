#ifndef GUARD_9_6_H
#define GUARD_9_6_H

#include <vector>
#include <iostream>

#include "9_5.h"

class Grader_ext
{
private:
  std::vector<Student_info_p> students;
  std::ostream& Grader_ext::generate_report(std::ostream&,
    std::vector<Student_info_p>::const_iterator, 
    std::vector<Student_info_p>::const_iterator) const;

public:
  Grader_ext() {};
  Grader_ext(std::istream&);

  std::ostream& generate_report(std::ostream&);
};

int ex9_6();

#endif // !GUARD_9_6_H