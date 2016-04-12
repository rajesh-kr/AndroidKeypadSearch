#include "trie.hpp"
#include <iostream>

Trie::Trie() {
    trie = new TrieNode();
}

Trie::~Trie() {
    soln.clear();
    delete trie;
}

bool Trie::is_valid(string& str) {
    int len = str.length();

    for(int i = 0; i < len; ++i) {
        if(str[i] < '0' || str[i] > '9') {
            return false;
        }
    }

    return true;
}

bool Trie::insert_node(string input, Contact contact) {
    TrieNode* curr = trie;
    string s;

    // if phone number starts with '+', ignore that
    if(input[0] == '+') {
        s = input.substr(1);
    }
    else {
        s = input;
    }

    // check if string s contains only digit
    if(!is_valid(s)) {
        return false;
    }

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
    curr->contacts.push_back(contact);

    return true;
}

void Trie::contacts_set(TrieNode* curr, std::set<Contact>& soln) {
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

std::set<Contact>& Trie::find_contacts(string s) {
    soln.clear();
    TrieNode* curr = trie;
    int len = s.length();

    // traverse down the trie till the input
    for(int i = 0; i < len; ++i) {
        int index = s[i] - '0';
        if(index < 0 || index > 9 || curr->numbers[index] == NULL) {
            // either input not in range or
            // reached dead end, no contacts found
            // return from here
            return soln;
        }

        curr = curr->numbers[index];
    }

    // store all the contacts in set
    contacts_set(curr, soln);

    return soln;
}
