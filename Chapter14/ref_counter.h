#ifndef GUARD_ref_counter_H
#define GUARD_ref_counter_H

template<class T> class Ref_counter {

public:

  Ref_counter() : data(new size_t(1)) { }

  Ref_counter& operator++() {
    (*refptr)++;
    return *this;
  };

  Ref_counter& operator--() {
    (*refptr)--;
    return *this;
  };

  ~Ref_counter(); // implemented analogously to §14.2/262


private:

  size_t* data;

};

#endif // !GUARD_ref_counter_H