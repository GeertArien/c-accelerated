#ifndef GUARD_ptr_r_H
#define GUARD_ptr_r_H

#include <exception>

#include "ref_counter.h"

template<class T> class Ptr_r {

public:

  void make_unique() {
    if (ref_c.count() != 1) {
      --ref_c;
      ref_c = ref_c();
      p = p ? clone(p) : 0;               // call the global (not member) version of clone
    }
  }

  Ptr_r() : p(0) { }
  Ptr_r(T* t) : p(t) { }
  Ptr_r(const Ptr_r& h) : ref_c(h.ref_c), p(h.p) { ++ref_c; }

  Ptr_r& operator=(const Ptr_r&); 
  ~Ptr_r();

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

template<class T>
Ptr_r<T>& Ptr_r<T>::operator=(const Ptr_r& rhs)
{
  if (&rhs != this)
  {
    // free the left-hand side, destroying pointers if appropriate
    if ((--ref_c).count() == 0) {
      delete p;
    }
    // copy in values from the right-hand side
    ref_c = rhs.ref_c;
    p = rhs.p;
    ++ref_c;
  }
  
  return *this;
}

template<class T> 
Ptr_r<T>::~Ptr_r()
{
  if ((--ref_c).count() == 0) {
    delete p;
  }
}

#endif // !GUARD_ptr_r_H