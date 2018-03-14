#include "Functions.h"


void findDifference()
{
	std::ifstream files("files.txt");
	//s - .srt file, d - .txt file
	std::string s, d;
	files >> s >> d;
	//открываютс€ два файла
	std::ifstream dictionary(d);
	std::vector<std::string> mywords, unknownwords;
	//заполн€ем вектор моих слов из словар€
	std::string word;
	while (dictionary >> word)
	{
		mywords.push_back(word);
	}
	std::set<std::string> allwords(getSubtitles(s));
	for (auto i : allwords) 
	{
		bool isInMyWords = false;
		for (auto j : mywords) 
		{
			if (i == j) 
			{
				isInMyWords = true;
				break;
			}
		}
		if (!isInMyWords) 
		{
			unknownwords.push_back(i);
		}
	}
	for (auto i : unknownwords) 
	{
		std::cout << i << std::endl;
	}
}

//заполн€ем сет всех слов из субтитров
std::set<std::string> getSubtitles(std::string s)
{
	std::ifstream subtitles(s);
	std::set<std::string> words;
	std::string temp;
	while (subtitles >> temp)
	{
		if (!isdigit(temp[0]) && temp[0] != '-') 
		{
			while (!temp.empty() && !isalpha(temp[temp.length() - 1]))
			{
				temp.erase(temp.end() - 1);
			}
			words.insert(temp);
		}
	}
	return words;
}

void translate()
{
}
