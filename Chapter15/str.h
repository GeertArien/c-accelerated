#ifndef GUARD_Str_H
#define GUARD_Str_H

#include <iostream>
#include <memory>

class Str {

  friend std::istream& operator >> (std::istream&, Str&);
  friend Str operator+(const char*, const Str&);
  friend std::istream& getline(std::istream&, Str&);

public:

  typedef size_t size_type;
  typedef char* iterator;
  typedef const char* const_iterator;

  // default constructor; create an empty Str
  Str() { create(0, '\0'); }

  // copy constructor
  Str(const Str& s) { create(s.d, s.d + s.size()); }

  // create a Str containing n copies of c
  Str(size_t n, char c) { create(n, c); }

  // create a Str from a null-terminated array of char
  Str(const char* cp) { create(cp, cp + std::strlen(cp)); }

  // create a Str from the range denoted by iterators b and e
  template<class In> Str(In b, In e) { create(b, e); }

  ~Str() { uncreate(); }

  Str& operator=(const Str&);

  size_t size() const { return length - 1; }

  char& operator[](size_t i) { return d[i]; }
  const char& operator[](size_t i) const { return d[i]; }

  Str& operator+=(const char* cp) {
    append(cp, strlen(cp));
    return *this;
  }

  Str& operator+=(const Str& s) {
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

  void append(const Str&);
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

std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);

std::istream& getline(std::istream&, Str&);

Str operator+(const Str&, const Str&);
Str operator+(const Str&, const char*);
Str operator+(const char*, const Str&);

inline bool operator== (const Str& lhs, const Str& rhs)
{
  return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

inline bool operator!= (const Str& lhs, const Str& rhs)
{
  return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

inline bool operator< (const Str& lhs, const Str& rhs)
{
  return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

inline bool operator<= (const Str& lhs, const Str& rhs)
{
  return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

inline bool operator> (const Str& lhs, const Str& rhs)
{
  return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

inline bool operator>= (const Str& lhs, const Str& rhs)
{
  return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

#endif // !GUARD_Str_H