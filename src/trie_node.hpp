#ifndef TRIE_NODE_HPP
#define TRIE_NODE_HPP

#include <vector>
#include "contact.hpp"

struct TrieNode {
    TrieNode* numbers[10];
    bool term;
    std::vector<Contact> contacts;
    TrieNode();
    ~TrieNode();
};

#endif
