#include "../include/NumberStats.hh"
#include "../include/catch2/catch.hpp"
#include <vector>

using namespace chapter5;

SCENARIO("Ensures user's first input is lower than the second", "[class]") {
  GIVEN("A lower first input than second input") {
    int input1 = 87;
    int input2 = 125;

    WHEN("We make calculations") {
      int _desiredSumOfEvens = 2014;
      int _desiredSumOfOddSquares = 227380;

      THEN("The computations are correct") {
        REQUIRE(calcSumOfEvens(input1, input2) == _desiredSumOfEvens);
        REQUIRE(calcSumOfOddSquares(input1, input2) == _desiredSumOfOddSquares);
      }
    }
  }
}
