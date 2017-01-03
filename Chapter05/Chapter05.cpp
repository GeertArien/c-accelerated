// Chapter05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "words.h"
#include "permuted_index.h"

#include <iostream>

using std::cin;     using std::cout;    using std::endl;
using std::string;
using std::vector;

void test_string_split() {
  string s;

  while (getline(cin, s)) {
    vector<string> v = split(s);

    for (vector<string>::size_type i = 0; i != v.size(); ++i)
      cout << v[i] << endl;
  }
}

void test_input_split() {
  string s;
  
  while (cin >> s)
    cout << s << endl;
}

void test_frame() {
  vector<string> v1 = { "one test", "two test", "aye caramba" };
  vector<string> v2 = { "one direction", "mama mia", "mamo testo", "lake district mall" };

  vector<string> vert = vcat(frame(v1), frame(v2));

  vector<string>::const_iterator iter = vert.begin();

  while (iter != vert.end())
    cout << *iter++ << endl;

  vector<string> horz = hcat(frame(v1), frame(v2));

  iter = horz.begin();

  while (iter != horz.end())
    cout << *iter++ << endl;
}

void test_permuted_index() {
  vector<string> v = { "The quick brown fox", "jumped over the fence" };
  vector<string> permuted_v = permuted_index(v);

  vector<string>::const_iterator iter = permuted_v.begin();

  while (iter != permuted_v.end())
    cout << *iter++ << endl;
}

int main()
{
  test_permuted_index();
  return 0;
}

