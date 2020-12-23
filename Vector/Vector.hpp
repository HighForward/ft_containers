#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <limits>
#include <cstdio>
#include <cmath>
#include <exception>

namespace ft
{

    //IT
    template<class T>
    class ConstvectorIterator;

    template<class T>
    class vectorIterator
    {
        private:
            T* c;

        public:
            typedef T*      pointer;
            typedef T&      reference;


        public:
            vectorIterator() {};
            vectorIterator(pointer current) : c(current) {};
            vectorIterator(const vectorIterator<T> &x) : c(const_cast<pointer>(x.c)) {};
            ~vectorIterator() {};

            //cast
            operator ConstvectorIterator<T>() { return (ConstvectorIterator<T>(c)); }
            vectorIterator(const ConstvectorIterator<T> &x) { this->c = x.c; }
            vectorIterator<T>& operator=(const ConstvectorIterator<T>& x) { this->c = x.c; return (*this); }

            vectorIterator<T>& operator=(const vectorIterator<T> &rhs) { c = rhs.c; return (*this); }

            //increment - decrement
            vectorIterator<T> &operator++() { c++; return (*this); }
            vectorIterator<T> operator++(int) { vectorIterator<T> temp = *this; c++; return (temp); }
            vectorIterator<T> &operator--() { c--; return (*this); }
            vectorIterator<T> operator--(int) { vectorIterator<T> temp = *this; c--; return (temp); }

            reference operator[](size_t n) { return *c; }

            //compare
            bool operator==(const vectorIterator<T> &rhs) { return (c == rhs.c); }
            bool operator!=(const vectorIterator<T> &rhs) { return (c != rhs.c); }
            bool operator<(const vectorIterator<T> &rhs)  { return (c < rhs.c); }
            bool operator>(const vectorIterator<T> &rhs)  { return (c > rhs.c); }
            bool operator<=(const vectorIterator<T> &rhs) { return (c <= rhs.c); }
            bool operator>=(const vectorIterator<T> &rhs) { return (c >= rhs.c); }

            //arithmetic operator
            std::ptrdiff_t operator-(const vectorIterator<T> &rhs) { return (this->c - rhs.c); }
            vectorIterator<T> operator-(int n) { return (vectorIterator<T>(this->c - n)); }
            std::ptrdiff_t operator+(const vectorIterator<T> &rhs) { return (this->c + rhs.c); }
            vectorIterator<T> operator+(int n) { return (vectorIterator<T>(this->c + n)); }

            //getter
            T &operator*() { return (*this->c); }
            T *getPtr() const { return (this->c); }
    };

    template<class T>
    class ConstvectorIterator
    {

        private:
            T* c;

        public:
            typedef const T* Pointer;
            typedef const T&      reference;

        public:
            ConstvectorIterator() {};
            ConstvectorIterator(T* current) : c(current) {};
            ConstvectorIterator(ConstvectorIterator<T> const &x) : c(x.c) {};
            ~ConstvectorIterator() {};

            //cast
            operator vectorIterator<T>() { return (vectorIterator<T>(this->c)); }
            ConstvectorIterator(const vectorIterator<T> &x) { this->c = x.c; }
            ConstvectorIterator<T>& operator=(const vectorIterator<T> &x) { this->c = x.getPtr(); return (*this); }

            ConstvectorIterator<T>& operator=(const ConstvectorIterator<T> &rhs) { this->c = rhs.c; return (*this); }

//            increment - decrement
            ConstvectorIterator<T> &operator++() { c++; return (*this); }
            ConstvectorIterator<T> operator++(int) { ConstvectorIterator<T> temp = *this; c++; return (temp); }
            ConstvectorIterator<T> &operator--() { c--; return (*this); }
            ConstvectorIterator<T> operator--(int) { ConstvectorIterator<T> temp = *this; c--; return (temp); }

            reference operator[](size_t n) { return *this->c; }


            //compare
            bool operator==(const ConstvectorIterator<T> &rhs) { return (c == rhs.c); }
            bool operator!=(const ConstvectorIterator<T> &rhs) { return (c != rhs.c); }
            bool operator<(const ConstvectorIterator<T> &rhs)  { return (c < rhs.c); }
            bool operator>(const ConstvectorIterator<T> &rhs)  { return (c > rhs.c); }
            bool operator<=(const ConstvectorIterator<T> &rhs) { return (c <= rhs.c); }
            bool operator>=(const ConstvectorIterator<T> &rhs) { return (c >= rhs.c); }

