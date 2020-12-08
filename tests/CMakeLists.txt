# add catch
if(NOT EXISTS ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp)
    file(DOWNLOAD https://github.com/catchorg/Catch2/releases/download/v2.13.3/catch.hpp
            ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp)
endif()

set(tests
    sdbm_hash.cpp
    struct_id.cpp)

add_executable(reflect_test test.cpp ${tests})
target_include_directories(reflect_test PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(reflect_test PROPERTIES CXX_STANDARD 17)

enable_testing()
add_test(NAME test COMMAND reflect_test)
