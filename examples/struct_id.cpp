#include <iostream>
#include "../reflect/hash.hpp"

constexpr const char* const FOO_SHAPE{
    "Foo{"
        "size_t const:version;"
        "float:f;"
        "double:d;"
    "}"
};
struct Foo {
    size_t const version{sdbm::hash_calculator<sdbm::length(FOO_SHAPE)>::calculate_value(FOO_SHAPE)};
    float f{3.1415f};
    double d{3.1415};
};

int main() {
    std::cout << "Foo --> (version == " << Foo{}.version << ", signture_length == " << sdbm::length(FOO_SHAPE) << ")\n";
    std::cout << "  Signature == (" << FOO_SHAPE << ")\n";
    // Expected output:
    // Foo --> (version == 3738447584922188735, signture_length == 43)
    //   Signature == (Foo{size_t const:version;float:f;double:d;})
    return 0;
}
