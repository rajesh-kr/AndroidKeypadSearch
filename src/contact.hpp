#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
using std::string;

struct Contact {
    string name;
    string phone;
    Contact(string n, string p);
};

#endif
