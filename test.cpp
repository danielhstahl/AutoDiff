#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "AutoDiff.h"


TEST_CASE("Test polynomial", "[Functional]"){
    AutoDiff<double> myAutoDiff(5.0, 1.0);
    auto mySquare=[&](const auto& myX){
        return myX*myX;
    };
    auto myResult=mySquare(myAutoDiff);


    REQUIRE(myResult.getStandard()==Approx(25.0));
    REQUIRE(myResult.getDual()==Approx(10.0));
}
TEST_CASE("Test exponential", "[Functional]"){
    AutoDiff<double> myAutoDiff(5.0, 1.0);
    auto myExp=[&](const auto& myX){
        return exp(myX);
    };
    auto myResult=myExp(myAutoDiff);


    REQUIRE(myResult.getStandard()==Approx(exp(5.0)));
    REQUIRE(myResult.getDual()==Approx(exp(5.0)));
}