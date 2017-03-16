#ifndef GUARD_8_2_H
#define GUARD_8_2_H

#include <algorithm>

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

  // Forward iterators
  template <class Fw1, class Fw2>
  static Fw1 search(Fw1 b, Fw1 e, Fw2 b2, Fw2 e2)
  {
    while (b != e)
    {
      Fw1 b_pat = b;
      Fw2 b2_pat = b2;

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

  // Input iterators
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

  // Input iterators, output iterator
  template <class In, class Out, class X>
  static Out remove_copy(In b, In e, Out d, const X& t)
  {
    while (b != e)
    {
      if (*b != t)
        *d++ = *b;
      ++b;
    }

    return d;
  }

  // Input iterators, output iterator
  template <class In, class Out, class P>
  static Out remove_copy_if(In b, In e, Out d, P p)
  {
    while (b != e)
    {
      if (!p(*b))
        *d++ = *b;
      ++b;
    }

    return d;
  }

  // Forward iterator
  template <class Fw, class X>
  static Fw remove(Fw b, Fw e, const X& t)
  {
    Fw b_in = b;

    while (b_in != e)
    {
      if (*b_in != t)
        *b++ = *b_in;

      ++b_in;
    }

    return b;
  }

  // Input iterators, output iterator
  template <class In, class Out, class P>
  static Out transform(In b, In e, Out d, P p)
  {
    while (b != e)
      *d++ = p(*b++);

    return d;
  }

  // Forward iterators
  template <class Fw, class P>
  static Fw partition(Fw b, Fw e, P p)
  {
    Fw b_out = b;

    while (b != e)
    {
      if (p(*b))
        std::iter_swap(b, b_out++);
      b++;
    }

    return b_out;
  }

  // Input iterator
  template <class In, class X>
  static X accumulate(In b, In e, X t)
  {
    while (b != e)
      t += *b++;

    return t;
  }

};

#endif // !GUARD_8_2_H