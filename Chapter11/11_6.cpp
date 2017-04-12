/**
Accelerated C++, Exercise 11-6, 11_6.cpp

Add an operation to remove an element from a Vec and another to empty the
entire Vec. These should behave analogously to the erase and clear operations on
vectors.
*/

#include "stdafx.h"
#include "11_6.h"

#include <iostream>
using std::cout;

#include "vec.h"

template <class T> 
void Vec<T>::destroy()
{
  if (data) 
  {
    // destroy (in reverse order) the elements that were constructed
    iterator it = avail;
    while (it != data)
      alloc.destroy(--it);
  }
  // reset pointers to indicate that the Vec is empty
  avail = data;
}

template<class T>
typename Vec<T>::iterator Vec<T>::destroy(iterator pos)
{
  if (data && pos != avail)
  {
    alloc.destroy(pos);
    iterator it = pos + 1;

    while (it != avail)
    {
      alloc.construct(pos++, *it++);
      alloc.destroy(pos);
    }
    avail = pos;
  }
  return avail;
}

template<class T>
typename Vec<T>::iterator Vec<T>::destroy(iterator b, iterator e)
{
  if (data && b != avail && b != e)
  {
    iterator it = b;
    while (it != e)
      alloc.destroy(it++);

    while (e != avail)
    {
      alloc.construct(b++, *e);
      alloc.destroy(e++);
    }

    avail = b;
  }
  return avail;
}

int ex11_6()
{
  Vec<int> v(10, 10);
  v.print_vec(cout);
  v.clear();
  v.print_vec(cout);
  for (Vec<int>::size_type i = 0; i < 10; i++)
    v.push_back(i);
  v.print_vec(cout);
  v.erase(v.begin() + 2);
  v.print_vec(cout);
  v.erase(v.begin() + 4, v.begin() + 7);
  v.print_vec(cout);

  return 0;
}