#ifndef TRIE_HPP
#define TRIE_HPP

#include <set>
#include <string>
#include "contact.hpp"
#include "trie_node.hpp"
using std::string;

class Trie {
    private:
        TrieNode* trie;
        std::set<Contact> soln;
        void printutil(TrieNode* t);
    public:
        Trie();
        ~Trie();
        void insert_node(string s, Contact c);
        int find_contact(string s);
        void print_t();
};

#endif
