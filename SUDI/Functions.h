#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <set>
//открыть субтитры, словарь юзера и записать не одинаковые
void findDifference();
std::set<std::string> getSubtitles(std::string);
void translate();