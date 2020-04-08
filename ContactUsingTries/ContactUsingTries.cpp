#include "Basic.h"
#include "Node.h"

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

    trie.displayAll();

    std::string searchWords[5] = {"app", "appl", "appleitini", "histogram", "\0"};
    for (std::string searchWord : searchWords) {
        std::string result = trie.findWord(searchWord) ? "Found" : "not found";
        std::cout << "'" << searchWord << "' " << result << std::endl;
    }    
}

int main()
{
    std::cout << "Hello World!\n";

    runTriesTest();

    std::cout << "=== FIN ===" << std::endl;
    //std::cout << "\"" << word << "\" count: " << trie.findCount(word, 0) << std::endl;

    return 0;
}
