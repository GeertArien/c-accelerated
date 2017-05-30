#ifndef GUARD_pic_v_H
#define GUARD_pic_v_H

#include <iostream>
#include <algorithm>

#include "ptr.h"
#include "vec.h"
#include "str.h"

// Forward declaration
class Picture_v;


// private classes for use in the implementation only

class Pic_base_v {

  // this class is an abstract base class

  friend std::ostream& operator<<(std::ostream&, const Picture_v&);
  friend class Frame_Pic_v;
  friend class HCat_Pic_v;
  friend class VCat_Pic_v;
  friend class String_Pic_v;

  // no public interface

  typedef Vec<Str>::size_type ht_sz;
  typedef Str::size_type wd_sz;

  virtual wd_sz width() const = 0;
  virtual ht_sz height() const = 0;
  virtual void display(std::ostream&, ht_sz, bool) const = 0;

protected:

  static void pad(std::ostream& os, wd_sz beg, wd_sz end);
};



class Frame_Pic_v : public Pic_base_v {

  friend Picture_v frame(const Picture_v&);

  // no public interface
  Ptr<Pic_base_v> p;

  Frame_Pic_v(const Ptr<Pic_base_v>& pic) : p(pic) { }

  wd_sz width() const { return p->width() + 4; }
  ht_sz height() const { return p->height() + 4; }

  void display(std::ostream&, ht_sz, bool) const;
};



class VCat_Pic_v : public Pic_base_v {

  friend Picture_v vcat(const Picture_v&, const Picture_v&);

  Ptr<Pic_base_v> top, bottom;

  VCat_Pic_v(const Ptr<Pic_base_v>& t, const Ptr<Pic_base_v>& b) :
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
};



class HCat_Pic_v : public Pic_base_v {

  friend Picture_v hcat(const Picture_v&, const Picture_v&);

  Ptr<Pic_base_v> left, right;

  HCat_Pic_v(const Ptr<Pic_base_v>& l, const Ptr<Pic_base_v>& r) :
    left(l), right(r) { }

  wd_sz width() const { return left->width() + right->width(); }

  ht_sz height() const
  {    return std::max(left->height(), right->height());  }
  void display(std::ostream&, ht_sz, bool) const;
};



class String_Pic_v : public Pic_base_v {

  friend class Picture_v;

  Vec<Str> data;
  String_Pic_v(const Vec<Str>& v) : data(v) { }

  wd_sz width() const;
  ht_sz height() const { return data.size(); };
  void display(std::ostream&, ht_sz, bool) const;
};



// public interface class and operations
class Picture_v {

  friend std::ostream& operator<<(std::ostream&, const Picture_v&);
  friend Picture_v frame(const Picture_v&);
  friend Picture_v hcat(const Picture_v&, const Picture_v&);
  friend Picture_v vcat(const Picture_v&, const Picture_v&);

public:

  Picture_v(const Vec<Str>& =
    Vec<Str>());

private:

  Ptr<Pic_base_v> p;

  Picture_v(Pic_base_v* ptr) : p(ptr) { }

};



Picture_v frame(const Picture_v&);
Picture_v hcat(const Picture_v&, const Picture_v&);
Picture_v vcat(const Picture_v&, const Picture_v&);
std::ostream& operator<<(std::ostream&, const Picture_v&);

#endif // !GUARD_pic_v_H