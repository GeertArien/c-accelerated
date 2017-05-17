#ifndef GUARD_STR_H
#define GUARD_STR_H

#include <algorithm>
#include <iostream>

#include "vec.h"

class Str {

  friend std::istream& operator >> (std::istream&, Str&);

public:

  typedef Vec<char>::size_type size_type;
  typedef Vec<char>::iterator iterator;
  typedef Vec<char>::const_iterator const_iterator;

  // default constructor; create an empty Str
  Str() { }

  // create a Str containing n copies of c
  Str(size_type n, char c) : data(n, c) { }

  // create a Str from a null-terminated array of char
  Str(const char* cp) {
    std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
  }

  // create a Str from the range denoted by iterators b and e
  template<class In> Str(In b, In e) : data(b, e) { }

  size_type size() const { return data.size(); }

  char& operator[](size_type i) { return data[i]; }
  const char& operator[](size_type i) const { return data[i]; }

  Str& operator+=(const Str& s) {
    std::copy(s.data.begin(), s.data.end(),
      std::back_inserter(data));
    return *this;
  }

  template <class In>
  void insert(iterator position, In first, In last) { data.insert(position, first, last); };

  iterator begin() { return data.begin(); };
  const_iterator begin() const { return data.begin(); };
  iterator end() { return data.end(); };
  const_iterator end() const { return data.end(); };

private:

  Vec<char> data;

};

std::istream& operator >> (std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);

Str operator+(const Str&, const Str&);

#endif // !GUARD_STR_H