#include "stdafx.h"

#include <algorithm>

#include "permuted_index.h"
#include "words.h"

using std::vector;    using std::string;
using std::sort;

vector<string> rotate(const std::string& s) {
  vector<string> ret;
  typedef string::size_type string_size;
  string_size i = 0;

  while (i != s.size()) {

    while (i != s.size() && isspace(s[i]))
      ++i;

    string_size j = i;

    while (j != s.size() && !isspace(s[j]))
      ++j;

    if (i != j) {
      string line = s.substr(i, s.size() - i);
      line += '\t';
      line += s.substr(0, i);
      ret.push_back(line);
      i = j;
    }
  }
  return ret;
}

void unrotate(vector<string>& v) {
  vector<string> v1, v2;
  vector<string>::iterator iter = v.begin();

  typedef string::size_type s_size;

  while (iter != v.end()) {
    s_size seperator = iter->find('\t');

    v1.push_back(iter->substr(seperator + 1, iter->size() - 1));
    v2.push_back(iter->substr(0, seperator));
    ++iter;
  }

  iter = v.begin();
  vector<string>::iterator iter_v1 = v1.begin();
  vector<string>::iterator iter_v2 = v2.begin();
  s_size maxlen = width(v1);

  while (iter != v.end()) {
    *iter = string(maxlen - iter_v1->size(), ' ') + *iter_v1 + '\t' + *iter_v2;
    ++iter, ++iter_v1, ++iter_v2;
  }
}

vector<string> permuted_index(const vector<string>& v) {
  vector<string>::const_iterator iter = v.begin();
  vector<string> permuted_v;

  while (iter != v.end()) {
    vector<string> rotated_v = rotate(*iter++);
    permuted_v.insert(permuted_v.end(), rotated_v.begin(), rotated_v.end());
  }

  sort(permuted_v.begin(), permuted_v.end(), compare_ignore_case);

  unrotate(permuted_v);

  return permuted_v;
}