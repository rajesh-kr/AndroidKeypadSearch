#include "trie.hpp"
#include <iostream>

Trie::Trie() {
    trie = new TrieNode();
}

Trie::~Trie() {
    delete trie;
}

void Trie::insert_node(string s, Contact c) {
    TrieNode* curr = trie;
    int len = s.length();
    for(int i = 0; i < len; ++i) {
        int index = s[i] - '0';
        if(curr->numbers[index] == NULL) {
            TrieNode* temp = new TrieNode();
            curr->numbers[index] = temp;
        }
        curr = curr->numbers[index];
    }

    curr->term = true;
    curr->contacts.push_back(c);
}

void Trie::print_t() {
    TrieNode* curr = trie;
    printutil(curr);
}

void Trie::printutil(TrieNode* curr) {
    if(curr->term == true) {
        for(std::vector<Contact>::iterator it = curr->contacts.begin(); it != curr->contacts.end(); ++it) {
            std::cout << it->name << ":" << it->phone << std::endl;
        }
    }
    for(int i = 0; i < 10; ++i) {
        if(curr->numbers[i] != NULL) {
            printutil(curr->numbers[i]);
        }
    }
}

int Trie::find_contacts(string s) {
    TrieNode* curr = trie;
    soln.clear();

    int len = s.length();
    for(int i = 0; i < len; ++i) {
        int index = s[i] - '0';
        if(curr->numbers[index] == NULL) {
            break;
        }
        curr = curr->numbers[index];
    }

    printutil(curr);

    return soln.size();
}
