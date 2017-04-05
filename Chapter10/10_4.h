#ifndef GUARD_10_4_H
#define GUARD_10_4_H

#include <string>

class String_list {

private:

  std::string *l;
  std::string::size_type size;
  std::string::size_type max;

  void resize();

public:

  typedef std::string* iterator;

  String_list() : l(new std::string[1]), size(0), max(1) {};
  String_list(const String_list& src);
  ~String_list();

  void push_back(std::string);
  std::string* begin() { return l; }
  std::string* end() { return l + size; };
};

int ex10_4();

#endif // !GUARD_10_4_H