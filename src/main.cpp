#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "contact.hpp"
#include "Trie.hpp"
using std::string;

std::map<char, int> T;

void create_T();
string convert_str_t9(string name) {
    string t = "";
    int len = name.length();
    for(int i = 0; i < len; i++) {
        t = t + std::to_string(T[name[i]]);
    }
    return t;
}

int main() {
    // create a trie object
    Trie t;

    // read the contact file
    create_T();
    std::ifstream contacts_file("contacts.txt");
    string name, phone;
    string t9_name;
    while(contacts_file >> name >> phone) {
        t9_name = convert_str_t9(name);
        Contact con(name, phone);
        t.insert_node(t9_name, con);
        //std::cout << con.name << ":" << t9_name << std::endl;
    }
    std::cout << std::endl;
    std::cout << "printing trie\n";
    t.print_t();
    // for each name of the file, convert it to t9 format and insert into trie
    // read the user input and search trie object
    return 0;
}

void create_T() {
    T['a'] = 2;
    T['b'] = 2;
    T['c'] = 2;
    T['d'] = 3;
    T['e'] = 3;
    T['f'] = 3;
    T['g'] = 4;
    T['h'] = 4;
    T['i'] = 4;
    T['j'] = 5;
    T['k'] = 5;
    T['l'] = 5;
    T['m'] = 6;
    T['n'] = 6;
    T['o'] = 6;
    T['p'] = 7;
    T['q'] = 7;
    T['r'] = 7;
    T['s'] = 7;
    T['t'] = 8;
    T['u'] = 8;
    T['v'] = 8;
    T['w'] = 9;
    T['x'] = 9;
    T['y'] = 9;
    T['z'] = 9;
}
