#ifndef TRIE_HPP
#define TRIE_HPP

#include <set>
#include <string>
#include "contact.hpp"
#include "trie_node.hpp"
using std::string;

class Trie {
    private:
        // root node for the trie
        TrieNode* trie;

        // set containing the search result of Contact
        // using set because same contact can be in the trie using first name, last name or phone number
        std::set<Contact> soln;

        // helper functions
        bool is_valid(string& str);
        void contacts_set(TrieNode* curr, std::set<Contact>& soln);

    public:
        Trie();
        ~Trie();

        // insert the contact specified by position string s
        // return true if contact inserted successfully, otherwise false
        bool insert_node(string input, Contact contact);

        // string s is the search string for which we have to find Contact in Trie
        // returns the set containing contacts
        std::set<Contact>& find_contacts(string s); 
};

#endif
