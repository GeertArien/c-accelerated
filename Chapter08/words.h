#ifndef GUARD_words_H
#define GUARD_words_H

#include <string>
#include <algorithm>

bool space(char c)
{
  return isspace(c) != 0;
}

bool not_space(char c)
{
  return !isspace(c);
}

template <class Out> // changed
void split(const std::string& str, Out os) { // changed
  typedef std::string::const_iterator iter;
  iter i = str.begin();
  while (i != str.end()) {
    // ignore leading blanks
    i = std::find_if(i, str.end(), not_space);
    // find end of next word
    iter j = std::find_if(i, str.end(), space);
    // copy the characters in [i, j)
    if (i != str.end())
      *os++ = std::string(i, j); // changed
    i = j;
  }
}

#endif // !GUARD_words_H