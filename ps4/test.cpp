// "Copyright [2020] <Copyright Owner>"  [legal/copyright]
#include <iostream>
#include <string>

#include "RingBuffer.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

using namespace std;
BOOST_AUTO_TEST_CASE(with_queue_runtime_error) {
  RingBuffer buffer(10);
  for (int i = 0; i < 10; i++) {
  buffer.enqueue(1);
}
  BOOST_REQUIRE_THROW(buffer.enqueue(1), runtime_error);
}

BOOST_AUTO_TEST_CASE(constructor_fail) {
  BOOST_REQUIRE_THROW(RingBuffer buff(0), invalid_argument);
  BOOST_REQUIRE_THROW(RingBuffer biff(-1), invalid_argument);
}

BOOST_AUTO_TEST_CASE(constructor_pass) {
  BOOST_REQUIRE_NO_THROW(RingBuffer buff(1));
  BOOST_REQUIRE_NO_THROW(RingBuffer biff(100));
}

BOOST_AUTO_TEST_CASE(twelveTest) {
  RingBuffer buffer(10);
  BOOST_REQUIRE_THROW(buffer.dequeue(), runtime_error);
}

