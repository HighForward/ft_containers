//#include "Vector.hpp"
#include <iostream>
#include <vector>
#include "test.hpp"

int main()
{
	std::cout << "\033[1;32mft::vector\033[0m\n";
	{
	    ft::vector<int> vec;

	    ft::vector<int>::iterator it;
        ft::vector<int>::const_iterator c;

        vec.push_back(100);

        c = vec.begin();
        it = vec.begin();

//        c.operator[](0) = 15;
        it.operator[](0) = 15;

        std::cout << c[0] << std::endl;
        std::cout << it[0] << std::endl;

//        std::cout << c[0] << std::endl;
//        c[0] = 15;

//        e.operator[](0) = 15;




//	    vec[0] = 500;
//	    it = vec.begin();


//	    it.
//	    std::cout << *e << std::endl;
	}
	std::cout << "\033[1;32mstd::vector\033[0m\n";
	{
        std::vector<int> vec;

        std::vector<int>::iterator it;
        std::vector<int>::const_iterator c;

        vec.push_back(100);

        c = vec.begin();
        it = vec.begin();

//        c.operator[](0) = 15;
	}
}