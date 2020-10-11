#include "vector.hpp"
#include <iostream>
#include <vector>
#include "test.h"

void	print_vector(ft::vector<int>::iterator it, ft::vector<int>::iterator ite)
{
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
}

void	print_vector(std::vector<int>::iterator it, std::vector<int>::iterator ite)
{
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
}

int main()
{
//	ft_vector_insert();
//	std_vector_insert();

	std::cout << "ft::vector\n"
	{
		ft::vector<int> vec;
	}
	std::cout << "std::vector\n"
	{
		ft::vector<int> vec;
	}

}