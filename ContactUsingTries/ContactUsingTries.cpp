#include "Main.h"

#define SYMBOL_COUNT 48

std::chrono::high_resolution_clock::time_point getTimeNow() {
    return std::chrono::high_resolution_clock::now();
}

double getTimeDifference(std::chrono::high_resolution_clock::time_point timeAfter, std::chrono::high_resolution_clock::time_point timeBefore) {
    std::chrono::duration<double> timeElapsed = timeAfter - timeBefore;
    return timeElapsed.count();
}

void hr() {
    for (int i = 0; i < SYMBOL_COUNT; ++i) {
        std::cout << '=';
    }
    std::cout << std::endl;
}

// note: the word list file downloaded from:
// https://github.com/dwyl/english-words/blob/master/words.txt
void runTriesTestLargeDataset() {
    hr();
    auto tBefore = getTimeNow();
    std::vector<std::string> contents = readFileInLines("words.txt");
    double readDuration = getTimeDifference(getTimeNow(), tBefore);
    std::cout << "It took " << readDuration << " seconds to read file.\n";

    TrieNode trie;
    std::string searchWord;
    bool searchResult;
    std::string result;

    tBefore = getTimeNow();
    for (std::string word : contents) { 
        trie.addWord(word);
    }
    readDuration = getTimeDifference(getTimeNow(), tBefore);
    std::cout << "It took " << readDuration << " seconds to create Trie.\n";

    while (searchWord.compare("qn") != 0) {
        std::cout << "Enter word to search (type \'qn\' to exit): ";
        std::cin >> searchWord;
        searchResult = trie.findWord(searchWord).first;
        result = (searchResult) ? " found." : " not found.";
        std::cout << searchWord << result << std::endl;
    }
    hr();
}

void runTriesTest() {
    hr();
    TrieNode trie;

    trie.addWord("a");
    trie.addWord("app");
    trie.addWord("apple");
    trie.addWord("apples");
    trie.addWord("application");
    trie.addWord("applications");

    trie.addWord("his");
    trie.addWord("historical");
    trie.addWord("history");
    trie.addWord("history-fanatic");
    trie.addWord("historian");
    trie.addWord("historians");

    trie.addWord("zebra");
    trie.addWord("go");
        
    hr();
    std::string deleteWords[4] = { "abc", "history", "applications", "zebra" };
    for (std::string deleteWord : deleteWords) {
        trie.removeWord(deleteWord);
    }
    hr();
    
    // test strings for search method
    std::string searchWords[14] = {"app", "appl", "appleitini", "histogram", "\0", " app", "a pple", "app e", "zebra", "hist*ry", "Apple", "applE", "history", "applications"};
    for (std::string searchWord : searchWords) {
        std::pair<bool, TrieNode*> results = trie.findWord(searchWord);
        std::string result = (results.first) ? "Found    " : "Not found";
        std::cout << result << ": " << searchWord << std::endl;
    } 

    hr();
    std::cout << "Final Word List " << std::endl;
    hr();
    trie.displayAll();
    hr();
}

int main()
{
    runTriesTestLargeDataset();

    std::cout << "=== FIN ===" << std::endl;

    return 0;
}
