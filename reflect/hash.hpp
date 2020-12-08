#pragma once
/*
 SDBM Hash Algorithm
 ===================
 
 From https://api.riot-os.org/group__sys__hashes__sdbm.html:
 """
 This algorithm was created for sdbm (a public-domain reimplementation of ndbm) database library. 
 It was found to do well in scrambling bits, causing better distribution of the keys and fewer splits. 
 It also happens to be a good general hashing function with good distribution.
 The magic constant 65599 was picked out of thin air while experimenting with different constants, and turns out to be a prime. 
 This is one of the algorithms used in berkeley db (see sleepycat) and elsewhere.
 """
 
 The SDBM non-cryptographic hash function is: hash(i) = hash(i - 1) * 65599 + str[i];
 
 Obvious inputs are the constant char pointer to a byte buffer to hash and the length of the buffer pointed to.
 Output is a size_t unsigned integral type in this implementation (well-defined overflow semantics).
*/

namespace sdbm {
using hash_type = size_t;

static constexpr inline hash_type recurrence(hash_type value, hash_type character) { 
    /*
      Reccurrence relation:
          value = value * 65599 + character 
      rewritten as:
          value = (value << 6) + (value << 16) - value + character
    */
    return (value << 6) + (value << 16) - value + character;
}

template <hash_type string_length>
struct hash_calculator {

    static constexpr inline hash_type calculate(const char* const plain_text, hash_type& value) {
        hash_type character = hash_calculator<string_length - 1>::calculate(plain_text, value);
        value = recurrence(value, character);
        return plain_text[string_length - 1];
    }

    static constexpr inline hash_type calculate_value(const char* const plain_text) {
        hash_type value = 0;
        hash_type character = hash_calculator<string_length>::calculate(plain_text, value);
        return recurrence(value, character);
    }
};

template <>
struct hash_calculator<1> {
    static constexpr inline hash_type calculate(const char* const plain_text, size_t& value) {
        return plain_text[0];
    }
};

// Utility Function for Compile-Time String Length
size_t constexpr length(const char* str) { return str ? ( *str ? 1 + length(str + 1) : 0 ) : 0; }

}  // namespace
