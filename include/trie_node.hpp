#ifndef TRIE_NODE_HPP
#define TRIE_NODE_HPP

#include <vector>
#include "contact.hpp"

struct TrieNode {
    bool term; // bool to mark the end node
    TrieNode* numbers[10]; // TODO: define 10 as constant and use here
    std::vector<Contact> contacts; // vector or contacts

    TrieNode();  // Constructor
    ~TrieNode(); // Destructor
};

#endif
