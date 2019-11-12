#define BOOST_TEST_MODULE print_ip

#include "print_ip.h"
#include <sstream>
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(print_ip_suite)

BOOST_AUTO_TEST_CASE(integral_tests)
{
    const std::string test_char("255\n");
    const std::string test_short("0.0\n");
    const std::string test_int("127.0.0.1\n");
    const std::string test_long("123.45.67.89.101.112.131.41\n");
    std::ostringstream oss;

    print_ip(char(-1),oss);
	BOOST_CHECK(test_char==oss.str());

    oss.str("");
    print_ip(short(0),oss);
	BOOST_CHECK(test_short==oss.str());

    oss.str("");
    print_ip(int(2130706433),oss);
	BOOST_CHECK(test_int==oss.str());

    oss.str("");
    print_ip(long(8875824491850138409),oss);
	BOOST_CHECK(test_long==oss.str());


}

BOOST_AUTO_TEST_CASE(container_tests)
{   
    const std::string test_vector("230.100.110.0.20\n");
    const std::string test_list("200.90.34.0.201\n");
    std::ostringstream oss;
    print_ip(std::vector{ 230,100,110,0,20 },oss);
    BOOST_CHECK(test_vector==oss.str());

    oss.str("");
	print_ip(std::list{ 200,90,34,0,201 },oss);
	BOOST_CHECK(test_list==oss.str());
}

BOOST_AUTO_TEST_CASE(string_tests) {
    std::ostringstream oss;
    const std::string test_ip{"77.7.0.1.121"};
	print_ip(test_ip,oss);
	BOOST_CHECK(test_ip + '\n' == oss.str());
}

BOOST_AUTO_TEST_CASE(tuple_tests) {
    std::ostringstream oss;
    const std::string test_ip{"168.41.33.10.0\n"};

	print_ip(std::tuple{ 168,41,33,10,0 },oss);
	
	BOOST_CHECK(test_ip == oss.str());
}

BOOST_AUTO_TEST_SUITE_END()