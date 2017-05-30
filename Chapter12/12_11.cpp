/**
Accelerated C++, Exercise 12_11, 12_11.cpp

If you add the operations listed in these exercises, then you can use this Str
class in all the examples in this book. Reimplement the operations on character pictures
from Chapter 5 and the split functions from §5.6/87 and §6.1.1/103.
*/

#include "stdafx.h"
#include "12_11.h"

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::max;
using std::find_if;

#include "str_c.h"

Str_c::size_type width(const vector<Str_c>& v)
{
  Str_c::size_type maxlen = 0;

  for (vector<Str_c>::size_type i = 0; i != v.size(); ++i)
    maxlen = max(maxlen, v[i].size());

  return maxlen;
}

vector<Str_c> frame(const vector<Str_c>& v)
{
  vector<Str_c> ret;
  Str_c::size_type maxlen = width(v);
  Str_c border(maxlen + 4, '*');

  ret.push_back(border);

  for (vector<Str_c>::size_type i = 0; i != v.size(); ++i)
  {
    ret.push_back("* " + v[i] + Str_c(maxlen - v[i].size(), ' ') + " *");
  }

  ret.push_back(border);

  return ret;
}

vector<Str_c> vcat(const vector<Str_c>& top, const vector<Str_c>& bottom)
{
  vector<Str_c> ret = top;

  //for (vector<Str_c>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
  //  ret.push_back(*it);
  ret.insert(ret.end(), bottom.begin(), bottom.end());

  return ret;
}

vector<Str_c> hcat(const vector<Str_c>& left, const vector<Str_c>& right)
{
  vector<Str_c> ret;

  Str_c::size_type width1 = width(left) + 1;

  vector<Str_c>::size_type i = 0, j = 0;

  while (i != left.size() || j != right.size())
  {
    Str_c s;

    if (i != left.size())
      s = left[i++];

    s += Str_c(width1 - s.size(), ' ');

    if (j != right.size())
      s += right[j++];

    ret.push_back(s);
  }

  return ret;
}

vector<Str_c> center(const vector<Str_c>& v)
{
  vector<Str_c> v_out;
  vector<Str_c>::size_type maxlen = width(v);
  vector<Str_c>::const_iterator iter = v.begin();

  while (iter != v.end())
  {
    int spaces_l = (maxlen - iter->size()) / 2;
    int spaces_r = maxlen - iter->size() - spaces_l;
    v_out.push_back(Str_c(spaces_l, ' ') + *iter++ + Str_c(spaces_r, ' '));
  }

  return v_out;
}

vector<Str_c> split(const Str_c& s)
{
  vector<Str_c> ret;
  typedef Str_c::size_type Str_c_size;
  Str_c_size i = 0;

  while (i != s.size())
  {
    while (i != s.size() && isspace(s[i]))
      ++i;

    Str_c_size j = i;

    while (j != s.size() && !isspace(s[j]))
      ++j;

    if (i != j)
    {
      ret.push_back(Str_c(s.begin() + i, s.begin() + j));
      i = j;
    }
  }
  return ret;
}

bool space(char c)
{
  return isspace(c) != 0;
}

bool not_space(char c)
{
  return !isspace(c);
}

vector<Str_c> split_alt(const Str_c& str)
{
  typedef Str_c::const_iterator iter;
  vector<Str_c> ret;

  iter i = str.begin();
  while (i != str.end())
  {

    i = find_if(i, str.end(), not_space);

    iter j = find_if(i, str.end(), space);

    if (i != str.end())
      ret.push_back(Str_c(i, j));
    i = j;
  }
  return ret;
}

int test_frame()
{
  vector<Str_c> v1 = { "one test", "two test", "aye caramba" };
  vector<Str_c> v2 = { "one direction", "mama mia", "mamo testo", "lake district mall" };

  vector<Str_c> vert = vcat(frame(v1), frame(v2));

  vector<Str_c>::const_iterator iter = vert.begin();

  while (iter != vert.end())
    cout << *iter++ << endl;

  vector<Str_c> horz = hcat(frame(v1), frame(v2));

  iter = horz.begin();

  while (iter != horz.end())
    cout << *iter++ << endl;

  return 0;
}

int test_center()
{
  vector<Str_c> v = { "This is really great", "really", "super awesome", "awesomesauce" };
  vector<Str_c> centered_v = center(v);

  vector<Str_c>::const_iterator iter = centered_v.begin();

  while (iter != centered_v.end())
    cout << *iter++ << endl;

  return 0;
}

int test_string_split()
{
  Str_c s = "Split this string!";

  vector<Str_c> v = split(s);

  for (vector<Str_c>::size_type i = 0; i != v.size(); ++i)
    cout << v[i] << endl;

  return 0;
}

int test_string_split_alt()
{
  Str_c s = "And this one too!";

  vector<Str_c> v = split(s);

  for (vector<Str_c>::size_type i = 0; i != v.size(); ++i)
    cout << v[i] << endl;

  return 0;
}

int ex12_11()
{
  test_frame();
  cout << endl;
  test_center();
  cout << endl;
  test_string_split();
  cout << endl;
  test_string_split_alt();
  cout << endl;

  return 0;
}