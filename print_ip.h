/**
 * @file print_ip.h
 * @author Nikitin S.A (https://github.com/SergeiNA)
 * @brief Definition of template print_id function
 * @version 0.1
 * @date 2019-11-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once
#include <iostream>

#include "print_traits.h"

/**
 * @brief class Separator
 * 
 * test descr
 * 
 */
struct Separator
{
	Separator(char ch) :separator(ch), is_first(true){}
	char separator;
	mutable bool is_first;
};

std::ostream& operator << (std::ostream& os, const Separator& sp) {
	if (sp.is_first) {
		sp.is_first = !sp.is_first;
		return os;
	}
	return os << sp.separator;
}

/// Print tuple
template <size_t> struct int_t {};

template <class Tuple, size_t N>
void printTuple(const Tuple& val, int_t<N>, std::ostream& os = std::cout) {
	printTuple(val, int_t<N - 1>(), os);
	os << '.' << std::get<N - 1>(val);
}

template<class Tuple>
void printTuple(const Tuple& val, int_t<1>, std::ostream& os) {
	os << std::get<0>(val);
}


/// Template specialization for integral types
template<class T>
typename std::enable_if<std::is_integral_v<T>, void>::type
 print_ip(const T& val, std::ostream& os = std::cout) {
	T t_val = val;
	Separator sp('.');
	for (size_t i = sizeof(val); i != 0; --i) 
		os << sp << +(*(reinterpret_cast<uint8_t*>(&t_val) + i - 1));
	os << std::endl;
}
/// Template specialization for container types
template<class T>
typename std::enable_if<is_container_v<T>, void>::type
print_ip(const T& val, std::ostream& os = std::cout) {
	Separator sp('.');
	for (const auto& v : val) 
		os << sp << v;
	os << std::endl;
}
/// Template specialization for string
template <class T>
typename std::enable_if<is_string_v<T>, void>::type
print_ip(const T& val, std::ostream& os = std::cout) {
	os << val << std::endl;
}

/// Template specialization for tuple
template <class... T>
typename std::enable_if<is_all_same_v<T...>, void>::type
print_ip(const std::tuple<T...> val, std::ostream& os = std::cout) {
	printTuple(val,int_t<sizeof... (T)>(),os);
	os << std::endl;
}

