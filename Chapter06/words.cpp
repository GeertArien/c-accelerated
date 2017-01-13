#include "stdafx.h"

#include <algorithm>
#include <numeric>

#include "words.h"

using std::string;    using std::vector;
using std::max;       using std::accumulate;

bool space(char c) {
  return isspace(c) != 0;
}

bool not_space(char c) {
  return !isspace(c);
}

bool not_url_char(char c) {
  static const string url_ch = "~;/?:@=&$-_.+!*'(),";

  return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

bool is_palindrome(const std::string& s) {
  return equal(s.begin(), s.end(), s.rbegin());
}

vector<string> split(const string& str) {
  typedef string::const_iterator iter;
  vector<string> ret;

  iter i = str.begin();
  while (i != str.end()) {

    i = find_if(i, str.end(), not_space);

    iter j = find_if(i, str.end(), space);

    if (i != str.end())
      ret.push_back(string(i, j));
    i = j;
  }
  return ret;
}

vector<string> find_urls(const string& s) {
  vector<string> ret;
  typedef string::const_iterator iter;
  iter b = s.begin(), e = s.end();

  while (b != e) {

    b = url_beg(b, e);

    if (b != e) {
      iter after = url_end(b, e);

      ret.push_back(string(b, after));

      b = after;
    }
  }

  return ret;
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) {
  static const string sep = "://";

  typedef string::const_iterator iter;

  iter i = b;

  while ((i = search(i, e, sep.begin(), sep.end())) != e) {

    if (i != b && i + sep.size() != e) {

      iter beg = i;
      while (beg != b && isalpha(beg[-1]))
        --beg;

      if (beg != i && !not_url_char(i[sep.size()]))
        return beg;
    }

    i += sep.size();
  }
  
  return e;
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
  return find_if(b, e, not_url_char);
}

vector<string> frame(const vector<string>& v) {
  vector<string> ret;
  string::size_type maxlen = width(v);
  string border(maxlen + 4, '*');
  vector<string>::const_iterator iter = v.begin();

  ret.push_back(border);

  while(iter != v.end()) {
    ret.push_back("* " + *iter++ + string(maxlen - iter->size(), ' ') + " *");
  }

  ret.push_back(border);
  return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right) {
  typedef vector<string>::const_iterator iter;
  iter iter_l = left.begin();
  iter iter_r = right.begin();
  vector<string> ret;

  string::size_type width1 = width(left) + 1;

  while (iter_l != left.end() || iter_r != right.end()) {
    string s;

    if (iter_l != left.end())
      s = *iter_l++;

    s += string(width1 - s.size(), ' ');

    if (iter_r != right.end())
      s += *iter_r++;

    ret.push_back(s);
  }

  return ret;
}

string::size_type width(const vector<string>& v) {
  string::size_type maxlen = 0;
  typedef vector<string>::const_iterator iter;
  iter it = v.begin();

  while (it != v.end())
    maxlen = max(maxlen, it++->size());

  return maxlen;
}

string concat(const vector<string>& v) {
  string s;
  return accumulate(v.begin(), v.end(), s);
}
