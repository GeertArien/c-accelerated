/**
Accelerated C++, Exercise 14-5, 14_5.cpp

Test the reimplemented Str class by recompiling and rerunning programs that
use Str, such as the version of split and the picture operations that use a Vec<Str>.
*/

#include "stdafx.h"
#include "14_5.h"

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::max;
using std::find_if;

#include "str.h"

Str::size_type width(const vector<Str>& v)
{
  Str::size_type maxlen = 0;

  for (vector<Str>::size_type i = 0; i != v.size(); ++i)
    maxlen = max(maxlen, v[i].size());

  return maxlen;
}

vector<Str> frame(const vector<Str>& v)
{
  vector<Str> ret;
  Str::size_type maxlen = width(v);
  Str border(maxlen + 4, '*');

  ret.push_back(border);

  for (vector<Str>::size_type i = 0; i != v.size(); ++i)
  {
    ret.push_back("* " + v[i] + Str(maxlen - v[i].size(), ' ') + " *");
  }

  ret.push_back(border);

  return ret;
}

vector<Str> vcat(const vector<Str>& top, const vector<Str>& bottom)
{
  vector<Str> ret = top;

  ret.insert(ret.end(), bottom.begin(), bottom.end());

  return ret;
}

vector<Str> hcat(const vector<Str>& left, const vector<Str>& right)
{
  vector<Str> ret;

  Str::size_type width1 = width(left) + 1;

  vector<Str>::size_type i = 0, j = 0;

  while (i != left.size() || j != right.size())
  {
    Str s;

    if (i != left.size())
      s = left[i++];

    s += Str(width1 - s.size(), ' ');

    if (j != right.size())
      s += right[j++];

    ret.push_back(s);
  }

  return ret;
}

vector<Str> center(const vector<Str>& v)
{
  vector<Str> v_out;
  vector<Str>::size_type maxlen = width(v);
  vector<Str>::const_iterator iter = v.begin();

  while (iter != v.end())
  {
    int spaces_l = (maxlen - iter->size()) / 2;
    int spaces_r = maxlen - iter->size() - spaces_l;

    if (spaces_l != 0)
      v_out.push_back(Str(spaces_l, ' ') + *iter++ + Str(spaces_r, ' '));
    else
      v_out.push_back(*iter++);
  }

  return v_out;
}

vector<Str> split(const Str& s)
{
  vector<Str> ret;
  typedef Str::size_type Str_size;
  Str_size i = 0;

  while (i != s.size())
  {
    while (i != s.size() && isspace(s[i]))
      ++i;

    Str_size j = i;

    while (j != s.size() && !isspace(s[j]))
      ++j;

    if (i != j)
    {
      ret.push_back(Str(s.begin() + i, s.begin() + j));
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

vector<Str> split_alt(const Str& str)
{
  typedef Str::const_iterator iter;
  vector<Str> ret;

  iter i = str.begin();
  while (i != str.end())
  {

    i = find_if(i, str.end(), not_space);

    iter j = find_if(i, str.end(), space);

    if (i != str.end())
      ret.push_back(Str(i, j));
    i = j;
  }
  return ret;
}

int test_frame()
{
  vector<Str> v1 = { "one test", "two test", "aye caramba" };
  vector<Str> v2 = { "one direction", "mama mia", "mamo testo", "lake district mall" };

  vector<Str> vert = vcat(frame(v1), frame(v2));

  vector<Str>::const_iterator iter = vert.begin();

  while (iter != vert.end())
    cout << *iter++ << endl;

  vector<Str> horz = hcat(frame(v1), frame(v2));

  iter = horz.begin();

  while (iter != horz.end())
    cout << *iter++ << endl;

  return 0;
}

int test_center()
{
  vector<Str> v = { "This is really great", "really", "super awesome", "awesomesauce" };
  vector<Str> centered_v = center(v);

  vector<Str>::const_iterator iter = centered_v.begin();

  while (iter != centered_v.end())
    cout << *iter++ << endl;

  return 0;
}

int test_string_split()
{
  Str s = "Split this string!";

  vector<Str> v = split(s);

  for (vector<Str>::size_type i = 0; i != v.size(); ++i)
    cout << v[i] << endl;

  return 0;
}

int test_string_split_alt()
{
  Str s = "And this one too!";

  vector<Str> v = split(s);

  for (vector<Str>::size_type i = 0; i != v.size(); ++i)
    cout << v[i] << endl;

  return 0;
}

int ex14_5()
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