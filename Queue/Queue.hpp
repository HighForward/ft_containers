#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include "../List/List.hpp"


namespace ft
{
    template<class T, class Container = list<T> >
    class queue
    {
        public:
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;

        private:
            container_type _c;


        public:
            queue(const container_type& ctnr = container_type())
            {
                _c = ctnr;
            }

            void push(const value_type &val)
            {
                this->_c.push_back(val);
            }

            void pop()
            {
                this->_c.pop_front();
            }

            size_type size() const
            {
                return (_c.size());
            }

            bool empty() const
            {
                return (_c.empty());
            }

            value_type& front()
            {
                return (_c.front());
            }

            const value_type& front() const
            {
                return (_c.front());
            }

            value_type& back()
            {
                return (_c.back());
            }

            const value_type& back() const
            {
                return (_c.back());
            }
    };


}

#endif