#ifndef GUARD_pic_H
#define GUARD_pic_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "ptr.h"


// Forward declaration
class Picture;



// private classes for use in the implementation only

class Pic_base {

  // this class is an abstract base class

  friend std::ostream& operator<<(std::ostream&, const Picture&);
  friend class Frame_Pic;
  friend class HCat_Pic;
  friend class VCat_Pic;
  friend class String_Pic;
  friend class Picture;

  // no public interface

  typedef std::vector<std::string>::size_type ht_sz;
  typedef std::string::size_type wd_sz;

  virtual wd_sz width() const = 0;
  virtual ht_sz height() const = 0;
  virtual void display(std::ostream&, ht_sz, bool) const = 0;
  virtual void reframe(const char, const char, const char) = 0;
  
protected:
  
  static void pad(std::ostream& os, wd_sz beg, wd_sz end);

};



class Frame_Pic : public Pic_base {

  friend Picture frame(const Picture&);
  friend Picture frame(const Picture&, const char, const char, const char);

  // no public interface
  Ptr<Pic_base> p;
  char corner;
  char top_bot;
  char side;

  Frame_Pic(const Ptr<Pic_base>& pic, const char corner = '+',
            const char top_bottom = '-', const char side = '|') 
    : p(pic), corner(corner), top_bot(top_bottom), side(side) { }

  wd_sz width() const { return p->width() + 4; }
  ht_sz height() const { return p->height() + 4; }

  void display(std::ostream&, ht_sz, bool) const;
  void reframe(const char, const char, const char);
};



class VCat_Pic : public Pic_base {

  friend Picture vcat(const Picture&, const Picture&);

  Ptr<Pic_base> top, bottom;

  VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b) :
    top(t), bottom(b) { }

  wd_sz width() const
  {
    return std::max(top->width(), bottom->width());
  }

  ht_sz height() const
  {
    return top->height() + bottom->height();
  }

  void display(std::ostream&, ht_sz, bool) const;
  void reframe(const char, const char, const char);
};



class HCat_Pic : public Pic_base {

  friend Picture hcat(const Picture&, const Picture&);

  Ptr<Pic_base> left, right;

  HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r) :
    left(l), right(r) { }

  wd_sz width() const { return left->width() + right->width(); }

  ht_sz height() const
  {
    return std::max(left->height(), right->height());
  }

  void display(std::ostream&, ht_sz, bool) const;
  void reframe(const char, const char, const char);
};



class String_Pic : public Pic_base {

  friend class Picture;

  std::vector<std::string> data;
  String_Pic(const std::vector<std::string>& v) : data(v) { }

  wd_sz width() const;
  ht_sz height() const { return data.size(); };
  void display(std::ostream&, ht_sz, bool) const;
  void reframe(const char, const char, const char) { }
};



// public interface class and operations
class Picture {

  friend std::ostream& operator<<(std::ostream&, const Picture&);
  friend Picture frame(const Picture&);
  friend Picture frame(const Picture&, const char, const char, const char);
  friend Picture hcat(const Picture&, const Picture&);
  friend Picture vcat(const Picture&, const Picture&);

public:

  Picture(const std::vector<std::string>& =
    std::vector<std::string>());

  void reframe(const char corner, const char top_bottom, const char side);

private:

  Ptr<Pic_base> p;

  Picture(Pic_base* ptr) : p(ptr) { }

};



Picture frame(const Picture&);
Picture frame(const Picture&, const char, const char, const char);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);

#endif // !GUARD_pic_H