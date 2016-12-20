// Chapter03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

using std::cin;     using std::setprecision;
using std::cout;    using std::string;
using std::endl;    using std::streamsize;
using std::vector;  using std::sort;

int StudentGradeAverage(double& result, string& name) {
  cout << "Please enter your name: ";
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  cout << "Enter all your homework grades, "
    "followed by end-of-file: ";

  int count = 0;
  double sum = 0;
  double x;

  while (cin >> x) {
    ++count;
    sum += x;
  }

  double homework = count == 0 ? 0 : sum / count;

  result = 0.2 * midterm + 0.4 * final + 0.4 * homework;

  return 0;
}

void OuputGradeAverage(double grade) {
  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
    << grade << setprecision(prec) << endl;
}

int StudentGradeMedian(double& result, string& name) {
  cout << "Please enter your name: ";
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  cout << "Enter all your homework grades, "
    "followed by end-of-file: ";

  double x;
  vector<double> homework;

  while (cin >> x)
    homework.push_back(x);

  typedef vector<double>::size_type vector_size;
  vector_size size = homework.size();

  if (size == 0) {
    cout << endl << "You must enter your grades. "
                    "Please try again." << endl;
    return 1;
  }

  sort(homework.begin(), homework.end());

  vector_size mid = size / 2;
  double median = size % 2 == 0 ? (homework[mid - 1] + homework[mid]) / 2 : homework[mid];

  result = 0.2 * midterm + 0.4 * final + 0.4 * median;
  
  return 0;
}

void OuputGradeMedian(double grade) {
  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
    << grade << setprecision(prec) << endl;
}

int Quartiles(vector<int>& someInts)
{
  sort(someInts.begin(), someInts.end());

  int quarter = someInts.size() / 4;
  int remainder = someInts.size() % 4;

  if (quarter == 0) {
    cout << "Vector is smaller than 4 elements." << endl;
    return 1;
  }
   
  int start = someInts.size();

  for (int i = 0; i < 4; i++, remainder--) {
    std::stringstream result;
    int quarterSize = remainder > 0 ? quarter + 1 : quarter;
    int stop = start - quarterSize;
    vector<int>::const_iterator first = someInts.begin() + stop;
    vector<int>::const_iterator last = someInts.begin() + start;
    std::copy(first, last, std::ostream_iterator<int>(result, " "));
    cout << "Quarter " << std::to_string(i + 1) << ": " + result.str() << endl;
    start -= quarterSize;
  }

  return 0;
}

int CountDistinctWord(vector<string> words) {

  if (words.size() < 2) {
    cout << "Please enter atleast 2 words." << endl;
    return 1;
  }

  sort(words.begin(), words.end());

  for (vector<string>::size_type i = 0, counter = 0; i < words.size(); i++) {
    counter++;
    if (i + 1 == words.size() || words[i] != words[i + 1]) {
      cout << words[i] << ": " << counter << endl;
      counter = 0;
    }
  }

  return 0;
}

int LongestShortestString(vector<string> words) {

  if (words.size() < 1) {
    cout << "Please enter atleast 1 words." << endl;
    return 1;
  }

  vector<string>::size_type shortest, longest;
  shortest = longest = words[0].size();

  for (vector<string>::size_type i = 1; i < words.size(); i++) {
    if (words[i].size() < shortest)
      shortest = words[i].size();
    if (words[i].size() > longest)
      longest = words[i].size();
  }

  cout << "The shortest word is " << shortest << " characters long." << endl
    << "The longest word is " << longest << " characters long." << endl;

  return 0;
}

vector<string> GetInput() {
  string word;
  vector<string> words;

  cout << "Please enter some words:" << endl;

  while (cin >> word) {
    words.push_back(word);
  }
  
  return words;
}

int StudentNamesGrades() {
  vector<string> names;
  vector<double> grades;
  string answer;
  
  do {
    string name;
    double grade;
    if (StudentGradeAverage(grade, name))
      return 1;

    names.push_back(name);
    grades.push_back(grade);

    cout << "Enter (y)es if you want to enter more grades and students: ";
    cin.clear();
    cin >> answer;
    cout << endl;
  } while (answer.at(0) == 'y' || (answer.at(0) == 26 && answer.at(1) == 'y'));

  for (vector<string>::size_type i = 0; i < names.size(); i++) {
    cout << names[i] << ":" << endl;
    OuputGradeAverage(grades[i]);
    cout << endl;
  }

  return 0;
}

int main()
{
  vector<int> someInts = { 10, 12, 5, 8, 13, 25, 1, 121, 85, 99, 120, 180, 75, 205, 16, 22, 99, 16 };
  
  return StudentNamesGrades();
}

