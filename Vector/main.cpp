#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
    std::cout << "\033[1;32mft::vector\033[0m\n";
    {
        int myints[] = {16,2,77,29};
        ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
        std::cout << *fifth.begin() << std::endl;

        ft::vector<int>::const_iterator it;

        it = fifth.begin();

    }
    std::cout << "\033[1;32mstd::vector\033[0m\n";
    {
        int myints[] = {16,2,77,29};
        std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
        std::cout << *fifth.begin() << std::endl;
    }
}