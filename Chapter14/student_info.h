#ifndef GUARD_student_info_H
#define GUARD_student_info_H

#define ANNOTATE 0

#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <algorithm>

#include "handle.h"

class Core {

  friend class Student_info;
  friend class Audit;

public:

  // default constructor for Core
  Core() : midterm(0), final(0) { 
#if ANNOTATE == 1
    std::cerr << "Core::Core()" << std::endl;
#endif
  }

  // build a Core from an istream
  Core(std::istream& is) { 
#if ANNOTATE == 1
    std::cerr << "Core::Core(istream&)" << std::endl;
#endif
    read(is);
  }

  virtual ~Core() { }

  std::string name() const;
  virtual double grade() const;
  std::string letter_grade() const;
  virtual std::istream& read(std::istream&);

  bool valid() const { return !homework.empty(); }
  virtual bool requirements_met() const
  {
    return std::find(homework.begin(), homework.end(), 0.0) == homework.end();
  }

  virtual Core* clone() const { return new Core(*this); }

protected:
  std::istream& read_common(std::istream&);
  double midterm, final;
  std::vector<double> homework;

private:
  std::string n;

};



class Grad : public Core {

public:

  // both constructors implicitly use Core::Core() to initialize the base part
  Grad() : thesis(0) { 
#if ANNOTATE == 1
    std::cerr << "Grad::Grad()" << std::endl;
#endif
  }
  Grad(std::istream& is) { 
#if ANNOTATE == 1
    std::cerr << "Grad::Grad(istream&)" << std::endl;
#endif
    read(is); 
  }

  double grade() const;
  std::istream& read(std::istream&);

  bool requirements_met() const
  {
    return Core::requirements_met() && thesis != 0.0;
  }

protected:

  Grad* clone() const { return new Grad(*this); }

private:
  double thesis;
};



class Student_info {

public:

  Student_info() { }
  Student_info(std::istream& is) { read(is); }
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

  static bool compare(const Student_info& s1,
    const Student_info& s2) {
    return s1.name() < s2.name();
  }

private:

  Handle<Core> cp;

};


bool compare(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);
std::istream& read_hw(std::istream&, std::vector<double>&);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(double midterm, double final, double homework);
double median(std::vector<double>);


#endif // !GUARD_student_info_H