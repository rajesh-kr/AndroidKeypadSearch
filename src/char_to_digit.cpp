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
    T['A'] = '2';
    T['B'] = '2';
    T['C'] = '2';
    T['D'] = '3';
    T['E'] = '3';
    T['F'] = '3';
    T['G'] = '4';
    T['H'] = '4';
    T['I'] = '4';
    T['J'] = '5';
    T['K'] = '5';
    T['L'] = '5';
    T['M'] = '6';
    T['N'] = '6';
    T['O'] = '6';
    T['P'] = '7';
    T['Q'] = '7';
    T['R'] = '7';
    T['S'] = '7';
    T['T'] = '8';
    T['U'] = '8';
    T['V'] = '8';
    T['W'] = '9';
    T['X'] = '9';
    T['Y'] = '9';
    T['Z'] = '9';
}

CharMap::~CharMap() {
    T.clear();
}

std::string CharMap::convert(std::string name) {
    std::string t = ""; 
    int len = name.length();

    for(int i = 0; i < len; ++i) {
        if(T[name[i]] != 0) {
            t = t + T[name[i]];
        }
        else {
            t = t + name[i];
        }
    }   

    return t;
}
