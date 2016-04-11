#include "trie.hpp"
#include <iostream>

Trie::Trie() {
    trie = new TrieNode();
}

Trie::~Trie() {
    soln.clear();
    delete trie;
}

void Trie::insert_node(string s, Contact c) {
    TrieNode* curr = trie;
    int len = s.length();

    // traverse using string s,
    // create nodes if they don't exist
    for(int i = 0; i < len; ++i) {
        int index = s[i] - '0';
        if(curr->numbers[index] == NULL) {
            TrieNode* temp = new TrieNode();
            curr->numbers[index] = temp;
        }
        curr = curr->numbers[index];
    }

    // insert the contact at the bottom node
    curr->term = true;
    curr->contacts.push_back(c);
}

// print the Contacts to STDOUT
void print_set(std::set<Contact>& soln) {
    for(std::set<Contact>::iterator it = soln.begin(); it != soln.end(); ++it) {
        std::cout << it->name << ":" << it->phone << std::endl;
    }
}

void contacts_set(TrieNode* curr, std::set<Contact>& soln) {
    // if this node contains Contact, put in the set
    if(curr->term == true) {
        for(std::vector<Contact>::iterator it = curr->contacts.begin(); it != curr->contacts.end(); ++it) {
            soln.insert(*it);
        }
    }

    // TODO: Replace 10 with constant
    for(int i = 0; i < 10; ++i) {
        if(curr->numbers[i] != NULL) {
            contacts_set(curr->numbers[i], soln);
        }
    }
}

int Trie::find_contacts(string s) {
    soln.clear();
    TrieNode* curr = trie;
    int len = s.length();

    // traverse down the trie till the input
    for(int i = 0; i < len; ++i) {
        int index = s[i] - '0';

        if(curr->numbers[index] == NULL) {
            // reached dead end, no contacts found
            // return from here
            return soln.size();
        }

        curr = curr->numbers[index];
    }

    // store all the contacts in set
    contacts_set(curr, soln);

    // print the contacts to STDOUT
    print_set(soln);

    return soln.size();
}
