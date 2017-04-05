#ifndef GUARD_10_4_H
#define GUARD_10_4_H

class String_list {

private:

  char** l;
  size_t size;
  size_t max;

  void resize();

public:

  String_list() : l(new char*[1]), size(0), max(1) {};
  ~String_list();

  void push_back(const char*);
  char** begin() { return l; }
  char** end() { return l + size; };
};

int ex10_4();

#endif // !GUARD_10_4_H