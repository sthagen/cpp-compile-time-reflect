#include "catch.hpp"
#include "../reflect/hash.hpp"

TEST_CASE("SDBM hash of string 42", "[positive]") {
    constexpr const char* const fourtytwo{"42"};
    sdbm::hash_type const hash_of_fourtytwo{sdbm::hash_calculator<sdbm::length(fourtytwo)>::calculate_value(fourtytwo)};
    REQUIRE(hash_of_fourtytwo == 3411198);
}

TEST_CASE("SDBM hashes of different strings are different", "[positive]") {
    constexpr const char* const a{"a"}, b{"b"};
    sdbm::hash_type const hash_of_a{sdbm::hash_calculator<sdbm::length(a)>::calculate_value(a)};
    sdbm::hash_type const hash_of_b{sdbm::hash_calculator<sdbm::length(b)>::calculate_value(b)};
    REQUIRE(hash_of_a != hash_of_b);
}

TEST_CASE("Length helper function yields 0 on nullptr", "[positive]") {
    constexpr const char* const empty{nullptr};
    REQUIRE(sdbm::length(empty) == 0);
}

TEST_CASE("Length helper function yields 13 for const char * with 13 characters", "[positive]") {
    constexpr const char* const wild_thirteen{"1234567890123"};
    REQUIRE(sdbm::length(wild_thirteen) == 13);
}
