/**
Accelerated C++, Exercise 7-5, 7_5.cpp

Reimplement the grammar program using a list as the data structure in which
we build the sentence.
*/

#include "stdafx.h"

#include "7_5.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <iostream>
using std::istream;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <iterator>
using std::back_inserter;

#include <exception>
using std::logic_error;

#include "words.h"
#include "numbers.h"


list<string> split_to_list(const string& str) 
{
  vector<string> ret = split(str);
  list <string> list;
  copy(ret.begin(), ret.end(), back_inserter(list));

  return list;
}

Grammar read_grammar_list(istream& in)
{
  Grammar ret;
  string line;

  while (getline(in, line)) 
  {
    list<string> entry = split_to_list(line);

    if (!entry.empty())
      ret[entry.front()].push_back(Rule(++entry.begin(), entry.end()));
  }

  return ret;
}

void gen_aux(const Grammar& g, const string& word, list<string>& ret)
{

  if (!bracketed(word))
    ret.push_back(word);
  else
  {

    Grammar::const_iterator it = g.find(word);

    if (it == g.end())
      throw logic_error("empty rule");

    const Rule_collection& c = it->second;

    const Rule& r = c[nrand(c.size())];

    for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
      gen_aux(g, *i, ret);
  }
}

list<string> gen_sentence_list(const Grammar& g)
{
  list<string> ret;
  gen_aux(g, "<sentence>", ret);

  return ret;
}


int generate_sentence_list_output(string file)
{
  ifstream infile;
  infile.open(file);

  list<string> sentence = gen_sentence_list(read_grammar_list(infile));
  list<string>::const_iterator it = sentence.begin();

  if (!sentence.empty()) 
  {
    cout << *it;
    ++it;
  }

  while (it != sentence.end()) 
  {
    cout << " " << *it;
    ++it;
  }

  cout << endl;
  return 0;
}

int ex7_5()
{
  return generate_sentence_list_output("grammar.txt");
}
