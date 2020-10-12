#include "vector.hpp"
#include <iostream>
#include <vector>
#include "test.h"

int main()
{
	std::cout << "\033[1;32mft::vector\033[0m\n";
	{
		ft::vector<int> vec(8, 666);
		ft::vector<int> vec2(vec);

//		vec.swap(vec2);
		print_info(vec2);
		print_vector(vec2.begin(), vec2.end());
		print_capacity(vec2.begin(), vec2.capacity());
//		print_info(vec2);
//		print_vector(vec2.begin(), vec2.end());
//		print_capacity(vec2.begin(), vec2.capacity());
	}
	std::cout << "\033[1;32mstd::vector\033[0m\n";
	{
		std::vector<int> vec(8, 666);
		std::vector<int> vec2(vec);

//		vec.swap(vec2);
		print_info(vec2);
		print_vector(vec2.begin(), vec2.end());
		print_capacity(vec2.begin(), vec2.capacity());
//		print_info(vec2);
//		print_vector(vec2.begin(), vec2.end());
//		print_capacity(vec2.begin(), vec2.capacity());
	}
}