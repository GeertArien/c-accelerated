#ifndef GUARD_13_6_H
#define GUARD_13_6_H

#include "student_info.h"

class Credit : public Core {

public:

  Credit() {}
  Credit(std::istream& is) : Core(is) {}

  double grade() const;
  bool passed() const { return grade() >= 60; }

  bool valid() const { return true; }
  bool requirements_met() const { return true; }

protected:

  Credit* clone() const { return new Credit(*this); }
};

int ex13_6();

#endif // !GUARD_13_6_H