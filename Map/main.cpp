#include "Map.hpp"
#include <map>
#include <iostream>

int main()
{
	std::cout << "--- ft::map ---" <<std::endl;
	{
		ft::map<int, std::string> map;
		ft::map<int, std::string>::iterator it;

		ft::Node<int, std::string> node;

		node.getParent();
		node.getGrandParent();

		map.insert(std::pair<int, std::string>(15, "bite"));
		map.insert(std::pair<int, std::string>(16, "bite"));
//		map.insert(std::pair<int, std::string>(14, "bite"));
//		map.insert(std::pair<int, std::string>(19, "bite"));

		std::cout << map.size() << std::endl;
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