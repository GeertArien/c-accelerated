#include "stdafx.h"
#include "words.h"

#include <string>
#include <map>
#include <istream>
#include <vector>
#include <algorithm>
#include <exception>

#include "numbers.h"

using std::string;    using std::map;
using std::istream;   using std::ostream;
using std::endl;      using std::vector;
using std::find_if;   using std::getline;
using std::logic_error;

istream& count_words(istream& is, ostream& os) {
  string s;
  map<string, int> counters;

  while (is >> s)
    ++counters[s];

  for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it)
    os << it->first << "\t" << it->second << endl;

  return is;
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
    vector<string> entry = split(line);

    if (!entry.empty())
      ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
  }

  return ret;
}

vector<string> gen_sentence(const Grammar& g) {
  vector<string> ret;
  gen_aux(g, "<sentence>", ret);

  return ret;
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret) {
  
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