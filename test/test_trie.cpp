#include "catch.hpp"
#include "trie.hpp"
#include "contact.hpp"
#include "char_to_digit.hpp"
#include <set>
#include <vector>
#include <string>
#include <iostream>
using std::string;

TEST_CASE("Searching without inserting in trie", "[Test1]") {
    Trie t;
    std::set<Contact> soln = t.find_contacts("4");
    REQUIRE(soln.size() == 0);
}

TEST_CASE("Inserting and Searching in Trie", "[Test2]") {
    Trie t;
    CharMap ch;

    // create a list of contacts
    // array of names
    string names[] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Zeta", "kappa"};
    // corresponding phones
    string phones[] = {"9732143245", "8151834923", "+12620812156", "+918737312371", "08787112219", "4411223355", "5215669191"};
    bool inserted;

    for(int i = 0; i < 7; ++i) {
        Contact contact(names[i], phones[i]);
        inserted = t.insert_node(ch.convert(names[i]), contact);
        REQUIRE(inserted == true);
        inserted = t.insert_node(phones[i], contact);
        REQUIRE(inserted == true);
    }

    SECTION("Adding invalid entry") {
        string name = "Et#a";
        string phone = "0804081234";
        Contact c(name, phone);
        REQUIRE(t.insert_node(ch.convert(name), c) == false);
        // same contact when inserted with phone number will be true
        REQUIRE(t.insert_node(phone, c) == true);
    }

    SECTION("Searching for name or phone not in trie") {
        // searching with number 7
        std::set<Contact> c = t.find_contacts("7");
        REQUIRE(c.size() == 0);
    }

    SECTION("Searching for contact whose name matches") {
        // Searching with number 33, for Delta
        std::set<Contact> c = t.find_contacts("33");
        std::set<Contact> expected;
        Contact cc("Delta", "+918737312371");
        expected.insert(cc);
        REQUIRE(c.size() == 1);
        REQUIRE(c == expected);
    }

    SECTION("Searching for contact whose number matches") {
        // Searching with number 126, for Gamma
        std::set<Contact> c = t.find_contacts("126");
        std::set<Contact> expected;
        Contact cc("Gamma", "+12620812156");
        expected.insert(cc);
        REQUIRE(c.size() == 1);
        REQUIRE(c == expected);
    }

    SECTION("Adding contact with both first and last name") {
        string first = "Theta";
        string second = "Iota";
        string name = first + " " + second;
        string phone = "+46896001311";
        Contact con(name, phone);

        inserted = t.insert_node(ch.convert(first), con); // insert using first name
        REQUIRE(inserted == true);

        inserted = t.insert_node(ch.convert(second), con); // insert using second name
        REQUIRE(inserted == true);

        inserted = t.insert_node(phone, con); //insert the same contact using phone number
        REQUIRE(inserted == true);

        SECTION("Search the contact where first name is matching") {
            std::set<Contact> c = t.find_contacts("84382"); // 84382 for Theta
            std::set<Contact> expected;
            expected.insert(con);

            REQUIRE(c.size() == 1);
            REQUIRE(c == expected);
        }

        SECTION("Search the contact where last name is matching") {
            std::set<Contact> c = t.find_contacts("4682"); // 4682 for Iota
            std::set<Contact> expected;
            expected.insert(con);

            REQUIRE(c.size() == 1);
            REQUIRE(c == expected);
        }

        SECTION("Search the contact where last name and phone both matches") {
            std::set<Contact> c = t.find_contacts("468"); // 468 for Iota, and phone
            std::set<Contact> expected;
            expected.insert(con); // only one instance of contact, as we are using set

            REQUIRE(c.size() == 1);
            REQUIRE(c == expected);
        }

        SECTION("Search for multiple contacts") {
            std::set<Contact> c = t.find_contacts("4"); // 4
            std::set<Contact> expected;

            expected.insert(con);
            Contact c_gamma(names[2], phones[2]);
            expected.insert(c_gamma);

            Contact c_zeta(names[5], phones[5]);
            expected.insert(c_zeta);


            REQUIRE(c.size() == expected.size());
            REQUIRE(c == expected);
        }
    }

    SECTION("Searching for contact where both name and phone number matches") {
        // Searching with number 52, for kappa
        std::set<Contact> c = t.find_contacts("52");
        std::set<Contact> expected;
        Contact cc(names[6], phones[6]);
        expected.insert(cc);
        REQUIRE(c.size() == 1);
        REQUIRE(c == expected);
    }

    SECTION("Searching with special character") {
        std::set<Contact> c = t.find_contacts("*");
        REQUIRE(c.size() == 0);
    }

    SECTION("Searching for contact where name is one character more than contact stored") {
        // Searching with number 93824, for Zeta4
        std::set<Contact> c = t.find_contacts("93824");
        REQUIRE(c.size() == 0);

        // this time searching for zeta
        c = t.find_contacts("9382");
        std::set<Contact> expected;
        Contact cc(names[5], phones[5]);
        expected.insert(cc);
        REQUIRE(c.size() == 1);
        REQUIRE(c == expected);

        SECTION("Adding zeta1 and searching again for zeta") {
            string name = "Zeta1";
            string phone = "+14084226615";
            Contact c_zeta1(name, phone);

            // insert contact in trie
            inserted = t.insert_node(ch.convert(name), c_zeta1);
            REQUIRE(inserted == true);
            inserted = t.insert_node(phone, c_zeta1);
            REQUIRE(inserted == true);

            // now, search for zeta, we will have two contactsl
            expected.insert(c_zeta1);
            c = t.find_contacts("9382");

            REQUIRE(c.size() == expected.size());
        }
    }
}
