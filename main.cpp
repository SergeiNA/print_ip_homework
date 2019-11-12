/**
 * @file main.cpp
 * @author Nikitin S.A (https://github.com/SergeiNA)
 * @brief Example of appling function print_ip for different types of data
 * @version 0.1
 * @date 2019-11-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "print_ip.h"

using namespace std;

int main()
{
	/**
	 * @brief Examples
	 * 
	 * -integral types: char/short/long
	 * -containers: list/vector
	 * -string
	 * -tuple
	 */
    print_ip(char(-1));
    print_ip(short(0));
    print_ip(int(2130706433));
    print_ip(long(8875824491850138409));
	print_ip(string("123.23.01.200"));
	print_ip(vector{ 123,4,3,40,20 });
	print_ip(list{ 200,40,3,0,20 });
	print_ip(tuple{ 200,40,3,0,20 });
	/**
	 * @brief NOTE! tuple should consist of same types
	 * 
	 *  print_ip(tuple{ 200,40.0 (double),3,0,20 }) won't compile
	 */
}
