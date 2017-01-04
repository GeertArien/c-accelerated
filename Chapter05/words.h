#ifndef GUARD_WORDS_H
#define GUARD_WORDS_H

#include <vector>
#include <string>
#include <iostream>
#include <list>

std::vector<std::string> split(const std::string&);
std::string::size_type width(const std::vector<std::string>&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::vector<std::string> vcat(const std::vector<std::string>&, const std::vector<std::string>&);
std::vector<std::string> hcat(const std::vector<std::string>&, const std::vector<std::string>&);
std::vector<std::string> center(const std::vector<std::string>&);
bool compare_ignore_case(std::string, std::string);
std::ostream& write_lower_upper(std::ostream&, const std::vector<std::string>&);
bool is_palindrome(const std::string&);
std::vector<std::string> get_palindromes(const std::vector<std::string>&);
std::ostream& write_palindromes(std::ostream& os, const std::vector<std::string>&);
bool has_asc_desc(const std::string&);
std::list<std::string> extract_asc_desc(std::list<std::string>&);
std::string longest_not_asc_desc(std::list<std::string>);

#endif // !GUARD_WORDS_H
