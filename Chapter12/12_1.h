#ifndef GUARD_12_1_H
#define GUARD_12_1_H

#include <iostream>
#include <memory>

class Str_c {

  friend std::istream& operator >> (std::istream&, Str_c&);

public:

  typedef size_t size_type;

  // default constructor; create an empty Str
  Str_c() : data(0), length(0) { }

  // create a Str containing n copies of c
  Str_c(size_t n, char c) { create(n, c); }

  // create a Str from a null-terminated array of char
  Str_c(const char* cp) { create(cp, cp + std::strlen(cp)); }

  // create a Str from the range denoted by iterators b and e
  template<class In> Str_c(In b, In e) { create(b, e); }

  ~Str_c() { uncreate(); }

  Str_c& operator=(const Str_c&);

  size_t size() const { return length; }

  char& operator[](size_t i) { return data[i]; }
  const char& operator[](size_t i) const { return data[i]; }

  Str_c& operator+=(const Str_c& s) {
    append(s);
    return *this;
  }


private:

  char *data;
  size_t length;
  std::allocator<char> alloc;

  void create(size_t, char);
  void uncreate()
  {
    length = 0;
    if (length != 0)
      delete[] data;
  }

  template<class In>
  void create(In i, In j)
  {
    length = j - i;
    data = new char[length];
    memcpy(data, i, length);
  }

  void append(const Str_c&);
  void append(const char);

};

std::istream& operator >> (std::istream&, Str_c&);
std::ostream& operator<<(std::ostream&, const Str_c&);

Str_c operator+(const Str_c&, const Str_c&);

int ex12_1();

#endif // !GUARD_12_1_H