            //arithmetic operator
            std::ptrdiff_t operator-(const ConstvectorIterator<T> &rhs) { return (this->c - rhs.c); }
            ConstvectorIterator<T> operator-(int n) { return (ConstvectorIterator<T>(this->c - n)); }
            std::ptrdiff_t operator+(const ConstvectorIterator<T> &rhs) { return (this->c + rhs.c); }
            ConstvectorIterator<T> operator+(int n) { return (ConstvectorIterator<T>(this->c + n)); }

            //getter
            reference operator*() { return (*this->c); }
            T *getPtr() const { return (this->c); }
    };

    //Reverse IT
    template<class T>
    class constReverseIterator;

    template<class T>
    class reverseIterator
    {
        private:
            T* c;

        public:
            typedef T* Pointer;
            typedef T&      reference;

        public:
            reverseIterator() : c() {};
            reverseIterator(Pointer current) : c(current) {};
            reverseIterator(reverseIterator<T> const &x) : c(const_cast<T*>(x.c)) {};
            ~reverseIterator() {};

            //cast
            operator reverseIterator<T>() { return (constReverseIterator<T>(this->c)); }
            reverseIterator(const constReverseIterator<T> &x) { this->c = x.c; }
            reverseIterator<T>& operator=(const constReverseIterator<T> &x) { this->c = x.getPtr(); return (*this); }

            reverseIterator<T>& operator=(const reverseIterator<T> &rhs) { this->c = rhs.c; return (*this); }

//            increment - decrement
            reverseIterator<T> &operator--() { c++; return (*this); }
            reverseIterator<T> operator--(int) { reverseIterator<T> temp = *this; c++; return (temp); }
            reverseIterator<T> &operator++() { c--; return (*this); }
            reverseIterator<T> operator++(int) { reverseIterator<T> temp = *this; c--; return (temp); }

            reference operator[](size_t n) { return *this->c; }

            //compare
            bool operator==(const reverseIterator<T> &rhs) { return (c == rhs.c); }
            bool operator!=(const reverseIterator<T> &rhs) { return (c != rhs.c); }
            bool operator<(const reverseIterator<T> &rhs)  { return (c < rhs.c); }
            bool operator>(const reverseIterator<T> &rhs)  { return (c > rhs.c); }
            bool operator<=(const reverseIterator<T> &rhs) { return (c <= rhs.c); }
            bool operator>=(const reverseIterator<T> &rhs) { return (c >= rhs.c); }

            //arithmetic operator
            std::ptrdiff_t operator-(const reverseIterator<T> &rhs) { return (this->c - rhs.c); }
            reverseIterator<T> operator-(int n) { return (reverseIterator<T>(this->c - n)); }
            std::ptrdiff_t operator+(const reverseIterator<T> &rhs) { return (this->c + rhs.c); }
            reverseIterator<T> operator+(int n) { return (reverseIterator<T>(this->c + n)); }

            //getter
            reference operator*() { return (*this->c); }
            T *getPtr() const { return (this->c); }
    };

    template<class T>
    class constReverseIterator
    {
        private:
            T* c;

        public:
            typedef const T* Pointer;
            typedef const T&      reference;

        public:
            constReverseIterator() : c() {};
            constReverseIterator(Pointer current) : c(current) {};
            constReverseIterator(constReverseIterator<T> const &x) : c(const_cast<T*>(x.c)) {};
            ~constReverseIterator() {};

            //cast
            operator constReverseIterator<T>() { return (reverseIterator<T>(this->c)); }
            constReverseIterator(const reverseIterator<T> &x) { this->c = x.getPtr(); }
            constReverseIterator<T>& operator=(const reverseIterator<T> &x) { this->c = x.getPtr(); return (*this); }

            constReverseIterator<T>& operator=(const constReverseIterator<T> &rhs) { this->c = rhs.c; return (*this); }

//            increment - decrement
            constReverseIterator<T> &operator--() { c++; return (*this); }
            constReverseIterator<T> operator--(int) { constReverseIterator<T> temp = *this; c++; return (temp); }
            constReverseIterator<T> &operator++() { c--; return (*this); }
            constReverseIterator<T> operator++(int) { constReverseIterator<T> temp = *this; c--; return (temp); }

            reference operator[](size_t n) { return *this->c; }


            //compare
            bool operator==(const constReverseIterator<T> &rhs) { return (c == rhs.c); }
            bool operator!=(const constReverseIterator<T> &rhs) { return (c != rhs.c); }
            bool operator<(const constReverseIterator<T> &rhs)  { return (c < rhs.c); }
            bool operator>(const constReverseIterator<T> &rhs)  { return (c > rhs.c); }
            bool operator<=(const constReverseIterator<T> &rhs) { return (c <= rhs.c); }
            bool operator>=(const constReverseIterator<T> &rhs) { return (c >= rhs.c); }

