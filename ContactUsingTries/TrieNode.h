#ifndef __NODE_H
#define __NODE_H

#include "Basic.h"
#include <map>

const static bool usePrefix = true;

class TrieNode {
private:
	std::pair <TrieNode*, char> parentNodePair;
	std::map<char, TrieNode*> children;
	bool isWord;
	std::string prefix;	// **IMP: ONLY for debugging/checking. may exhaust memory with scaling

	bool hasAChildWithChar(char _chr);
	bool isLeaf();
	void setParentNode(TrieNode* _parentNode, char _chr);
public:
	void addWord(std::string);
	TrieNode();
	~TrieNode();
	std::pair <TrieNode*, char> getParentNode();
	std::string getPrefix();
	std::pair <bool, TrieNode*> findWord(std::string _word);
	void removeWord(std::string _word);
	void displayAll();
};

std::pair <TrieNode*, char> getParentNodePair(TrieNode *);

#endif