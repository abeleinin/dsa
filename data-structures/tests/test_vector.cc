#include <catch2/catch_test_macros.hpp>

#include "vector.h"

TEST_CASE("Vector Constructor")
{
    Vector<int> vec(10);

    REQUIRE(vec.size() == 10);
}

