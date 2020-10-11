#include "vector.hpp"
#include <iostream>
#include <vector>


void	print_vector(ft::vector<int>::iterator it, ft::vector<int>::iterator ite)
{
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
}

int main()
{


	ft::vector<int> vec(1, 100);

	vec.push_back(42);
	vec.push_back(24);
	vec.push_back(85);
	vec.push_back(15);

	print_vector(vec.begin(), vec.end());

	ft::vector<int>::iterator it = vec.begin();
	ft::vector<int>::iterator ite = vec.end();

	std:: cout << "begin = " << *it << "\nend = " << *ite << "\n";

	vec.erase(it);

	print_vector(vec.begin(), vec.end());

	std::cout << "----" << std::endl;

	it++;
	ite--;
	vec.erase(it, ite);

	print_vector(vec.begin(), vec.end());
	std::cout << "----" << std::endl;

	int &test = vec.front();

	test = 789;

	print_vector(vec.begin(), vec.end());
	std::cout << "----" << std::endl;
//	vec.assign(vec.begin(), vec.end());

	std::vector<int> xd;

	std::cout << vec.max_size() << std::endl;
	std::cout << xd.max_size() << std::endl;
}