            //arithmetic operator
            std::ptrdiff_t operator-(const constReverseIterator<T> &rhs) { return (this->c - rhs.c); }
            constReverseIterator<T> operator-(int n) { return (constReverseIterator<T>(this->c - n)); }
            std::ptrdiff_t operator+(const constReverseIterator<T> &rhs) { return (this->c + rhs.c); }
            constReverseIterator<T> operator+(int n) { return (constReverseIterator<T>(this->c + n)); }

            //getter
            reference operator*() { return (*this->c); }
            T *getPtr() const { return (this->c); }
    };



    template<class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef vectorIterator<T> iterator;
            typedef ConstvectorIterator<T> const_iterator;
            typedef reverseIterator<T> reverse_iterator;
            typedef constReverseIterator<T> const_reverse_iterator;
            typedef size_t size_type;

        private:
            value_type *_c;
            size_type _length;
            size_type _capacity;
            allocator_type allocator;

        private :

            class out_of_range : public std::exception
            {
                    virtual const char* what() const throw()
                    {
                        return ("out_of_range");
                    }
            };

            size_type get_new_capacity(size_type requested_capacity)
            {
                if ((int)requested_capacity < 0)
                    return (0);
                size_type new_cap = 0;
                size_type power = 0;
                while (new_cap < requested_capacity)
                    new_cap = pow(2, power++);
                return (new_cap);
            }

        public:

            //constructor - destructor
            vector(const allocator_type& alloc = allocator_type())
            {
                allocator = alloc;
                _c = allocator.allocate(0);
                _capacity = 0;
                _length = 0;
            };

            vector(size_type n, const value_type &val = value_type(), const allocator_type& alloc = allocator_type())
            {
                allocator = alloc;
                _capacity = n;
                _c = allocator.allocate(n);
                for (size_type i = 0; i < n; i++)
                    _c[i] = val;
                _length = n;
            };

            vector(vector<T>& rhs)
            {
                _c = allocator.allocate(0);
                this->allocator = rhs.allocator;
                this->_capacity = 0;
                this->_length = 0;
                assign(rhs.begin(), rhs.end());
            }

            vector(iterator first, iterator last, const allocator_type& alloc = allocator_type())
            {
                _c = NULL;
                _length = 0;
                _capacity = 0;
                assign(first, last);
            }

            vector& operator=(const vector<T>& rhs) {
                assign(rhs.begin(), rhs.end());
                this->_length = rhs._length;
                this->_capacity = rhs._capacity;
                this->allocator = rhs.allocator;
                return (*this);
            }

            ~vector()
            {
                allocator.deallocate(_c, capacity());
            }


            // --- Iterator ---:
            iterator begin() { return (iterator(&at(0))); }
            iterator end() { return (iterator(&_c[_length])); }
            const_iterator begin() const { return (const_iterator(&at(0))); }
            const_iterator end() const { return (const_iterator(&_c[_length])); }
            reverse_iterator rbegin() { return (reverse_iterator(&_c[_length - 1])); }
            reverse_iterator rend() { return (reverse_iterator(&_c[0 - 1])); }
            const_reverse_iterator rbegin() const { return (const_reverse_iterator(&_c[_length - 1])); }
            const_reverse_iterator rend() const { return (const_reverse_iterator(&_c[0 - 1])); }


            // --- Capacity ---:
            size_type size() const
            {
                return (_length);
            }

            size_type max_size() const
            {
                return (std::numeric_limits<size_type>::max() / sizeof(value_type));
            }

            void resize(size_type n, value_type val = value_type())
            {
                if (n > size())
                {
                    if (n > capacity())
                        reserve(get_new_capacity(n + 1));
                    for (size_type x = size(); x < n; x++)
                        _c[x] = val;
                }
                _length = n;
            }

            size_type capacity() const
            {
                return (_capacity);
            }

            bool empty() const
            {
                return (_length == 0);
            }

            void reserve(size_type n)
            {
                if (n > capacity())
                {
                    T* new_c;
                    new_c = allocator.allocate(n);
                    for (size_type i = 0; i < _length; i++)
                    {
                        allocator.construct(&new_c[i], _c[i]);
                        allocator.destroy(&_c[i]);
                    }
                    allocator.deallocate(_c, capacity());
                    _capacity = n;
                    _c = new_c;
                }
            }

            // --- Element access ---:
            reference operator[] (size_type n)
            {
                return (_c[n]);
            }

            const_reference operator[] (size_type n) const
            {
                return (_c[n]);
            }

