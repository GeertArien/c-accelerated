#ifndef GUARD_13_7_H
#define GUARD_13_7_H

#include <iostream>

#include "student_info.h"

class Audit : public Core {

public:

  Audit() {}
  Audit(std::istream& is) { read(is); }

  std::istream& read(std::istream&);

  double grade() const { return 0.0; };

  bool valid() const { return true; }
  bool requirements_met() const { return true; }

protected:

  Audit* clone() const { return new Audit(*this); }
};

int ex13_7();

#endif // !GUARD_13_7_H