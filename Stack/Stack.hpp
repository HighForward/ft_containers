#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "../List/List.hpp"


namespace ft
{
    template<class T, class Container = list<T> >
    class stack
    {
        public:
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;

        private:
            container_type _c;


        public:
            stack(const container_type& ctnr = container_type())
            {
                _c = ctnr;
            }

            void push(const value_type &val)
            {
                this->_c.push_back(val);
            }

            void pop()
            {
                this->_c.pop_back();
            }

            size_type size() const
            {
                return (_c.size());
            }

            bool empty() const
            {
                return (_c.size());
            }

            value_type& top()
            {
                return (_c.back());
            }

            const value_type& top() const
            {
                return (_c.back());
            }
    };


}

#endif