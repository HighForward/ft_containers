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

    template<class T, class Pointer>
    class ConstvectorIterator;

	template<class T, class Pointer>
	class vectorIterator
	{
	        typedef Pointer pointer;
            typedef T&      reference;


        public:
			pointer c;

		public:
			vectorIterator() {};
			vectorIterator(const pointer current) : c(current) {};
			vectorIterator(const vectorIterator<T, Pointer> &x) : c(const_cast<pointer>(x.c)) {};
			~vectorIterator() {};

			vectorIterator<T, Pointer>& operator=(const vectorIterator<T, Pointer> &rhs) { c = rhs.c; return (*this); }

			//increment - decrement
            vectorIterator<T, Pointer> &operator++() { c++; return (*this); }
            vectorIterator<T, Pointer> operator++(int) { vectorIterator<T, Pointer> temp = *this; c++; return (temp); }
            vectorIterator<T, Pointer> &operator--() { c--; return (*this); }
            vectorIterator<T, Pointer> operator--(int) { vectorIterator<T, Pointer> temp = *this; c--; return (temp); }

            reference operator[](size_t n) { return *c; }

            operator ConstvectorIterator<T, Pointer>()
            {
			    return (ConstvectorIterator<T, Pointer>(c));
            }

            vectorIterator(const ConstvectorIterator<T, Pointer> &x)
            {
			    this->c = x.c;
            }

            vectorIterator<T, Pointer>& operator=(const ConstvectorIterator<T, Pointer>& x)
            {
			    this->c = x.c;
                return (*this);
            }

            //compare
			bool operator==(const vectorIterator<T, Pointer> &rhs) { return (c == rhs.c); }
			bool operator!=(const vectorIterator<T, Pointer> &rhs) { return (c != rhs.c); }
			bool operator<(const vectorIterator<T, Pointer> &rhs)  { return (c < rhs.c); }
			bool operator>(const vectorIterator<T, Pointer> &rhs)  { return (c > rhs.c); }
			bool operator<=(const vectorIterator<T, Pointer> &rhs) { return (c <= rhs.c); }
			bool operator>=(const vectorIterator<T, Pointer> &rhs) { return (c >= rhs.c); }

			//arithmetic operator
			std::ptrdiff_t operator-(const vectorIterator<T, Pointer> &rhs) { return (this->c - rhs.c); }
            vectorIterator<T, Pointer> operator-(int n) { return (vectorIterator<T, Pointer>(this->c - n)); }
			std::ptrdiff_t operator+(const vectorIterator<T, Pointer> &rhs) { return (this->c + rhs.c); }
            vectorIterator<T, Pointer> operator+(int n) { return (vectorIterator<T, Pointer>(this->c + n)); }

			//getter
			T &operator*() { return (*this->c); }
	};


    template<class T, class Pointer>
    class ConstvectorIterator
    {
            typedef const Pointer pointer;
            typedef const T&      reference;

        public:
            T* c;

        public:
            ConstvectorIterator() : c() {};
            ConstvectorIterator(const pointer current) : c(current) {};
            ConstvectorIterator(ConstvectorIterator<T, Pointer> const &x) : c(const_cast<pointer>(x.c)) {};
            ~ConstvectorIterator() {};

            ConstvectorIterator<T, Pointer>& operator=(const ConstvectorIterator<T, Pointer> &rhs) { c = rhs.c; return (*this); }

            //increment - decrement
            ConstvectorIterator<T, Pointer> &operator++() { c++; return (*this); }
            ConstvectorIterator<T, Pointer> operator++(int) { ConstvectorIterator<T, Pointer> temp = *this; c++; return (temp); }
            ConstvectorIterator<T, Pointer> &operator--() { c--; return (*this); }
            ConstvectorIterator<T, Pointer> operator--(int) { ConstvectorIterator<T, Pointer> temp = *this; c--; return (temp); }

            reference operator[](size_t n) { return *c; }

            operator vectorIterator<T, Pointer>()
            {
                return (vectorIterator<T, Pointer>(c));
            }

            ConstvectorIterator(const vectorIterator<T, Pointer> &x)
            {
                this->c = x.c;
            }

            ConstvectorIterator<T, Pointer>& operator=(const vectorIterator<T, Pointer> &x)
            {
                this->c = x.c;
                return (*this);
            }

            //compare
            bool operator==(const ConstvectorIterator<T, Pointer> &rhs) { return (c == rhs.c); }
            bool operator!=(const ConstvectorIterator<T, Pointer> &rhs) { return (c != rhs.c); }
            bool operator<(const ConstvectorIterator<T, Pointer> &rhs)  { return (c < rhs.c); }
            bool operator>(const ConstvectorIterator<T, Pointer> &rhs)  { return (c > rhs.c); }
            bool operator<=(const ConstvectorIterator<T, Pointer> &rhs) { return (c <= rhs.c); }
            bool operator>=(const ConstvectorIterator<T, Pointer> &rhs) { return (c >= rhs.c); }

            //arithmetic operator
            std::ptrdiff_t operator-(const ConstvectorIterator<T, Pointer> &rhs) { return (this->c - rhs.c); }
            ConstvectorIterator<T, Pointer> operator-(int n) { return (ConstvectorIterator<T, Pointer>(this->c - n)); }
            std::ptrdiff_t operator+(const ConstvectorIterator<T, Pointer> &rhs) { return (this->c + rhs.c); }
            ConstvectorIterator<T, Pointer> operator+(int n) { return (ConstvectorIterator<T, Pointer>(this->c + n)); }

            //getter
            reference operator*() { return (*this->c); }
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
			typedef vectorIterator<T, T*> iterator;
			typedef ConstvectorIterator<T, T*> const_iterator;
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

			vector(const vector& x)
			{
				_c = NULL;
				_length = 0;
				_capacity = 0;
				assign(x.begin(), x.end());
			}

			vector(iterator first, iterator last, const allocator_type& alloc = allocator_type())
			{
				_c = NULL;
				_length = 0;
				_capacity = 0;
				assign(first, last);
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
}

#endif