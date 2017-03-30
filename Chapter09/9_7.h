#ifndef GUARD_9_7_H
#define GUARD_9_7_H

#include <string>
#include <vector>

class Student_info_hw {

private:
  std::string n;
  double midterm, final;
  std::vector<double> homework;
  std::istream& read_hw(std::istream&);

public:
  Student_info_hw();
  Student_info_hw(std::istream&);

  std::istream& read(std::istream&);
  double grade() const;
  std::string name() const { return n; }
};

int ex9_7();

#endif // !GUARD_9_7_H