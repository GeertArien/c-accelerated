#include "stdafx.h"
#include "square.h"
#include <vector>
#include <exception>
#include <iomanip>

using std::vector;      using std::domain_error;
using std::ostream;     using std::endl;
using std::streamsize;  using std::setw;



vector<double> square_double(const unsigned int range) {
  vector<double> squares;
  if (range > squares.max_size())
    throw domain_error("Range argument exceeds vector limit.");

  for (unsigned int i = 0; i < range; i++)
    squares.push_back(i * i);

  return squares;
}



ostream& print_squares(ostream& os, const vector<double>& v) {
  if (os) {
    unsigned digits_i = GetNumberOfDigitss(v.size());
    unsigned digits_v = GetNumberOfDigitss(v.back());

    for (vector<double>::size_type i = 0; i < v.size(); i++) {
      streamsize s_size = os.width();
      os << setw(digits_i) << i << " " << setw(digits_v) << v[i] << endl;
      os.width(s_size);
    }
  }

  return os;
}

unsigned GetNumberOfDigitss(unsigned i)
{
  return i > 0 ? (int)log10((double)i) + 1 : 1;
}
