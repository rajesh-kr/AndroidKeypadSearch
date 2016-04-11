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
        std::string convert_str_t9(std::string s);
};

#endif
