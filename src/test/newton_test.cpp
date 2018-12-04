// define the module name (will be shown in test output)
#define BOOST_TEST_MODULE "NewtonTest"
// now include unit_test.hpp for header only testing
#include <boost/test/included/unit_test.hpp>
// For header-only usage of the boost test framework
// see https://www.boost.org/doc/libs/1_64_0/libs/test/doc/html/boost_test/usage_variants.html#boost_test.usage_variants.single_header

// class to be tested
#include <newton.h>

void create_find_root_test(Function f, Function df, double x0, double expected) {
  Newton newton;
  double x = newton.find_root(f, df, x0, 100, 1e-12);

  BOOST_CHECK_MESSAGE(std::abs(x - expected) < 1e-12, "Expected root not found. Expected x ~ " + std::to_string(expected) + ", got " + std::to_string(x));
}

// ------------- TEST CASES --------------

BOOST_AUTO_TEST_CASE( find_root, * boost::unit_test::timeout(1 /*seconds*/) )
{

  create_find_root_test([](double x) -> double { return x;}, [](double x) -> double { return 1;}, 1, 0);
  create_find_root_test([](double x) -> double { return x + 1;}, [](double x) -> double { return 1;}, 1, -1);
  
  // non converging case
  try {
    create_find_root_test([](double x) -> double { return 1;}, [](double x) -> double { return 0;}, 1, 0);
    BOOST_FAIL("Must throw an exception since a root cannot be found.");
  } catch (const std::runtime_error& ex) {
    // TODO check whether exception matches etc.
    std::cerr << ex.what() << std::endl;
  }

}