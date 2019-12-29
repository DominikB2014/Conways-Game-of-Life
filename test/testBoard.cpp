#include "catch.h"
#include "GameBoard.h"

TEST_CASE("test for"){

    std::vector<bool> emptyRow5{false, false, false, false, false};
    Grid grid;
    grid.push_back(emptyRow5);
    grid.push_back(emptyRow5);
    grid.push_back(emptyRow5);
    grid.push_back(emptyRow5);
    grid.push_back(emptyRow5);
    grid.push_back(emptyRow5);

    SECTION("TEST 1"){
        REQUIRE(1 == 1);
    }


}
