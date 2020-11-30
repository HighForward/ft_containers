#include "Map.hpp"
#include "test.hpp"
#include <map>
#include <iostream>



void ft_test(const test<const int, std::string> &n)
{
	std::cout << n.first << " - " << n.second << std::endl;
}

int main()
{

	ft_test(test<int, std::string>(15, "quarante-deux"));

	/*
	std::cout << "--- ft::map ---" <<std::endl;
	{
		ft::map<int, std::string> map;
		ft::map<int, std::string>::iterator it;

		ft::Node<int, std::string> node;

		node.getParent();
		node.getGrandParent();

		map.insert(std::pair<int, std::string>(16, "bite"));
		map.insert(std::pair<int, std::string>(14, "bite"));
		map.insert(std::pair<int, std::string>(19, "bite"));
		map.insert(std::pair<int, std::string>(22, "bite"));
		map.insert(std::pair<int, std::string>(25, "bite"));

		std::cout << map.size() << std::endl;
		map.print();
		map.clear();
	}
	std::cout << "--- std::map ---" << std::endl;
	{
		std::map<int, std::string> map;

		map.insert(std::pair<int, std::string>(15, "bite"));
		map.insert(std::pair<int, std::string>(16, "bite"));
		map.insert(std::pair<int, std::string>(14, "bite"));
		map.insert(std::pair<int, std::string>(19, "bite"));

		std::map<int, std::string>::iterator it = map.begin();
		std::map<int, std::string>::iterator ite = map.end();
		std::cout << map.size() << std::endl;
		while (it != ite)
		{
			std::cout << it->first << " => " << it->second << std::endl;
			it++;
		}
	}*/
}