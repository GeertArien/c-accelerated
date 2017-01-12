#ifndef GUARD_words_h
#define GUARD_words_h

#include <vector>
#include <string>

bool space(char);
bool not_space(char);
bool not_url_char(char);
std::vector<std::string> split(const std::string&);
bool is_palindrome(const std::string&);
std::string::const_iterator url_beg(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator url_end(std::string::const_iterator, std::string::const_iterator);
std::vector<std::string> find_urls(const std::string&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::vector<std::string> hcat(const std::vector<std::string>&, const std::vector<std::string>&);
std::string::size_type width(const std::vector<std::string>&);

#endif // !GUARD_words_h
