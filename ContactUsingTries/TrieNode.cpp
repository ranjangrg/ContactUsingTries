#include "TrieNode.h"

TrieNode::TrieNode() {
	std::pair <TrieNode*, char> _parentNode(nullptr, NULL);
	this->parentNodePair = _parentNode;
	this->isWord = false;
}

TrieNode::~TrieNode() {
	this->children.clear();
}

bool TrieNode::hasAChildWithChar(char _chr) {
	bool found = false;
	TrieNode* correspondingChild = this->children[_chr];
	if (correspondingChild != nullptr) { found = true; }
	return found;
}

// i.e. has no children nodes instantiated yet
bool TrieNode::isLeaf() {
	return this->children.empty();
}

std::pair <TrieNode*, char> TrieNode::getParentNode() {
	return this->parentNodePair;
}

void TrieNode::setParentNode(TrieNode* _parentNode, char _chr) {
	this->parentNodePair.first = _parentNode;
	this->parentNodePair.second = _chr;
}

std::string TrieNode::getPrefix() {
	return this->prefix;
}

void TrieNode::addWord(std::string _word) {
	if (_word.length() == 0) { return; }
	TrieNode* currChild = this;
	std::string _prefixCache = "";
	for (char _chr : _word) {
		if ( !(currChild->hasAChildWithChar(_chr)) ) {
			// if char is not yet stored, create new child
			currChild->children[_chr] = new TrieNode();
			currChild->children[_chr]->setParentNode(currChild, _chr);
		}		
		_prefixCache += _chr;
		currChild = currChild->children[_chr];
		currChild->prefix = _prefixCache;
	}
	std::cout << "Word added: " << _word << std::endl;
	currChild->isWord = true;
}

std::pair <bool, TrieNode*> TrieNode::findWord(std::string _word) {
	bool keepSeaching = true;
	bool found = false;
	TrieNode* nodePtr = nullptr;
	TrieNode* currNode = this;
	//for (char _chr : _word) {
	for (unsigned int idx = 0; idx < _word.length() and keepSeaching; ++idx) {
		char _chr = _word.at(idx);
		if (currNode->children[_chr] != nullptr) {
			currNode = currNode->children[_chr];
		} else {
			keepSeaching = false;
		}
	}
	if (keepSeaching) { found = (currNode->isWord) ? true : false; }
	if (found) {
		nodePtr = currNode;
	}
	std::pair<bool, TrieNode*> results(found, nodePtr);
	return results;
}

// returns the parent node of the arg TrieNode
std::pair <TrieNode*, char> getParentNodePair(TrieNode* _trieNode) {
	std::pair <TrieNode*, char> _parentNodePair = _trieNode->getParentNode();
	return _parentNodePair;
}

void TrieNode::removeWord(std::string _word) {
	TrieNode* currNode = this->findWord(_word).second;
	bool stopNow = false;

	char _parentChar = '\0';
	while ( (currNode != nullptr) && !(stopNow) ) {
		if (currNode->isLeaf()) {
			std::pair <TrieNode*, char> parentNodePair = getParentNodePair(currNode);
			currNode = parentNodePair.first;
			_parentChar = parentNodePair.second;
			currNode->children.erase(_parentChar); // deleting map element / destroy
		}
		else {
			currNode->isWord = false;
			stopNow = true;
		}
	}
	std::cout << "Removed word: " << _word << "\n";
}

// NOTE: uses prefix field from TrieNode class
// Using prefix field might be inefficient while scaling
void TrieNode::displayAll() {
	if (this->isWord) {
		std::cout << this->prefix << std::endl;
		if (this->isLeaf()) { return; }
	}
	for (auto it = this->children.begin(); it != this->children.end(); ++it) {
		char childChar = it->first;
		TrieNode* childNode = it->second;
		if (childNode != nullptr) { childNode->displayAll(); }
	}
}