#include "../include/NumberStats.hh"
#include "../include/catch2/catch.hh"
#include <vector>

using chapter5::NumberStats;

SCENARIO("Ensures user's first input is lower than the second", "[class]") {
  GIVEN("A lower first input than second input") {
    int input1 = 1;
    int input2 = 10;

    WHEN("The object is created") {
      REQUIRE_NOTHROW(NumberStats(input1, input2));

      THEN("The object's private member variables are assigned without error") {
        NumberStats obj(input1, input2);

        REQUIRE(obj.getFirstNumber() == input1);
        REQUIRE(obj.getSecondNumber() == input2);
        REQUIRE(obj.getFirstNumber() < obj.getSecondNumber());
      }
    }
  }

  GIVEN("A higher first input than second input") {
    int input1 = 100;
    int input2 = 1;

    WHEN("The object is created") {
      REQUIRE(input1 > input2);

      REQUIRE_THROWS(NumberStats(input1, input2));
    }
  }
}