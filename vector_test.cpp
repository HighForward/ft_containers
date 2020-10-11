#include "vector.hpp"
#include <iostream>
#include <vector>
#include "test.h"

void ft_vector_insert()
{
	std::cout << "ft::vector" << std::endl;
	{
		ft::vector<int> vec;

		vec.push_back(100);
		vec.push_back(200);
		vec.push_back(300);
		vec.push_back(400);
		vec.push_back(500);
		vec.push_back(500);

		ft::vector<int>::iterator it = vec.begin();
		it++;
		it++;
		vec.insert(it, 6, 12);
		it = vec.begin();

		vec.insert(it, 3, 30);
		it = vec.begin();

		ft::vector<int> vec2(5, 99);

		vec.insert(it, vec2.begin(), vec2.end());

		it++;
		it++;
		it++;

		it = vec.begin() + 3;
		vec.insert(it,48);

		print_vector(vec.begin(), vec.end());
	}
}

void std_vector_insert()
{
	std::cout << "\nstd::vector" << std::endl;
	{
		std::vector<int> vec;

		vec.push_back(100);
		vec.push_back(200);
		vec.push_back(300);
		vec.push_back(400);
		vec.push_back(500);
		vec.push_back(500);

		std::vector<int>::iterator it = vec.begin();
		it++;
		it++;
		vec.insert(it, 6, 12);
		it = vec.begin();

		vec.insert(it, 3, 30);
		it = vec.begin();

		std::vector<int> vec2(5, 99);

		vec.insert(it, vec2.begin(), vec2.end());

		it++;
		it++;
		it++;

		it = vec.begin() + 3;
		vec.insert(it,48);

		print_vector(vec.begin(), vec.end());
	}
}