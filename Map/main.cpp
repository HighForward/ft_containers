#include "MapRemake.hpp"
#include <map>
#include <iostream>
#include <cassert>


int main()
{
	std::cout << "--- ft::map ---" <<std::endl;
	{

        ft::map<int, int>::iterator it;
        ft::map<int, int>::const_iterator cit;
        ft::map<int, int> map;

        map.insert(std::pair<int, int>(15, 15));
        ft::map<int, int>::iterator ite;

        cit = map.begin();

        std::cout << it->second << std::endl;
    }
	std::cout << "--- std::map ---" << std::endl;
    {
        std::map<int, int>::iterator it;
        std::map<int, int>::const_iterator cit;
        std::map<int, int> map;

        map.insert(std::pair<int, int>(15, 15));
        std::map<int, int>::iterator ite;

        cit = map.begin();


        std::cout << cit->second << std::endl;
	}
}