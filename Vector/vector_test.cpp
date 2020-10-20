#include "Vector.hpp"
#include <iostream>
#include <vector>
#include "test.h"

void 	print_info(ft::vector<int> &vec)
{
	std::cout << "\033[1;31m------ size: " << vec.size() << " ------\033[0m\n";
	std::cout << "\033[1;31m---- capacity: " << vec.capacity() << " ----\033[0m\n";
}

void	print_vector(ft::vector<int>::iterator it, ft::vector<int>::iterator ite)
{
	std::cout << "\033[1;31m-- vector content: --\033[0m\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "\033[1;31m---------------------\033[0m\n";
}

void 	print_capacity(ft::vector<int>::iterator it, size_t capacity)
{
	for (size_t i = 0; i < capacity; i++)
	{
		std::cout << "*it: " << *it << std::endl;
		it++;
	}
}

void 	print_info(std::vector<int> &vec)
{
	std::cout << "\033[1;31m------ size: " << vec.size() << " ------\033[0m\n";
	std::cout << "\033[1;31m---- capacity: " << vec.capacity() << " ----\033[0m\n";
}

void	print_vector(std::vector<int>::iterator it, std::vector<int>::iterator ite)
{
	std::cout << "\033[1;31m-- vector content: --\033[0m\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "\033[1;31m---------------------\033[0m\n";
}

void 	print_capacity(std::vector<int>::iterator it, size_t capacity)
{
	std::cout << "\033[1;31m-- capacity value: --\033[0m\n";
	for (size_t i = 0; i < capacity; i++)
	{
		std::cout << "*it: " << *it << std::endl;
		it++;
	}
	std::cout << "\033[1;31m---------------------\033[0m\n";
}


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

void ft_vector_erase()
{
	std::cout << "\033[1;32mft::vector\033[0m\n";
	{
		ft::vector<int> vec;
		ft::vector<int>::iterator it;
		vec.push_back(100);
		vec.push_back(200);
		vec.push_back(300);
		vec.push_back(400);
		vec.push_back(500);
		vec.push_back(600);
		vec.push_back(700);
		vec.push_back(800);
		it = vec.erase(vec.begin());
		std::cout << "*it: " << *it << std::endl;
		it = vec.erase(vec.begin());
		std::cout << "*it: " << *it << std::endl;
		it = vec.erase(vec.begin(), vec.begin() + 2);
		std::cout << "*it: " << *it << std::endl;
		vec.push_back(900);
		vec.push_back(1000);
		vec.push_back(1100);
		it = vec.erase(vec.end() - 2);
		std::cout << "*it: " << *it << std::endl;
		it = vec.erase(vec.begin() + 2, vec.begin() + 4);
		std::cout << "*it: " << *it << std::endl;

		print_info(vec);
		print_vector(vec.begin(), vec.end());
		print_capacity(vec.begin(), vec.capacity());
	}
}

void std_vector_erase()
{
	std::cout << "\n\033[1;32mstd::vector\033[0m\n";
	{
		std::vector<int> vec;
		std::vector<int>::iterator it;
		vec.push_back(100);
		vec.push_back(200);
		vec.push_back(300);
		vec.push_back(400);
		vec.push_back(500);
		vec.push_back(600);
		vec.push_back(700);
		vec.push_back(800);
		it = vec.erase(vec.begin());
		std::cout << "*it: " << *it << std::endl;
		it = vec.erase(vec.begin());
		std::cout << "*it: " << *it << std::endl;
		it = vec.erase(vec.begin(), vec.begin() + 2);
		std::cout << "*it: " << *it << std::endl;
		vec.push_back(900);
		vec.push_back(1000);
		vec.push_back(1100);
		it = vec.erase(vec.end() - 2);
		std::cout << "*it: " << *it << std::endl;
		it = vec.erase(vec.begin() + 2, vec.begin() + 4);
		std::cout << "*it: " << *it << std::endl;

		print_info(vec);
		print_vector(vec.begin(), vec.end());
		print_capacity(vec.begin(), vec.capacity());
	}
}

void ft_vector_clear()
{
	std::cout << "\033[1;32mft::vector\033[0m\n";
	{
		ft::vector<int> vec;
		ft::vector<int>::iterator it;
		for (size_t i = 0; i < 10; i++)
			vec.push_back(i);

		vec.clear();
		print_info(vec);
		print_vector(vec.begin(), vec.end());
		print_capacity(vec.begin(), vec.capacity());
	}
}

void std_vector_clear()
{
	std::cout << "\n\033[1;32mstd::vector\033[0m\n";
	{
		std::vector<int> vec;
		std::vector<int>::iterator it;

		for (size_t i = 0; i < 10; i++)
			vec.push_back(i);

		vec.clear();
		print_info(vec);
		print_vector(vec.begin(), vec.end());
		print_capacity(vec.begin(), vec.capacity());
	}
}

void ft_vector_assign()
{
	std::cout << "\033[1;32mft::vector\033[0m\n";
	{
		ft::vector<int> vec(3, 33);
		ft::vector<int> vec2(6, 66);
		ft::vector<int> vec4(1, 111);

		print_info(vec);
		print_vector(vec.begin(), vec.end());
		print_capacity(vec.begin(), vec.capacity());
		vec.assign(vec2.begin(), vec2.end());
		print_info(vec);
		print_vector(vec.begin(), vec.end());
		print_capacity(vec.begin(), vec.capacity());
		vec.assign(vec4.begin(), vec4.end());
		print_info(vec);
		print_vector(vec.begin(), vec.end());
		print_capacity(vec.begin(), vec.capacity());
		vec.assign(4, 99);
		print_info(vec);
		print_vector(vec.begin(), vec.end());
		print_capacity(vec.begin(), vec.capacity());
	}
}

void std_vector_assign()
{
	std::cout << "\033[1;32mft::vector\033[0m\n";
	{
		std::vector<int> vec(3, 33);
		std::vector<int> vec2(6, 66);
		std::vector<int> vec4(1, 111);

		print_info(vec);
		print_vector(vec.begin(), vec.end());
		print_capacity(vec.begin(), vec.capacity());
		vec.assign(vec2.begin(), vec2.end());
		print_info(vec);
		print_vector(vec.begin(), vec.end());
		print_capacity(vec.begin(), vec.capacity());
		vec.assign(vec4.begin(), vec4.end());
		print_info(vec);
		print_vector(vec.begin(), vec.end());
		print_capacity(vec.begin(), vec.capacity());
		vec.assign(4, 99);
		print_info(vec);
		print_vector(vec.begin(), vec.end());
		print_capacity(vec.begin(), vec.capacity());
	}
}

void ft_vector_push_pop()
{
	std::cout << "\033[1;32mft::vector\033[0m\n";
	{
		ft::vector<int> vec(2, 10);
		vec.push_back(15);
		vec.push_back(51);
		vec.push_back(96);
		vec.push_back(69);
		vec.pop_back();
		vec.push_back(999);
		vec.pop_back();
		vec.push_back(999);
		vec.pop_back();
		print_info(vec);
		print_vector(vec.begin(), vec.end());
		print_capacity(vec.begin(), vec.capacity());
	}
}

void std_vector_push_pop()
{
	std::cout << "\033[1;32mft::vector\033[0m\n";
	{
		std::vector<int> vec(2, 10);
		vec.push_back(15);
		vec.push_back(51);
		vec.push_back(96);
		vec.push_back(69);
		vec.pop_back();
		vec.push_back(999);
		vec.pop_back();
		vec.push_back(999);
		vec.pop_back();
		print_info(vec);
		print_vector(vec.begin(), vec.end());
		print_capacity(vec.begin(), vec.capacity());
	}
}