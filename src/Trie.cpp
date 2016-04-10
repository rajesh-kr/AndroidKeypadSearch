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
    for(int i = 0; i < s.length(); i++) {
        if(i == s.length() - 1) {
            curr->term = true;
            curr->contacts.push_back(c);
        }

        int index = s[i] - '0';
        if(curr->numbers[index] == NULL) {
            TrieNode* temp = new TrieNode();
            curr->numbers[index] = temp;
        }
        curr = curr->numbers[index];
    }
}

void Trie::print_t() {
    TrieNode* curr = trie;
    printutil(curr);
}

void Trie::printutil(TrieNode* curr) {
    for(int i = 0; i < 10; i++) {
        if(curr->numbers[i] != NULL) {
            if(curr->term == true) {
                for(std::vector<Contact>::iterator it = curr->contacts.begin(); it != curr->contacts.end(); ++it) {
                    std::cout << it->name << ":" << it->phone << std::endl;
                }
            }
            printutil(curr->numbers[i]);
        }
    }
}
