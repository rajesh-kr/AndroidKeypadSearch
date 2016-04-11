#ifndef TRIE_HPP
#define TRIE_HPP

#include <set>
#include <string>
#include "contact.hpp"
#include "trie_node.hpp"
using std::string;

class Trie {
    private:
        TrieNode* trie; // root node for the trie
        std::set<Contact> soln; // set containing the search result of Contact

    public:
        Trie();
        ~Trie();
        void insert_node(string s, Contact c); // insert the contact specified by position string s
        int find_contacts(string s); // string s is the search string for which we have to find Contact in Trie
};

#endif
