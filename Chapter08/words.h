#ifndef GUARD_words_H
#define GUARD_words_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

std::istream count_words(std::istream, std::ostream);
std::vector<std::string> split(const std::string&);
std::map<std::string, std::vector<int> > xref(std::istream&, std::vector<std::string> find_words(const std::string&) = split);
bool space(char);
bool not_space(char);
bool bracketed(const std::string&);
Grammar read_grammar(std::istream&);
std::vector<std::string> gen_sentence(const Grammar&);
void gen_aux(const Grammar&, const std::string&, std::vector<std::string>&);

bool not_url_char(char);
std::string::const_iterator url_beg(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator url_end(std::string::const_iterator, std::string::const_iterator);
std::vector<std::string> find_urls(const std::string&);

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