#ifndef GUARD_word_h
#define GUARD_word_h

#include <vector>
#include <string>

std::istream& read(std::istream&, std::vector<std::string>&);
unsigned count_distinct(const std::vector<std::string>&);
std::ostream& count_occurence(std::ostream&, const std::vector<std::string>&);

#endif // !GUARD_word_h
