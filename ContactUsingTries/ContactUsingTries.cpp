#include "Basic.h"
#include "TrieNode.h"

#define SYMBOL_COUNT 48

void hr() {
    for (int i = 0; i < SYMBOL_COUNT; ++i) {
        std::cout << '=';
    }
    std::cout << std::endl;
}

void runTriesTest() {
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
}

int main()
{
    hr();
    runTriesTest();
    hr();

    std::cout << "=== FIN ===" << std::endl;

    return 0;
}
