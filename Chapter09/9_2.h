#ifndef GUARD_9_2_H
#define GUARD_9_2_H

#include <string>
#include <iostream>

class Student_info_n {

private:
  std::string n;
  double g;

public:
  Student_info_n();
  Student_info_n(std::istream&);

  std::istream& read(std::istream&);
  double grade() const { return g; };
  std::string name() { return n; }
};

int ex9_2();

#endif // !GUARD_9_2_H