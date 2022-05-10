// WordCount.cpp
#include <ctype.h>
#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(const std::string & word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int retTotal = 0;
	for (auto & v : table) {
		//std::cout << "checking external vector..." << std::endl;
		for (auto & i : v) {
//			std::cout << "checking internal vector..." << std::endl;
			retTotal += i.second;
		}
	}
	return retTotal;
}

int WordCount::getNumUniqueWords() const {
	int retUnique = 0;
	for (auto & v : table) {
		//std::cout << "checking external vector..." << std::endl;
		retUnique += v.size();
	}
	return retUnique;
}

int WordCount::getWordCount(const std::string & word) const {
	size_t srchInd = hash(makeValidWord(word));
	for (auto & x : table[srchInd]) {
		//std::cout << "checking external vector..." << std::endl;
		if (x.first == makeValidWord(word)) {
			return x.second;
		}
	}
	return 0;
}
	
int WordCount::incrWordCount(const std::string & word) {
	if (makeValidWord(word).length() == 0) {
		return 0;
	}
	size_t incInd = hash(makeValidWord(word));
//	std::cout << "HASHING ORIG WORD: " << word << ", NEW WORD: " << makeValidWord(word) << ". NOW, INDEX IS: " << incInd << "\n\n";
	for (auto & x : table[incInd]) {
//		std::cout << "intvect check, string is: " << x.first << ", and count is: " << x.second << std::endl;
		if (x.first == makeValidWord(word)) {
			x.second += 1;
//			std::cout << "THE WORD " << word << " ALREADY FOUND, AS " << makeValidWord(word) << std::endl;
			return x.second;
		}
	}
	std::pair<std::string, int> toAdd(makeValidWord(word), 1);
	table[incInd].push_back(toAdd);
//	std::cout << "vfront is: " << table[incInd].front().first << std::endl;
	return 1;
}

int WordCount::decrWordCount(const std::string & word) {
	size_t decInd = hash(makeValidWord(word));
	if (getWordCount(word) == 0) {
		return -1;
	}
	int deleteIndex = 0;
	for (size_t i = 0; i < table[decInd].size(); i++) {
		if ((table[decInd])[i].first == makeValidWord(word)) {
			if ((table[decInd])[i].second > 1) {
				(table[decInd])[i].second -= 1;
				return (table[decInd])[i].second;
			}
			deleteIndex = i;
		}
	}
	table[decInd].erase(table[decInd].begin()+deleteIndex);
	return 0;
}

bool WordCount::isWordChar(char c) { //I don't really use this method
	return isalpha(c);
}

std::string WordCount::makeValidWord(const std::string & word) {
	std::string retStr = "";
	bool foundStart = false;
	for (size_t i = 0; i < word.length(); i++) {
		if (foundStart) {
	 		if (!isalpha(word[i]) && word[i] != '\'' && word[i] != '-') {
				continue;
			} else {
				retStr += tolower(word[i]);
			}
		} else {
			if (isalpha(word[i])) {
				retStr += tolower(word[i]);
				foundStart = true;
			}
		}	
	}
	while (!isalpha(retStr[retStr.length()-1]) && retStr.length()>0) {
		retStr.erase(retStr.length()-1, 1);
	}
	return retStr;
}

//THESE ARE COMPARATOR FUNCS USED IN THE DUMP METHODS THAT FOLLOW
bool compareByCount(std::pair<std::string, int> a, std::pair<std::string, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

bool compareByLexico(std::pair<std::string, int> a, std::pair<std::string, int> b) {
	return a.first > b.first;
}





void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	std::vector<std::pair<std::string, int>> toDump;
	for (auto & v : table) {
                for (auto & toAdd : v) {
			toDump.push_back(toAdd);
		}
        }
	std::sort(toDump.begin(), toDump.end(), compareByLexico);
	
	for (auto & elm : toDump) {
		out << elm.first << "," << elm.second << std::endl;
	}
}




void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	std::vector<std::pair<std::string, int>> toDump;
	for (auto & v : table) {
		for (auto & toAdd : v) {
			toDump.push_back(toAdd);
		}
	}
	std::sort(toDump.begin(), toDump.end(), compareByCount);

	for (auto & elm : toDump) {
		out << elm.first << "," << elm.second << std::endl;
	}
}

void WordCount::addAllWords(const std::string& text) {
	//the following snippet of code is adapted from KillzoneKid's answer from
	//https://stackoverflow.com/questions/49201654/splitting-a-string-with-multiple-delimiters-in-c
	//as a much cleaner alternative to splitting a string via multiple delimiters than
	//the idea I originally had, which was to split it manually with a loop and a collector.	
	std::string splitters = " \n\t";
	size_t startInd = 0;
	size_t curInd = 0;
	while ((startInd = text.find_first_not_of(splitters, curInd)) != std::string::npos) {
		curInd = text.find_first_of(splitters, startInd + 1);
		this->incrWordCount(text.substr(startInd, curInd - startInd));
	}
}


	
	
	
	
	
	