            reference at(size_type n)
            {
                return (_c[n]);
            }

            const_reference at(size_type n) const
            {
                return (_c[n]);
            }

            reference front()
            {
                return (at(0));
            }

            const_reference front() const
            {
                return (at(0));
            }

            reference back()
            {
                return (at(_length - 1));
            }

            const_reference back() const
            {
                return (at(_length - 1));
            }


            // --- Modifiers ---:
            void assign(iterator first, iterator last)
            {
                std::ptrdiff_t len = last - first;
                size_type x = 0;

                if (len > capacity())
                    reserve(len);
                for (iterator it = first; it != last; it++)
                    _c[x++] = *it;
                _length = x;
            }

            void assign(const_iterator first, const_iterator last)
            {
                std::ptrdiff_t len = last - first;
                size_type x = 0;

                if (len > capacity())
                    reserve(len);
                for (iterator it = first; it != last; it++)
                    _c[x++] = *it;
                _length = x;
            }

            void assign(size_type n, const value_type &val)
            {
                if (n > capacity())
                    reserve(n);
                for (size_type x = 0; x < n; x++)
                    _c[x] = val;
                _length = n;
            }

            void push_back(const value_type &val)
            {
                reserve(get_new_capacity(_length + 1));
                _c[_length++] = val;
            }

            void pop_back()
            {
                allocator.destroy(&_c[--_length]);
            }

            iterator insert(iterator position, const value_type& val)
            {
                std::ptrdiff_t i = position - begin();

                insert(position, 1, val);
                return (iterator(&at(i)));
            }

            void insert(iterator position, size_type n ,const value_type& val)
            {
                if (n > 0)
                {
                    value_type temp[_length + n];
                    std::ptrdiff_t index = position - begin();
                    reserve(get_new_capacity(_length + n));
                    for (size_type x = 0; x < index; x++)
                        temp[x] = _c[x];
                    for (size_type x = index; x < size(); ++x)
                        temp[x + n] = _c[x];
                    for (size_type i = 0; i < n; i++)
                        temp[i + index] = val;
                    for (size_type i = 0; i < _length + n; i++)
                        _c[i] = temp[i];
                    _length += n;
                }
            }

            void insert(iterator position, iterator first, iterator last)
            {
                iterator it = position;
                while (first != last)
                {
                    it = insert(it, *first);
                    it++;
                    first++;
                }
            }

            iterator erase(iterator position)
            {
                std::ptrdiff_t index = position - begin();

                for (size_type x = index; x != size() - 1; x++)
                    _c[x] = _c[x + 1];
                _length--;
                return (iterator(&_c[index]));
            }

            iterator erase(iterator first, iterator last)
            {
                std::ptrdiff_t index = first - begin();
                std::ptrdiff_t stop = last - first;

                _length -= stop;
                for (size_type i = index; i != size(); i++)
                    _c[i] = _c[i + stop];
                return (iterator(&_c[index]));
            }

            void swap(vector &x)
            {
                size_type temp_len = _length;
                size_type temp_cap = _capacity;
                pointer temp_c = _c;
                _length = x._length;
                _capacity = x._capacity;
                _c = x._c;
                x._length = temp_len;
                x._capacity = temp_cap;
                x._c = temp_c;
            }

            void clear()
            {
                erase(begin(), end());
            }
    };

    template<class T>
    bool operator==(const vector<T> &lhs, const vector<T> &rhs)
    {
        if (lhs.size() != rhs.size())
        { return (false); }
        for (typename vector<T>::size_type i = 0; i < rhs.size(); ++i)
        {
            if (lhs[i] != rhs[i])
            { return false; }
        }
        return (true);
    }

    template<class T>
    bool operator<(const vector<T> &lhs, const vector<T> &rhs)
    {
        if (lhs.size() != rhs.size()) {
            return (lhs.size() < rhs.size());
        }
        for (typename vector<T>::size_type i = 0; i < rhs.size(); ++i)
        {
            if (lhs[i] < rhs[i])
            { return (true); }
        }
        return (false);
    }

    template<class T>
    bool operator!=(const vector<T> &lhs, const vector<T> &rhs)
    {
        return (!(lhs == rhs));
    }

    template<class T>
    bool operator>(const vector<T> &lhs, const vector<T> &rhs)
    {
        return (rhs < lhs);
    }

    template<class T>
    bool operator<=(const vector<T> &lhs, const vector<T> &rhs)
    {
        return (!(rhs < lhs));
    }

    template<class T>
    bool operator>=(const vector<T> &lhs, const vector<T> &rhs)
    {
        return (!(lhs < rhs));
    }
}

#endif