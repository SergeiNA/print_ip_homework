#pragma once

#include <iostream>


template<typename T>
void print_ip_integral(T val) {
	bool is_first = true;
	for (size_t i = sizeof(val); i != 0; --i) {
		if (is_first) {
			is_first = !is_first;
			std::cout << +(*(reinterpret_cast<uint8_t*>(&val) + i - 1));
			continue;
		}
		std::cout << '.' << +(*(reinterpret_cast<uint8_t*>(&val) + i - 1));
	}

	cout << "\n------------\n";
}