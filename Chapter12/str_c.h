#ifndef GUARD_str_c_H
#define GUARD_str_c_H

#include <iostream>
#include <memory>

class Str_c {

  friend std::istream& operator >> (std::istream&, Str_c&);
  friend Str_c operator+(const char*, const Str_c&);
  friend std::istream& getline(std::istream&, Str_c&);

public:

  typedef size_t size_type;
  typedef char* iterator;
  typedef const char* const_iterator;

  // default constructor; create an empty Str
  Str_c() { create(0, '\0'); }

  // copy constructor
  Str_c(const Str_c& s) { create(s.d, s.d + s.size()); }

  // create a Str containing n copies of c
  Str_c(size_t n, char c) { create(n, c); }

  // create a Str from a null-terminated array of char
  Str_c(const char* cp) { create(cp, cp + std::strlen(cp)); }

  // create a Str from the range denoted by iterators b and e
  template<class In> Str_c(In b, In e) { create(b, e); }

  ~Str_c() { uncreate(); }

  Str_c& operator=(const Str_c&);

  size_t size() const { return length - 1; }

  char& operator[](size_t i) { return d[i]; }
  const char& operator[](size_t i) const { return d[i]; }

  Str_c& operator+=(const char* cp) {
    append(cp, strlen(cp));
    return *this;
  }

  Str_c& operator+=(const Str_c& s) {
    append(s);
    return *this;
  }

  operator void*() const { return is_not_empty(); };

  const char* c_str() const { return d; }
  const char* data() const { return d; }

  size_t copy(char* p, size_t n) const { return copy_characters(p, n); }

  iterator begin() { return d; };
  const_iterator begin() const { return d; };
  iterator end() { return d + size(); };
  const_iterator end() const { return d + size(); };

private:

  char *d;
  size_t length;
  std::allocator<char> alloc;

  void create(size_t, char);
  void uncreate()
  {
    if (length != 0)
      delete[] d;
    length = 0;
  }

  template<class In>
  void create(In i, In j)
  {
    length = j - i + 1;
    d = new char[length];
    memcpy(d, i, length - 1);
    d[length - 1] = '\0';
  }

  void append(const Str_c&);
  void append(const char*, const size_t);
  void prepend(const char*, const size_t);
  void append(const char);

  size_t copy_characters (char*, size_t) const;

  void* is_not_empty() const
  {
    if (size() > 0)
      return d;
    else
      return 0;
  }
};

std::istream& operator>>(std::istream&, Str_c&);
std::ostream& operator<<(std::ostream&, const Str_c&);

std::istream& getline(std::istream&, Str_c&);

Str_c operator+(const Str_c&, const Str_c&);
Str_c operator+(const Str_c&, const char*);
Str_c operator+(const char*, const Str_c&);

inline bool operator== (const Str_c& lhs, const Str_c& rhs)
{
  return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

inline bool operator!= (const Str_c& lhs, const Str_c& rhs)
{
  return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

inline bool operator< (const Str_c& lhs, const Str_c& rhs)
{
  return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

inline bool operator<= (const Str_c& lhs, const Str_c& rhs)
{
  return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

inline bool operator> (const Str_c& lhs, const Str_c& rhs)
{
  return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

inline bool operator>= (const Str_c& lhs, const Str_c& rhs)
{
  return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

#endif // !GUARD_str_c_H