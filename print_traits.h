/**
 * @file print_traits.h
 * @author Nikitin S.A (https://github.com/SergeiNA)
 * @brief  type_traits uilities for print_ip  
 * @version 0.1
 * @date 2019-11-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once

#include <list>
#include <string>
#include <tuple>
#include <vector>


///is_all_same
template<typename... Args>
struct is_all_same {};

//cicular inheritance error why only on ubuntu ???
//template<typename T,typename... Args> 
//struct is_all_same<T, Args...> :is_all_same<T, Args...> {};

template<typename T>
struct is_all_same<T> : std::true_type {};

template<typename T, typename...Args>
struct is_all_same<T, T, Args...> : is_all_same<T, Args...> {};

template <typename T, typename U, typename...Args>
struct is_all_same<T, U, Args...> : std::false_type {};

template<typename... T>
constexpr bool is_all_same_v = is_all_same<T...>::value;


///Is container type_traits
template<class T> struct is_container : public std::false_type {};

template<class T>
struct is_container<std::vector<T>> : public std::true_type {};

template<class T>
struct is_container<std::list<T>> : public std::true_type {};

template<typename T>
constexpr bool is_container_v = is_container<T>::value;

///Is tuple type_traits
template<typename... T> struct is_tuple : public std::false_type {};

template<typename... T>
struct is_tuple<std::tuple<T...>> : public std::true_type {};

template<typename... T>
constexpr bool is_tuple_v = is_tuple<T...>::value;

///Is string type_traits
template <typename T, typename = void>
struct is_string : public std::false_type {};

template <class T>
struct is_string<std::basic_string<T, std::char_traits<T>, std::allocator<T>>, void> : public std::true_type {};

template<typename T>
constexpr bool is_string_v = is_string<T>::value;