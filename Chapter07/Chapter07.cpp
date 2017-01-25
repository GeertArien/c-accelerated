// Chapter07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <list>

#include "words.h"
#include "student_info.h"
#include "grade.h"

#include "7_1.h"
#include "7_2.h"
#include "7_3.h"
#include "7_4.h"

using std::map;           using std::cin;
using std::string;        using std::vector;
using std::cout;          using std::endl;
using std::max;           using std::sort;
using std::streamsize;    using std::setprecision;
using std::domain_error;  using std::ifstream;
using std::to_string;     using std::size_t;
using std::list;

int test_generate_sentence(string file) {
  ifstream infile;
  infile.open(file);

  list<string> sentence = gen_sentence(read_grammar(infile));
  list<string>::const_iterator it = sentence.begin();

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

int test_generate_sentence_v2(string file) {
  ifstream infile;
  infile.open(file);

  vector<string> sentence = gen_sentence_v2(read_grammar(infile));
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
  ex7_4();

  return 0;
}

