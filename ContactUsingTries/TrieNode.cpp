#include "TrieNode.h"

TrieNode::TrieNode() {
	this->isWord = false;
}

bool TrieNode::hasAChildWithChar(char _chr) {
	bool found = false;
	TrieNode* correspondingChild = this->children[_chr];
	if (correspondingChild != nullptr) { found = true; }
	return found;
}

bool TrieNode::hasNoChildren() {
	return this->children.empty();
}

void TrieNode::addWord(std::string _word) {
	if (_word.length() == 0) { return; }
	TrieNode* currChild = this;
	std::string _prefixCache = "";
	for (char _chr : _word) {
		if ( !(currChild->hasAChildWithChar(_chr)) ) {
			// if char is not yet stored, create new child
			currChild->children[_chr] = new TrieNode();
		}		
		_prefixCache += _chr;
		currChild = currChild->children[_chr];
		currChild->prefix = _prefixCache;
	}
	std::cout << "Word added: " << _word << std::endl;
	currChild->isWord = true;
}

bool TrieNode::findWord(std::string _word) {
	bool found = true;
	TrieNode* currNode = this;
	//for (char _chr : _word) {
	for (int idx = 0; idx < _word.length() and found; ++idx) {
		char _chr = _word.at(idx);
		if (currNode->children[_chr] != nullptr) {
			currNode = currNode->children[_chr];
		} else {
			found = false;
		}
	}
	if (found) { found = currNode->isWord; }
	return found;
}

void TrieNode::displayAll() {
	if (this->isWord) { 
		std::cout << this->prefix << std::endl;
		if ( this->hasNoChildren() ) { return; }
	}
	for (auto it = this->children.begin(); it != this->children.end(); ++it) {
		char childChar = it->first;
		TrieNode* childNode = it->second;
		childNode->displayAll();
	}
}