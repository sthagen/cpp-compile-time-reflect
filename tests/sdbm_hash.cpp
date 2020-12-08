#include "catch.hpp"
#include "../reflect/hash.hpp"

TEST_CASE("SDBM hash of string 42", "[positive]") {
    constexpr const char* const fourtytwo{"42"};
    size_t const hash_of_fourtytwo{sdbm::hash_calculator<sdbm::length(fourtytwo)>::calculate_value(fourtytwo)};
    REQUIRE(hash_of_fourtytwo == 3411198);
}
