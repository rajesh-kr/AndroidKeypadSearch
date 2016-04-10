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
        int index = s[i] - '0';
        if(curr->numbers[index] == NULL) {
            TrieNode* temp = new TrieNode();
            curr->numbers[index] = temp;
        }
        curr = curr->numbers[index];

        if(i == s.length() - 1) {
            curr->term = true;
            curr->contacts.push_back(c);
        }
    }
}

void Trie::print_t() {
    TrieNode* curr = trie;
    printutil(curr);
}

void Trie::printutil(TrieNode* curr) {
    for(int i = 0; i < 10; i++) {
        if(curr->numbers[i] != NULL) {
            std::cout << i;
            printutil(curr->numbers[i]);
        }
    }
}
