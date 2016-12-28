#ifndef GUARD_word_h
#define GUARD_word_h

#include <vector>
#include <string>

std::istream& read(std::istream&, std::vector<std::string>&);
unsigned count_distinct(std::vector<std::string>);
std::ostream& count_occurence(std::ostream&, std::vector<std::string>);

#endif // !GUARD_word_h
