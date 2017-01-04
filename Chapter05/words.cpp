#include "stdafx.h"
#include "words.h"

#include <algorithm>
#include <functional>


using std::vector;  using std::string;
using std::max;     using std::transform;
using std::ostream; using std::sort;
using std::greater; using std::list;

vector<string> split(const string& s) {
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
      ret.push_back(s.substr(i, j - i));
      i = j;
    }
  }
  return ret;
}

string::size_type width(const vector<string>& v) {
  string::size_type maxlen = 0;
  
  for (vector<string>::size_type i = 0; i != v.size(); ++i)
    maxlen = max(maxlen, v[i].size());

  return maxlen;
}

vector<string> frame(const vector<string>& v) {
  vector<string> ret;
  string::size_type maxlen = width(v);
  string border(maxlen + 4, '*');

  ret.push_back(border);

  for (vector<string>::size_type i = 0; i != v.size(); ++i) {
    ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
  }

  ret.push_back(border);

  return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
  vector<string> ret = top;

  //for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
  //  ret.push_back(*it);
  ret.insert(ret.end(), bottom.begin(), bottom.end());

  return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right) {
  vector<string> ret;

  string::size_type width1 = width(left) + 1;

  vector<string>::size_type i = 0, j = 0;

  while (i != left.size() || j != right.size()) {
    string s;

    if (i != left.size())
      s = left[i++];

    s += string(width1 - s.size(), ' ');

    if (j != right.size())
      s += right[j++];

    ret.push_back(s);
  }

  return ret;
}

vector<string> center(const vector<string>& v) {
  vector<string> v_out;
  vector<string>::size_type maxlen = width(v);
  vector<string>::const_iterator iter = v.begin();

  while (iter != v.end()) {
    int spaces_l = (maxlen - iter->size()) / 2;
    int spaces_r = maxlen - iter->size() - spaces_l;
    v_out.push_back(string(spaces_l, ' ') + *iter++ + string(spaces_r, ' '));
  }

  return v_out;
}

bool compare_ignore_case(string s1, string s2) {
  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

  return s1 < s2;
}

ostream& write_lower_upper(ostream& os, const vector<string>& v) {
  vector<string> v_copy = v;
  sort(v_copy.begin(), v_copy.end(), greater<string>());
  
  for (vector<string>::size_type i = 0; i < v_copy.size(); i++) {
    os << v_copy[i] << std::endl;
  }

  return os;
}

bool is_palindrome(const string& s) {
  string::const_iterator iter = s.begin();
  string::const_reverse_iterator r_iter = s.rbegin();

  while (iter != r_iter.base() && iter + 1 != r_iter.base())
    if (tolower(*iter++) != tolower(*r_iter++))
      return false;

  return true;
}

vector<string> get_palindromes(const vector<string>& v) {
  vector<string> p;
  vector<string>::const_iterator iter = v.begin();

  while (iter != v.end()) {
    if (is_palindrome(*iter))
      p.push_back(*iter);
    ++iter;
  }

  return p;
}

ostream& write_palindromes(ostream& os, const vector<string>& v) {
  vector<string> palindromes = get_palindromes(v);

  for (vector<string>::size_type i = 0; i < palindromes.size(); i++) {
    os << palindromes[i] << std::endl;
  }

  return os;
}

bool has_asc_desc(const string& s) {
  string::const_iterator iter = s.begin();
  string asc_desc = "bdfhkltgjpqy";

  while (iter != s.end()) {
    std::size_t found = asc_desc.find(tolower(*iter++));
    if (found != std::string::npos)
      return true;
  }

  return false;
}

list<string> extract_asc_desc(list<string>& l) {
  list<string> l_ad;
  list<string>::const_iterator iter = l.begin();

  while (iter != l.end()) {
    if (has_asc_desc(*iter)) {
      l_ad.push_back(*iter);
      iter = l.erase(iter);
    }
    else
      ++iter;
  }
  return l_ad;
}

string longest_not_asc_desc(list<string> l) {
  extract_asc_desc(l);
  string longest;

  for (list<string>::const_iterator iter = l.begin(); iter != l.end(); iter++)
    if (iter->length() > longest.length())
      longest = *iter;

  return longest;
}