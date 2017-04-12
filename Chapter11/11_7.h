#ifndef GUARD_11_7_H
#define GUARD_11_7_H

#include "student_info.h"
#include "vec.h"

class Grader
{

private:
  Vec<Student_info> students;
  std::ostream& Grader::generate_report(std::ostream&,
    Vec<Student_info>::const_iterator,
    Vec<Student_info>::const_iterator) const;

public:
  Grader() {};
  Grader(std::istream&);

  std::ostream& generate_report(std::ostream&);
};


int ex11_7();

#endif // !GUARD_11_7_H