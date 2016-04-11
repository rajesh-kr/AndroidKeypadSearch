#include <iostream>
#include <fstream>
#include <string>
#include "contact.hpp"
#include "Trie.hpp"
#include "char_to_digit.hpp"
using std::string;

int main() {
    // create CharMap object
    // to convert name to t9 string
    CharMap char_to_digit;

    // create a trie object
    Trie* t = new Trie();

    // read the contact file
    std::ifstream contacts_file("contacts.txt");
    string name, phone;
    string t9_name;

    // for each contact of the file, convert it to t9 format and insert into trie
    while(contacts_file >> name >> phone) {
        t9_name = char_to_digit.convert_str_t9(name);
        Contact con(name, phone);

        // insert the contact in trie
        t->insert_node(t9_name, con);
    }

    // read the user input and search trie object
    int count_c;
    std::cout << "Searching with 46" << std::endl;
    count_c = t->find_contacts("46");
    std::cout << count_c << std::endl;
    std::cout << "Searching with 7" << std::endl;
    count_c = t->find_contacts("7");
    std::cout << count_c << std::endl;

    return 0;
}
