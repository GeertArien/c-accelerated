#ifndef GUARD_8_2_H
#define GUARD_8_2_H

int ex8_2();

// Input Iterator
class algorithms {

public:

  // Input iterators
  template <class In1, class In2>
  static bool equal(In1 b, In1 e, In2 d)
  {
    while (b != e)
      if (*b++ != *d++)
        return false;

    return true;
  }

  // Input iterators
  template <class In, class X>
  static In find(In b, In e, const X& t)
  {
    while (b != e && *b != t)
      ++b;

    return b;
  }

};

#endif // !GUARD_8_2_H