#ifndef GUARD_ref_counter_H
#define GUARD_ref_counter_H

class Ref_counter {

public:

  Ref_counter() : counter(new size_t(1)) { };

  Ref_counter(size_t s) : counter(new size_t(s)) { };

  Ref_counter(const Ref_counter& r) : counter(r.counter) { };

  Ref_counter& operator=(const Ref_counter& rhs) {
    if (*counter <= 0)
      delete counter;
    counter = rhs.counter;

    return *this;
  };

  Ref_counter& operator++() {
    (*counter)++;
    return *this;
  };

  Ref_counter& operator--() {
    (*counter)--;
    return *this;
  };

  Ref_counter operator++(int) {
    Ref_counter ret(*(this->counter));
    (*counter)++;
    return ret;
  };

  Ref_counter operator--(int) {
    Ref_counter ret(*(this->counter));
    (*counter)--;
    return ret;
  };

  ~Ref_counter() {
    if (*counter <= 0)
      delete counter;
  };

  size_t count() { return *counter; };


private:

  size_t* counter;

};

#endif // !GUARD_ref_counter_H