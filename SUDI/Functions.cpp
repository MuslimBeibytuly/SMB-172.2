#include "Functions.h"


void findDifference()
{
	std::ifstream files("files.txt");
	//s - .srt file, d - .txt file
	std::string s, d;
	files >> s >> d;
	std::set<std::string> allwords(getAllWordsFromSubtitles(s)), mywords(getMyWordsFromDictionary(s));
	std::vector<std::string> unknownwords;
	for (std::string i : allwords)
	{
		bool isInMyWords = false;
		for (std::string j : mywords) 
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
	for (std::string i : unknownwords)
	{
		std::cout << i << std::endl;
	}
}

//��������� ��� ���� ���� �� ���������
std::set<std::string> getAllWordsFromSubtitles(std::string s)
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

//��������� ��� ���� ���� �� �������
std::set<std::string> getMyWordsFromDictionary(std::string d)
{
	std::ifstream dictionary(d);
	std::string word;
	std::set<std::string> words;
	while (dictionary >> word)
	{
		words.insert(word);
	}
	return words;
}

void translate(std::vector<std::string> words)
{
}

void writeResultsToFile(std::string, std::map<std::string, std::string>)
{
}
