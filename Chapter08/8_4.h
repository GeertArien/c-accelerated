#ifndef GUARD_8_4_H
#define GUARD_8_4_H

int ex8_4();

template <class T>
void swap(T &l, T &r)
{
  T t = l;
  l = r;
  r = t;
}

template <class Bi>
void reversing(Bi begin, Bi end)
{
  while (begin != end)
  {
    --end;
    if (begin != end)
      swap(*begin++, *end);       
    // to swap it directly we need to know the 
    // type of the element the iterator is pointing at
  }
}

#endif // !GUARD_8_4_H