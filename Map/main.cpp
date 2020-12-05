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
		ft::map<int, std::string> pam;

        pam.insert(std::pair<int, std::string>(1100, "kk"));
        pam.insert(std::pair<int, std::string>(11200, "pipi"));

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

        map.insert(it, std::pair<int, std::string>(11, "megabite"));
        map.insert(it, std::pair<int, std::string>(9, "megabite"));

        map.insert(pam.begin(), pam.end());


//		std::cout << "size: " << map.size() << std::endl;
//		it.print();

        it = map.begin();
        ite = map.end();
		map.print();
        std::cout << "---------" << std::endl;
		map.print();
        map.clear();

	}
	std::cout << "--- std::map ---" << std::endl;
	{
		std::map<int, std::string> map;

		map.insert(std::pair<int, std::string>(15, "bite"));
		map.insert(std::pair<int, std::string>(11, "bite"));
		map.insert(std::pair<int, std::string>(18, "bite"));
		map.insert(std::pair<int, std::string>(9, "bite"));
		map.insert(std::pair<int, std::string>(9, "bite"));
		map.insert(std::pair<int, std::string>(13, "bite"));

		std::map<int, std::string>::iterator it = map.begin();

        map.insert(it, std::pair<int, std::string>(25, "bite"));
		std::map<int, std::string>::iterator ite = map.end();


		ite = map.lower_bound(11);


//		std::cout << "map.count =" << map.count(9) << std::endl;
        std::cout << ite->first;
//		while (it != ite)
//		{
//			std::cout << it->first << " => " << it->second << std::endl;
//			it++;
//		}
	}
}