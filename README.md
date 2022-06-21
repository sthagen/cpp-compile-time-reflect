# cpp-compile-time-reflect

Experimental header-only module enabling compile time reflection.

## Usage

Generate the build files:

```console
❯ cmake -S . -B build
# ...
```

Build (in parallel):

```console
❯ cmake --build build --parallel 4
[ 66%] Building CXX object tests/CMakeFiles/reflect_test.dir/sdbm_hash.cpp.o
[ 66%] Building CXX object tests/CMakeFiles/reflect_test.dir/struct_id.cpp.o
[ 66%] Building CXX object examples/CMakeFiles/struct_id.dir/struct_id.cpp.o
[ 66%] Building CXX object tests/CMakeFiles/reflect_test.dir/test.cpp.o
[ 83%] Linking CXX executable struct_id
[ 83%] Built target struct_id
[100%] Linking CXX executable reflect_test
[100%] Built target reflect_test
```

Execute the tests:

```console
❯ build/tests/reflect_test
===============================================================================
All tests passed (6 assertions in 6 test cases)
```

Execute the example:

```console
❯ build/examples/struct_id
Foo --> (version == 3738447584922188735, signture_length == 43)
  Signature == (Foo{size_t const:version;float:f;double:d;})
```

## Status
Experimental

**Note**: The default branch is `default`.
