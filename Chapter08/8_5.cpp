/**
Accelerated C++, Exercise 8-5, 8_5.cpp

Reimplement the gen_sentence and xref functions from Chapter 7 to use output
iterators rather than writing their output directly to a vector<string> . Test these
new versions by writing programs that attach the output iterator directly to the standard
output, and by storing the results in a list<string> and a vector<string> .
*/

#include "stdafx.h"
#include "8_5.h"

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;

#include <fstream>
using std::ifstream;

#include <map>
using std::map;

#include <iterator>
using std::back_inserter;
using std::ostream_iterator;

#include <exception>
using std::logic_error;

#include <sstream>
using std::stringstream;

#include "words.h"
#include "numbers.h"

template <class Out>
void gen_sentence(const Grammar& g, Out os)
{
  gen_aux(g, "<sentence>", os);
}

template <class Out>
void gen_aux(const Grammar& g, const string& word, Out os)
{
  if (!bracketed(word))
    *os++ = word;
  else
  {
    Grammar::const_iterator it = g.find(word);

    if (it == g.end())
      throw logic_error("empty rule");

    const Rule_collection& c = it->second;

    const Rule& r = c[nrand(c.size())];

    for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
      gen_aux(g, *i, os);
  }
}

int test_generate_sentence()
{
  ifstream infile;
  infile.open("grammar.txt");
  const Grammar grammar = read_grammar(infile);

  vector<string> sentence_vector;
  list<string> sentence_list;

  gen_sentence(grammar, back_inserter(sentence_vector));
  gen_sentence(grammar, back_inserter(sentence_list));
  gen_sentence(grammar, ostream_iterator<string>(cout, " "));

  cout << endl;

  vector<string>::const_iterator itv = sentence_vector.begin();
  if (!sentence_vector.empty())
    cout << *itv++;
  while (itv != sentence_vector.end())
    cout << " " << *itv++;
  cout << endl;
  
  list<string>::const_iterator itl = sentence_list.begin();
  if (!sentence_list.empty())
    cout << *itl++;
  while (itl != sentence_list.end())
    cout << " " << *itl++;
  cout << endl;
  
  return 0;
}

template <class Out>
void xref(istream& in, Out os, vector<string> find_words(const string&) = split)
{
  const map<string, vector<int> > ret = xref(in, find_words);

  for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it)
  {
    stringstream ss;
    ss << it->first << " occurs on line(s): ";

    vector<int>::const_iterator line_it = it->second.begin();
    ss << *line_it++;

    while (line_it != it->second.end())
      ss << ", " << *line_it++;

    *os++ = ss.str();
  }

  in.clear();
  in.seekg(0, std::ios::beg);
}

int test_xref()
{
  ifstream infile;
  infile.open("lines.txt");

  vector<string> xref_vector;
  list<string> xref_list;

  cout << endl;

  xref(infile, back_inserter(xref_vector));
  xref(infile, back_inserter(xref_list));
  xref(infile, ostream_iterator<string>(cout, "\n"));

  cout << endl;

  vector<string>::const_iterator itv = xref_vector.begin();
  if (!xref_vector.empty())
    cout << *itv++;
  while (itv != xref_vector.end())
    cout << endl << *itv++;
  cout << endl << endl;

  list<string>::const_iterator itl = xref_list.begin();
  if (!xref_list.empty())
    cout << *itl++;
  while (itl != xref_list.end())
    cout << endl << *itl++;
  cout << endl;

  return 0;
}


int ex8_5()
{
  test_generate_sentence();
  test_xref();
  return 0;
}