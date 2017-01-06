#include "stdafx.h"

#include <algorithm>

#include "words.h"

using std::string;    using std::vector;

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