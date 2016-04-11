#include "char_to_digit.hpp"

CharMap::CharMap() {
    T['a'] = '2';
    T['b'] = '2';
    T['c'] = '2';
    T['d'] = '3';
    T['e'] = '3';
    T['f'] = '3';
    T['g'] = '4';
    T['h'] = '4';
    T['i'] = '4';
    T['j'] = '5';
    T['k'] = '5';
    T['l'] = '5';
    T['m'] = '6';
    T['n'] = '6';
    T['o'] = '6';
    T['p'] = '7';
    T['q'] = '7';
    T['r'] = '7';
    T['s'] = '7';
    T['t'] = '8';
    T['u'] = '8';
    T['v'] = '8';
    T['w'] = '9';
    T['x'] = '9';
    T['y'] = '9';
    T['z'] = '9';
}

CharMap::~CharMap() {
    T.clear();
}

std::string CharMap::convert_str_t9(std::string name) {
    std::string t = ""; 
    int len = name.length();
    for(int i = 0; i < len; ++i) {
        t = t + T[name[i]];
    }   
    return t;
}
