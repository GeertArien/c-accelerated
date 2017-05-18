#ifndef GUARD_student_info_H
#define GUARD_student_info_H

#include <iostream>
#include <vector>
#include <exception>


class Core {

  friend class Student_info;

public:

  // default constructor for Core
  Core() : midterm(0), final(0) { }

  // build a Core from an istream
  Core(std::istream& is) { read(is); }

  virtual ~Core() { }

  std::string name() const;
  virtual double grade() const;
  virtual std::istream& read(std::istream&);

protected:
  virtual Core* clone() const { return new Core(*this); }
  std::istream& read_common(std::istream&);
  double midterm, final;
  std::vector<double> homework;

private:
  std::string n;

};


class Grad : public Core {

public:

  // both constructors implicitly use Core::Core() to initialize the base part
  Grad() : thesis(0) { }
  Grad(std::istream& is) { read(is); }

  double grade() const;
  std::istream& read(std::istream&);

protected:

  Grad* clone() const { return new Grad(*this); }

private:
  double thesis;
};


class Student_info {

public:

  // constructors and copy control
  Student_info() : cp(0) { }
  Student_info(std::istream& is) : cp(0) { read(is); }
  Student_info(const Student_info&);
  Student_info& operator=(const Student_info&);
  ~Student_info() { delete cp; }

  // operations
  std::istream& read(std::istream&);

  std::string name() const {
    if (cp) return cp->name();
    else throw std::runtime_error("uninitialized Student");
  }

  double grade() const {
    if (cp) return cp->grade();
    else throw std::runtime_error("uninitialized Student");
  }

  static bool compare(const Student_info& s1, const Student_info& s2) {
    return s1.name() < s2.name();
  }

private:

  Core *cp;

};


bool compare(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);
std::istream& read_hw(std::istream&, std::vector<double>&);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(double midterm, double final, double homework);
double median(std::vector<double>);


#endif // !GUARD_student_info_H