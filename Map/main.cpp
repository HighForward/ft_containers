#include "Map.hpp"
#include "test.hpp"
#include <map>
#include <iostream>
#include <assert.h>


int main()
{
	std::cout << "--- ft::map ---" <<std::endl;
	{
		ft::map<int, std::string> map;
		ft::map<int, std::string>::iterator it;

		ft::Node<int, std::string> node;

		node.getParent();
		node.getGrandParent();

		map.insert(std::pair<int, std::string>(16, "bite"));
		map.insert(std::pair<int, std::string>(14, "octobite"));
		map.insert(std::pair<int, std::string>(9, "gigabite"));
		map.insert(std::pair<int, std::string>(19, "nanobite"));
		map.insert(std::pair<int, std::string>(13, "megabite"));

		std::cout << "size: " << map.size() << std::endl;

		it = map.begin();
		it++;
		it.print();

//		map.print();
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
	}
}