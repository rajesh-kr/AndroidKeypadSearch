#ifndef TRIE_HPP
#define TRIE_HPP

#include <string>
#include "trie_node.hpp"
#include "contact.hpp"
using std::string;

class Trie {
    private:
        TrieNode* trie;
        void printutil(TrieNode* t);
    public:
        Trie();
        ~Trie();
        void insert_node(string s, Contact c);
        void print_t();
};

#endif
