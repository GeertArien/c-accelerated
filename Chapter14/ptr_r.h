#ifndef GUARD_ptr_r_H
#define GUARD_ptr_r_H

#include <exception>

#include "ref_counter.h"

template<class T> class Ptr_r {

public:

  void make_unique() {
    if (ref_c.value() != 1) {
      --ref_c;
      ref_c =;
      p = p ? clone(p) : 0;               // call the global (not member) version of clone
    }
  }

  Ptr_r() : refptr(new size_t(1)), p(0) { }
  Ptr_r(T* t) : refptr(new size_t(1)), p(t) { }
  Ptr_r(const Ptr& h) : refptr(h.refptr), p(h.p) { ++*refptr; }

  Ptr_r& operator=(const Ptr&); // implemented analogously to §14.2/261
  ~Ptr_r(); // implemented analogously to §14.2/262

  operator bool() const { return p != 0; }

  T& operator*() const
  {
    if (p)
      return *p;
    throw std::runtime_error("unbound Ref_handle");
  }

  T* operator->() const {
    if (p)
      return p;
    throw std::runtime_error("unbound Ref_handle");
  }

private:

  T* p;
  Ref_counter ref_c;

};


#endif // !GUARD_ptr_r_H