/**
Accelerated C++, Exercise 8-2, 8_2.cpp

Implement the following library algorithms, which we used in Chapter 6 and
described in §6.5/121. Specify what kinds of iterators they require. Try to minimize the
number of distinct iterator operations that each function requires. After you have
finished your implementation, see §B.3/321 to see how well you did.

    equal(b, e, d)                search(b, e, b2, e2)
    find(b, e, t)                 find_if(b, e, p)
    copy(b, e, d)                 remove_copy(b, e, d, t)
    remove_copy_if(b, e, d, p)    remove(b, e, t)
    transform(b, e, d, f)         partition(b, e, p)
    accumulate(b, e, t)

*/

#include "stdafx.h"
#include "8_2.h"

#include <iostream>
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <exception>
using std::domain_error;

#include <iterator>
using std::back_inserter;

template <class In>
string print_vector(In b, In e)
{
  if (b == e)
    throw domain_error("Empty range");

  stringstream ss;

  ss << "[ " << *b++;

  while (b != e)
    ss << ", " << *b++;

  ss << " ]";

  return ss.str();
}

template <class X>
string print_vector(const vector<X>vec)
{
  return print_vector(vec.begin(), vec.end());
}

bool is_40(int x)
{
  return x == 40;
}

int minus_5(int x)
{
  return x - 5;
}

bool divisible_10(int x)
{
  return x % 10 == 0;
}

int ex8_2()
{
  vector<int> vec1 = { 10, 25, 35, 40, 50 };
  vector<int> vec2 = { 10, 27, 35, 40, 50 };
  vector<int> vec3 = { 10, 25, 35, 40, 50 };

  cout << "Is " << print_vector(vec1) << " equal to " << print_vector(vec2)
    << " ? " << algorithms::equal(vec1.begin(), vec1.end(), vec2.begin()) << endl;
  cout << "Is " << print_vector(vec1) << " equal to " << print_vector(vec3)
    << " ? " << algorithms::equal(vec1.begin(), vec1.end(), vec3.begin()) << endl << endl;

  vector<int> vec4 = { 35, 40 };
  cout << "Search " << print_vector(vec4) << " in " << print_vector(vec2) << " => "
    << *algorithms::search(vec2.begin(), vec2.end(), vec4.begin(), vec4.end()) << endl << endl;

  cout << "Find 35 in " << print_vector(vec1) << " => " << *algorithms::find(vec1.begin(), vec1.end(), 35) << endl << endl;

  cout << "Find if 40 in " << print_vector(vec1) << " => " << *algorithms::find_if(vec1.begin(), vec1.end(), is_40) << endl << endl;

  vector<int> vec5 = { 10, 20 };
  cout << "Copy " << print_vector(vec1) << " into " << print_vector(vec5) << " => ";
  algorithms::copy(vec1.begin(), vec1.end(), back_inserter(vec5));
  cout << print_vector(vec5) << endl << endl;

  vector<int> vec6;
  cout << "Copy " << print_vector(vec1) << " and remove 35 " << " => ";
  algorithms::remove_copy(vec1.begin(), vec1.end(), back_inserter(vec6), 35);
  cout << print_vector(vec6) << endl << endl;
  
  vector<int> vec7;
  cout << "Copy " << print_vector(vec1) << " and remove element if equal to 40 " << " => ";
  algorithms::remove_copy_if(vec1.begin(), vec1.end(), back_inserter(vec7), is_40);
  cout << print_vector(vec7) << endl << endl;

  cout << "Remove from " << print_vector(vec5) << " elements not equal to 10 " << " => ";
  cout << print_vector(vec5.begin(), algorithms::remove(vec5.begin(), vec5.end(), 10)) << endl << endl;

  vector<int> vec8;
  cout << "Transform " << print_vector(vec5) << " by detracting 5 from each element " << " => ";
  algorithms::transform(vec5.begin(), vec5.end(), back_inserter(vec8), minus_5);
  cout << print_vector(vec8) << endl << endl;

  cout << "Partition " << print_vector(vec1) << " by condition \" divisible by 10 \"" << " => ";
  algorithms::partition(vec1.begin(), vec1.end(), divisible_10);
  cout << print_vector(vec1) << endl << endl;

  cout << "Add " << print_vector(vec1) << " to 15" << " => " 
    << algorithms::accumulate(vec1.begin(), vec1.end(), 15) << endl << endl;

  return 0;
}