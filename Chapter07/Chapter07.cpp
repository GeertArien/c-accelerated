// Chapter07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "words.h"

using std::map;     using std::cin;
using std::string;  using std::vector;
using std::cout;    using std::endl;

int test_xref() {
  
  map<string, vector<int> > ret = xref(cin);

  for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
    cout << it->first << " occurs on line(s): ";

    vector<int>::const_iterator line_it = it->second.begin();
    cout << *line_it;

    ++line_it;

    while (line_it != it->second.end()) {
      cout << ", " << *line_it;
      ++line_it;
    }

    cout << endl;
  }

  return 0;
}

int test_generate_sentence() {
  vector<string> sentence = gen_sentence(read_grammar(cin));
  vector<string>::const_iterator it = sentence.begin();

  if (!sentence.empty()) {
    cout << *it;
    ++it;
  }

  while (it != sentence.end()) {
    cout << " " << *it;
    ++it;
  }

  cout << endl;
  return 0;
}

int main()
{
    return 0;
}

