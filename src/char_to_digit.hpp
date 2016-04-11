#ifndef CHAR_TO_HPP
#define CHAR_TO_HPP

#include <map>
#include <string>

class CharMap {
    private:
        std::map<char, char> T;

    public:
        CharMap();
        ~CharMap();
        std::string convert(std::string s); // method to convert character name to digit
};

#endif
