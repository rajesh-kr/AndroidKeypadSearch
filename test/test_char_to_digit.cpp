#include "catch.hpp"
#include "char_to_digit.hpp"
using std::string;

TEST_CASE("Testing char to digit", "test1") {
    CharMap ch; 
    REQUIRE(ch.convert("") == "");
    REQUIRE(ch.convert("rajesh") == "725374");
    REQUIRE(ch.convert("rajesh1") == "7253741");
    REQUIRE(ch.convert("raje$h") == "7253$4");
}
