#include "trie_node.hpp"

TrieNode::TrieNode() {
    term = false;

    // TODO: replace 10 with some constants
    for(int i = 0; i < 10; ++i) {
        numbers[i] = NULL;
    }
}

TrieNode::~TrieNode() {
    contacts.clear();    
    delete numbers[10]; //TODO
}
