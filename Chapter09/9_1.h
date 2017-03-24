#ifndef GUARD_9_1_H
#define GUARD_9_1_H

#include <string>
#include <iostream>

class Student_info_alt {

private:
  std::string n;
  double g;

public:
  Student_info_alt();
  Student_info_alt(std::istream&);

  std::istream& read(std::istream&);
  double grade() const { return g; };
  std::string name() const { return n; }
};

int ex9_1();

#endif // !GUARD_9_1_H