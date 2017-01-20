// Chapter07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "words.h"
#include "student_info.h"
#include "grade.h"

using std::map;           using std::cin;
using std::string;        using std::vector;
using std::cout;          using std::endl;
using std::max;           using std::sort;
using std::streamsize;    using std::setprecision;
using std::domain_error;  using std::ifstream;
using std::to_string;

int test_xref(string file, int line_length) {
  ifstream infile;
  infile.open(file);

  map<string, vector<int> > ret = xref(infile);

  for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
    string s = it->first + " occurs on line(s): ";
    string s_spaces(s.size(), ' ');

    vector<int>::const_iterator line_it = it->second.begin();

    while (line_it != it->second.end()) {
      string nr = to_string(*line_it);
      
      if (line_it != it->second.end() - 1)
        nr += ", ";

      if (s.size() + nr.size() > line_length) {
        cout << s << endl;
        s = s_spaces + nr;
      }
      else {
        s += nr;
      }

      ++line_it;
    }

    cout << s << endl;

    if (s.size() > s_spaces.size())
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

int test_count_words() {
  
  if (count_sort_words(cin, cout))
    return 0;
  else
    return 1;
}

vector<Student_info> test_student_info() {
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  while (read(cin, record)) {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare);

  for (vector<Student_info>::size_type i = 0; i != students.size(); i++) {
    cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

    try {
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec);
    }
    catch (domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }

  return students;
}

int test_student_info_extended() {
  const vector<Student_info> students = test_student_info();
  map<char, int> graded_students;

  for (vector<Student_info>::const_iterator iter = students.begin(); iter != students.end(); ++iter) {
    if (iter->grade >= 90)
      ++graded_students['A'];
    else if (iter->grade >= 80)
      ++graded_students['B'];
    else if (iter->grade >= 70)
      ++graded_students['C'];
    else if (iter->grade >= 60)
      ++graded_students['D'];
    else
      ++graded_students['F'];
  }

  for (map<char, int>::const_iterator iter = graded_students.begin(); iter != graded_students.end(); ++iter) {
    cout << iter->first << " : " << iter->second << " students" << endl;
  }

  return 0;
}

int main()
{
  return test_xref("lines.txt", 50);
}

