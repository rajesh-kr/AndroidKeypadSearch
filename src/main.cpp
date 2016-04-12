#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "contact.hpp"
#include "trie.hpp"
#include "char_to_digit.hpp"
using std::string;

int main() {
    // create CharMap object
    // to convert name to t9 string
    CharMap char_to_digit;

    // create a trie object
    Trie t;

    // read the contact file
    std::ifstream contacts_file("contacts.txt");
    string name, phone;
    string digit_name;

    // for each contact of the file, convert it to t9 format and insert into trie
    while(contacts_file >> name >> phone) {
        digit_name = char_to_digit.convert(name);
        Contact contact(name, phone);

        // insert the contact in trie
        t.insert_node(digit_name, contact);
        t.insert_node(phone, contact);
    }

    string f_name = "Kumar";
    string l_name = "Gaurav";
    string t1_n = char_to_digit.convert(f_name);
    string t2_n = char_to_digit.convert(l_name);
    string ph = "973334433";
    Contact cont(f_name + " " + l_name, ph);
    t.insert_node(t1_n, cont);
    t.insert_node(t2_n, cont);
    t.insert_node(ph, cont);


    // read the user input and search trie object
    std::set<Contact> count_c;

    std::cout << "Searching with 4" << std::endl;
    count_c = t.find_contacts("4");
    std::cout << count_c.size() << std::endl;

    std::cout << "Searching with 1" << std::endl;
    count_c = t.find_contacts("1");
    std::cout << count_c.size() << std::endl;

    std::cout << "Searching with 7" << std::endl;
    count_c = t.find_contacts("7");
    std::cout << count_c.size() << std::endl;

    std::cout << "Searching with 9" << std::endl;
    count_c = t.find_contacts("9");
    std::cout << count_c.size() << std::endl;

    std::cout << "Searching with #" << std::endl;
    count_c = t.find_contacts("#");
    std::cout << count_c.size() << std::endl;

    return 0;
}
