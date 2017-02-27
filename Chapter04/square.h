#ifndef GUARD_square_h
#define GUARD_square_h

#include <vector>
#include <iostream>

std::vector<int> square(const unsigned int range);
std::vector<double> square_double(const unsigned int range);
std::ostream& print_squares(std::ostream&, const std::vector<int>&);
std::ostream& print_squares(std::ostream&, const std::vector<double>&);
unsigned GetNumberOfDigitss(unsigned);

#endif // !GUARD_square_h

