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
		ft::map<int, std::string>::iterator ite;

		map.insert(std::pair<int, std::string>(8, "bite"));
		map.insert(std::pair<int, std::string>(4, "octobite"));
		map.insert(std::pair<int, std::string>(2, "gigabite"));
		map.insert(std::pair<int, std::string>(1, "gigabite"));
		map.insert(std::pair<int, std::string>(6, "nanobite"));
		map.insert(std::pair<int, std::string>(12, "megabite"));
		map.insert(std::pair<int, std::string>(10, "megabite"));
		map.insert(std::pair<int, std::string>(14, "megabite"));

//		std::cout << "size: " << map.size() << std::endl;
//		it.print();

        it = map.begin();
        it++;
        it++;
		map.print();
		map.erase(it);
		std::cout << "---------" << std::endl;
		map.print();
	}
	std::cout << "--- std::map ---" << std::endl;
	{
		std::map<int, std::string> map;

		map.insert(std::pair<int, std::string>(15, "bite"));
		map.insert(std::pair<int, std::string>(11, "bite"));
		map.insert(std::pair<int, std::string>(18, "bite"));
		map.insert(std::pair<int, std::string>(9, "bite"));
		map.insert(std::pair<int, std::string>(13, "bite"));

		std::map<int, std::string>::iterator it = map.begin();
		std::map<int, std::string>::iterator ite = map.end();
//		std::cout << map.size() << std::endl;
        it++;
        it++;

        map.insert(it, std::pair<int, std::string>(19, "bite"));
        it++;
        it++;
        it++;

        std::cout << it->first << std::endl;
//		while (it != ite)
//		{
//			std::cout << it->first << " => " << it->second << std::endl;
//			it++;
//		}
	}
}