#include "list.hpp"
#include <list>

int main()
{

	std::cout << "\033[1;32mft::list\033[0m\n";
	{
		ft::list<int> list;
		ft::list<int>::iterator it;

		list.push_back(99);
		list.push_back(66);
		it = list.begin();

//		it++;


		std::cout << *it << std::endl;


	}
	std::cout << "\033[1;32mstd::list\033[0m\n";
	{
		std::list<int> list;
		std::list<int>::iterator it;

//		list.push_back(99);
//		list.push_back(66);
		it = list.begin();

//		it++;

//		it[4] = 45;
//
//		list[1] = 45;

		std::cout << list.size() << " | ";
		std::cout << *it << std::endl;
	}

}