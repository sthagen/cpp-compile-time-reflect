#include "catch.hpp"
#include "../reflect/hash.hpp"

TEST_CASE("Struct identity compiles and is reproducible", "[positive]") {
  constexpr const char* const FOO_SHAPE{
      "Foo{"
          "size_t const:version;"
          "float:f;"
          "double:d;"
      "}"
  };
  struct Foo {
      sdbm::hash_type const version{sdbm::hash_calculator<sdbm::length(FOO_SHAPE)>::calculate_value(FOO_SHAPE)};
      float f{3.1415f};
      double d{3.1415};
  };
  
  // std::cout << "Foo --> " << Foo{}.version << " " << sdbm::length(FOO_SHAPE) << "\n";
  // Foo --> 3738447584922188735 43
  REQUIRE(Foo{}.version == 3738447584922188735);
}
