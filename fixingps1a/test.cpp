// "Copyright 2020 <Greg Kaplowitz>"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>

#include "FibLFSR.hpp"
// using namespace std;
BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {
  LFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);

  LFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(7) == 48);
}

BOOST_AUTO_TEST_CASE(zeroTest) {
  LFSR la("101100");
  BOOST_REQUIRE(la.step() == 0);
  BOOST_REQUIRE(la.step() == 0);
  BOOST_REQUIRE(la.step() == 0);
  BOOST_REQUIRE(la.step() == 0);
  BOOST_REQUIRE(la.step() == 0);
  BOOST_REQUIRE(la.step() == 0);
  BOOST_REQUIRE(la.step() == 0);
  BOOST_REQUIRE(la.step() == 0);

  LFSR l2a("101100");
  BOOST_REQUIRE(l2a.generate(8) == 0);
}

BOOST_AUTO_TEST_CASE(twelveTest) {
  LFSR lb("10110110001101100011100011011");
  BOOST_REQUIRE(lb.step() == 0);
  BOOST_REQUIRE(lb.step() == 0);
  BOOST_REQUIRE(lb.step() == 0);
  BOOST_REQUIRE(lb.step() == 1);
  BOOST_REQUIRE(lb.step() == 1);
  BOOST_REQUIRE(lb.step() == 1);
  BOOST_REQUIRE(lb.step() == 0);
  BOOST_REQUIRE(lb.step() == 0);

  LFSR l2b("10110110001101100011100011011");
  BOOST_REQUIRE(l2b.generate(8) == 56);
}
