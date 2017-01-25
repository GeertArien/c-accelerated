#include "stdafx.h"
#include "words.h"

#include <string>
#include <map>
#include <list>
#include <istream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

#include "numbers.h"

using std::string;      using std::map;
using std::istream;     using std::ostream;
using std::endl;        using std::vector;
using std::find_if;     using std::getline;
using std::logic_error; using std::pair;
using std::multimap;    using std::transform;
using std::inserter;    using std::sort;
using std::distance;    using std::unique;
using std::list;        using std::copy;
using std::back_inserter;
using std::front_inserter;

istream& count_words(istream& is, ostream& os) {
  string s;
  map<string, int> counters;

  while (is >> s)
    ++counters[s];

  for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it)
    os << it->first << "\t" << it->second << endl;

  return is;
}

pair<int, string> flip_count_pair(pair<string, int> p) {
  return pair<int, string>(p.second, p.first);
}

map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&)) {
  string line;
  int line_number = 0;
  map<string, vector<int> > ret;

  while (getline(in, line)) {
    ++line_number;

    vector<string> words = find_words(line);

    for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
      ret[*it].push_back(line_number);
  }

  return ret;
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

list<string> split_l(const string& str) {
  vector<string> ret = split(str);
  list <string> list;
  copy(ret.begin(), ret.end(), back_inserter(list));
  
  return list;
}

bool space(char c) {
  return isspace(c) != 0;
}

bool not_space(char c) {
  return !isspace(c);
}

bool bracketed(const string& s) {
  return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

Grammar read_grammar(istream& in) {
  Grammar ret;
  string line;

  while (getline(in, line)) {
    list<string> entry = split_l(line);

    if (!entry.empty())
      ret[entry.front()].push_back(Rule(++entry.begin(), entry.end()));
  }

  return ret;
}

list<string> gen_sentence(const Grammar& g) {
  list<string> ret;
  gen_aux(g, "<sentence>", ret);

  return ret;
}

vector<string> gen_sentence_v2(const Grammar& g) {
  vector<string> ret;
  vector<string> rules;

  rules.push_back("<sentence>");

  while (!rules.empty()) {

    string segment = rules.back();
    rules.pop_back();

    if (!bracketed(segment))
      ret.push_back(segment);
    else {

      Grammar::const_iterator it = g.find(segment);

      if (it == g.end())
        throw logic_error("empty rule");

      const Rule_collection& c = it->second;

      const Rule& r = c[nrand(c.size())];

      for (Rule::const_reverse_iterator i = r.rbegin(); i != r.rend(); ++i)
        rules.push_back(*i);
    }
  }

  return ret;
}

void gen_aux(const Grammar& g, const string& word, list<string>& ret) {
  
  if (!bracketed(word))
    ret.push_back(word);
  else {

    Grammar::const_iterator it = g.find(word);

    if (it == g.end())
      throw logic_error("empty rule");

    const Rule_collection& c = it->second;

    const Rule& r = c[nrand(c.size())];

    for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
      gen_aux(g, *i, ret);
  }
}