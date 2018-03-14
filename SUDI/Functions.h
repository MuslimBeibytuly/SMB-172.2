#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
//открыть субтитры, словарь юзера и записать не одинаковые
void findDifference();
std::set<std::string> getAllWordsFromSubtitles(std::string);
std::set<std::string> getMyWordsFromDictionary(std::string);
void translate(std::vector<std::string>);
void writeResultsToFile(std::string, std::map<std::string, std::string>);