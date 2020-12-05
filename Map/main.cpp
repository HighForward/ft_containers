#include "Map.hpp"
#include "test.hpp"
#include <map>
#include <iostream>


int main()
{
	std::cout << "--- ft::map ---" <<std::endl;
	{
		ft::map<int, std::string> map;

		ft::map<int, std::string>::iterator it;
		ft::map<int, std::string>::iterator ite;

		map.insert(std::pair<int, std::string>(8, "bite"));
		map.insert(std::pair<int, std::string>(10, "octobite"));
		map.insert(std::pair<int, std::string>(2, "gigabite"));
		map.insert(std::pair<int, std::string>(1, "gigabite"));
		map.insert(std::pair<int, std::string>(6, "nanobite"));
		map.insert(std::pair<int, std::string>(12, "megabite"));
		map.insert(std::pair<int, std::string>(10, "megabite"));
		map.insert(std::pair<int, std::string>(14, "megabite"));


        it = map.begin();
        ite = map.end();

//        cit = map.begin();

//        it = map.upper_bound(1);


		map.print();
        std::cout << "---------" << std::endl;
		map.print();
        map.clear();

	}
	std::cout << "--- std::map ---" << std::endl;
	{
        std::map<int, std::string> map;

        std::map<int, std::string>::iterator it;
        std::map<int, std::string>::iterator ite;

        map.insert(std::pair<int, std::string>(8, "bite"));
        map.insert(std::pair<int, std::string>(10, "octobite"));
        map.insert(std::pair<int, std::string>(2, "gigabite"));
        map.insert(std::pair<int, std::string>(1, "gigabite"));
        map.insert(std::pair<int, std::string>(6, "nanobite"));
        map.insert(std::pair<int, std::string>(12, "megabite"));
        map.insert(std::pair<int, std::string>(10, "megabite"));
        map.insert(std::pair<int, std::string>(14, "megabite"));


        it = map.upper_bound(1);
        std::cout << it->first << std::endl;

	}
}