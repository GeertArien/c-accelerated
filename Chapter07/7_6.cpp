/**
Accelerated C++, Exercise 7-6, 7_6.cpp

Reimplement the gen_sentence program using two vectors: One will hold the
fully unwound, generated sentence, and the other will hold the rules and will be used as
a stack. Do not use any recursive calls.
*/

#include "stdafx.h"

#include "7_6.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <exception>
using std::logic_error;

#include "words.h"
#include "numbers.h"

vector<string> gen_sentence_vectors(const Grammar& g) 
{
  vector<string> ret;
  vector<string> rules;

  rules.push_back("<sentence>");

  while (!rules.empty()) 
  {

    string segment = rules.back();
    rules.pop_back();

    if (!bracketed(segment))
      ret.push_back(segment);
    else 
    {

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

int generate_sentence_vectors_output(string file) 
{
  ifstream infile;
  infile.open(file);

  vector<string> sentence = gen_sentence_vectors(read_grammar(infile));
  vector<string>::const_iterator it = sentence.begin();

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

int ex7_6() 
{
  return generate_sentence_vectors_output("grammar.txt");
}