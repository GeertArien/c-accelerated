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
bool compare_ignore_case(std::string, std::string);

#endif // !GUARD_WORDS_H
