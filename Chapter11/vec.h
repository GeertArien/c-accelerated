#ifndef GUARD_vec_H
#define GUARD_vec_H

#include <memory>
#include <algorithm>
#include <iterator>

template <class T> class Vec {

public:

  typedef T* iterator;
  typedef const T* const_iterator;
  typedef size_t size_type;
  typedef T value_type;

  Vec() { create(); }
  explicit Vec(size_type n, const T& t = T()) { create(n, t); }
  Vec(const Vec& v) { create(v.begin(), v.end()); }

  Vec& operator=(const Vec&);
  ~Vec() { uncreate(); }
  T& operator[](size_type i) { return data[i]; }
  const T& operator[](size_type i) const { return data[i]; }

  void push_back(const T& t, bool double_grow = true) {
    if (avail == limit)
      grow(double_grow);
    unchecked_append(t);
  }

  size_type size() const { return avail - data; }
  iterator begin() { return data; }
  const_iterator begin() const { return data; }
  iterator end() { return avail; }
  const_iterator end() const { return avail; }

  std::ostream& print_vec(std::ostream&);
  void clear() { destroy(); };
  iterator erase(iterator it) { return destroy(it); };
  iterator erase(iterator b, iterator e) { return destroy(b, e); };

private:

  iterator data; // first element in the Vec
  iterator avail; // (one past) the last element in the Vec
  iterator limit; // (one past) the allocated memory
                 
  std::allocator<T> alloc; // object to handle memory allocation
                      
  void create();
  void create(size_type, const T&);
  void create(const_iterator, const_iterator);

  // destroy the elements in the array and free the memory
  void uncreate();

  // destroy the elements in the array
  void destroy();
  iterator destroy(iterator);
  iterator destroy(iterator, iterator);

  // support functions for push_back
  void grow(bool);

  void unchecked_append(const T&);
};


template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
  // check for self-assignment
  if (&rhs != this) {
    // free the array in the left-hand side
    uncreate();
    // copy elements from the right-hand to the left-hand side
    create(rhs.begin(), rhs.end());
  }
  return *this;
}

template <class T> void Vec<T>::create()
{
  data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
  data = alloc.allocate(n);
  limit = avail = data + n;
  std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
  data = alloc.allocate(j - i);
  stdext::checked_array_iterator<T*> checked_data(data, (j - i));
  limit = avail = (std::uninitialized_copy(i, j, checked_data))._Unchecked();
}

template <class T> void Vec<T>::uncreate()
{
  if (data) {
    // destroy (in reverse order) the elements that were constructed
    iterator it = avail;
    while (it != data)
      alloc.destroy(--it);
    // return all the space that was allocated
    alloc.deallocate(data, limit - data);
  }
  // reset pointers to indicate that the Vec is empty again
  data = limit = avail = 0;
}

template <class T> void Vec<T>::grow(bool double_grow)
{
  size_type new_size;

  if (double_grow)
  {
    // when growing, allocate twice as much space as currently in use
    new_size = std::max(2 * (limit - data), ptrdiff_t(1));
  }
  else
    new_size = limit - data + 1;
    
  // allocate new space and copy existing elements to the new space
  iterator new_data = alloc.allocate(new_size);
  stdext::checked_array_iterator<T*> checked_data(new_data, new_size);
  iterator new_avail = (std::uninitialized_copy(data, avail, checked_data))._Unchecked();
  // return the old space
  uncreate();
  // reset pointers to point to the newly allocated space
  data = new_data;
  avail = new_avail;
  limit = data + new_size;
}

// assumes avail points at allocated, but uninitialized space
template <class T> void Vec<T>::unchecked_append(const T& val)
{
  alloc.construct(avail++, val);
}

template<class T>
std::ostream& Vec<T>::print_vec(std::ostream& os)
{
  if (avail - data > 0)
  {
    iterator iter = data;

    os << *iter++;

    while (iter != avail)
      os << ", " << *iter++;

    os << std::endl;
  }
  return os;
}

#endif // !GUARD_vec_H