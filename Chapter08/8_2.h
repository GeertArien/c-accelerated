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
  template <class In1, class In2>
  static In1 search(In1 b, In1 e, In2 b2, In2 e2)
  {
    while (b != e)
    {
      In1 b_pat = b;
      In2 b2_pat = b2;

      while (*b_pat++ == *b2_pat++)
      {
        if (b2_pat == e2)
          return b;
        if (b_pat == e)
          return e;
      }

      ++b;
    }

    return e;
  }

  // Input iterators
  template <class In, class X>
  static In find(In b, In e, const X& t)
  {
    while (b != e && *b != t)
      ++b;

    return b;
  }

  template <class In, class P>
  static In find_if(In b, In e, P p)
  {
    while (b != e && !p(*b))
      ++b;

    return b;
  }

  // Input iterators, output iterator
  template <class In, class Out>
  static Out copy(In b, In e, Out d)
  {
    while (b != e)
      *d++ = *b++;

    return d;
  }

};

#endif // !GUARD_8_2_H