#ifndef GUARD_student_info_p_H
#define GUARD_student_info_p_H

#include <iostream>
#include <exception>

#include "student_info.h"
#include "ptr.h"

class Student_info_p {

public:

  Student_info_p() { }
  Student_info_p(std::istream& is) { read(is); }
  // no copy, assign, or destructor: they're no longer needed

  std::istream& read(std::istream&);

  std::string name() const {
    if (cp)
      return cp->name();
    else throw std::runtime_error("uninitialized Student");
  }

  double grade() const {
    if (cp) return cp->grade();
    else throw std::runtime_error("uninitialized Student");
  }

  static bool compare(const Student_info_p& s1,
    const Student_info_p& s2) {
    return s1.name() < s2.name();
  }

private:

  Ptr<Core> cp;

};


#endif // !GUARD_student_info_p_H