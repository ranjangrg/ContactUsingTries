#ifndef __NODE_H
#define __NODE_H

#include "Basic.h"
#include <map>

const static bool usePrefix = true;

class TrieNode {
private:
	std::map<char, TrieNode*> children;
	bool isWord;
	std::string prefix;	// **IMP: ONLY for debugging/checking. may exhaust memory with scaling
	bool hasAChildWithChar(char _chr);
	bool hasNoChildren();
public:
	void addWord(std::string);
	TrieNode();
	bool findWord(std::string _word);
	void displayAll();
};

#endif