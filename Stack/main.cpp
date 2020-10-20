#include "Stack.hpp"
#include <stack>

int main()
{
    ft::stack<int> stack;

    stack.push(42);

    std::cout << stack.top() << std::endl;
    stack.pop();
    std::cout << stack.empty() << std::endl;
    stack.push(24);
    std::cout << stack.empty() << std::endl;
    stack.push(99);
    stack.push(33);
    std::cout << stack.top() << std::endl;
    std::cout << stack.size() << std::endl;

}