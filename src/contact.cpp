#include "contact.hpp"

Contact::Contact(string n, string p) {
    name = n;
    phone = p;
}

// for adding contact to set
bool Contact::operator< (const Contact& c) const {
    if(name.compare(c.name) == 0 && phone.compare(c.phone) == 0) {
        return false;
    }
    
    return true;
}
