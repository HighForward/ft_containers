#include <iostream>
#include <cstddef>

namespace ft
{
	template<typename T>
	class Node
	{
		public:
			T c;
			Node *prev;
			Node *next;

			Node() {}
			Node(const T &content) : c(content), next(NULL), prev(NULL) {}
	};

	template<typename T>
	class listIterator
	{
		private:
			Node<T>* n;

		public:

			listIterator() {}
			listIterator(Node<T> *current) : n(current) {}
			listIterator(listIterator const *copy) : n(copy->n) {}
			~listIterator() {}

			Node<T>* get_node()
			{
				return (n);
			}

			listIterator& operator++()
			{
				n = n->next;
				return (*this);
			}

			listIterator operator++(int)
			{
				Node<T>* temp = n;
				n = n->next;
				return (listIterator<T>(temp));
			}

			listIterator& operator--()
			{
				n = n->prev;
				return (*this);
			}

			listIterator operator--(int)
			{
				Node<T>* temp = n;
				n = n->prev;
				return (listIterator<T>(temp));
			}

			bool operator==(listIterator<T> const &rhs)
			{
				return (this->n == rhs.n);
			}

			bool operator!=(listIterator<T> const &rhs)
			{
				return (this->n != rhs.n);
			}

			T& operator*()
			{
				return (n->c);
			}
	};

	template<class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef T value_type;
			typedef T *pointer;
			typedef const T *const_pointer;
			typedef T &reference;

			typedef const T &const_reference;
			typedef Alloc allocator_type;
			typedef std::ptrdiff_t difference_type;

			typedef listIterator<T> iterator;
			typedef listIterator<const T> const_iterator;

			typedef size_t size_type;

		private:
			typedef struct	s_list
			{
				Node<T> *first;
				Node<T> *last;
				Node<T> *past_end;
			}				t_list;

			t_list _list;
			allocator_type _allocator;
			size_type _length;

            template<typename Type>
            void swap(Type &l, Type &r)
            {
                Type tmp(l);
                l = r;
                r = tmp;
            }

			void init()
			{
				_list.past_end = new Node<T>;
				_list.last = _list.past_end;
				_list.first = _list.past_end;
				init_past_end();
			}

			void init_past_end()
			{
				_list.past_end->next = _list.first;
				_list.past_end->prev = _list.last;
				_list.last->next = _list.past_end;
				_list.first->prev = _list.past_end;
			}

		public:

			list(const allocator_type &alloc = allocator_type())
			{
				_allocator = alloc;
				_length = 0;
				init();
			}

			list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
			{
				_allocator = alloc;
				_length = 0;
                init();
				for (size_type x = n; x != 0; x--)
				    push_back(val);
			}

			~list()
			{
				Node<T> *remove;
				Node<T> *tmp;

				remove = _list.first;
				while (remove != end().get_node())
				{
					tmp = remove->next;
					delete remove;
					remove = tmp;
				}
				delete _list.past_end;
			}

			//operator=

			//Iterator
			iterator begin()
			{
				return (iterator(_list.first));
			}

			iterator end()
			{
				if (_length == 0)
					return (iterator(_list.first));
				else
					return (iterator(_list.last->next));
			}

			//reverse et const

			//Capacity
			bool empty() const
			{
				return (_length == 0);
			}

			size_type size() const
			{
				return (_length);
			}

			size_type max_size() const
			{
				//to_do;
				return (0);
			}

			//Element access
			reference front()
			{
				return (_list.first->c);
			}

			const_reference front() const
			{
				return (_list.first->c);
			}

			reference back()
			{
				return (_list.last->c);
			}

			const_reference back() const
			{
				return (_list.last->c);
			}

			//Modifiers
            void assign(iterator first, iterator last)
            {
                list<T> tmp;

                tmp.insert(tmp.begin(), first, last);
                clear();
                insert(begin(), tmp.begin(), tmp.end());
            }

            void assign(size_type n, const value_type& val)
            {
                clear();
                for (size_type x = n; x > 0; x--)
                    push_back(val);
            }

			void push_back(const value_type &val)
			{
				Node<T> *node = new Node<T>(val);
				node->next = _list.past_end;
				node->prev = _list.last;

				if (size() != 0)
					_list.last->next = node;
				else
					_list.first = node;
				_list.last = node;
				init_past_end();
				_length++;
			}

			void push_front(const value_type &val)
			{
				Node<T> *node = new Node<T>(val);
				node->next = _list.first;
				node->prev = _list.past_end;

				if (size() != 0)
					_list.first->prev = node;
				else
					_list.last = node;
				_list.first = node;
				init_past_end();
				_length++;
			}

			void pop_back()
			{
				Node<T> *tmp = _list.last->prev;
				delete _list.last;
				_list.last = tmp;
                init_past_end();

                _length--;
			}

			void pop_front()
			{
				Node<T> *tmp = _list.first->next;
				delete _list.first;
				_list.first = tmp;
                init_past_end();

                _length--;
			}

			iterator insert(iterator position, const value_type& val)
			{
				if (position == begin())
				{
					push_front(val);
					return (begin());
				}
				else if (position == end())
				{
					push_back(val);
					return (end());
				}
				else
				{
					Node<T> *node = new Node<T>(val);
					node->prev = position.get_node()->prev;
					node->next = position.get_node();
					position.get_node()->prev->next = node;
					position.get_node()->prev = node;
					_length++;
					return (iterator(node));
				}
			}

			void insert(iterator position, size_type n, const value_type& val)
			{
				iterator tmp = position;
				for (size_type x = 0; x < n; x++)
					insert(tmp, val);
			}

			void insert(iterator position, iterator first, iterator last)
			{

                for (iterator it = first; it != last; it++)
                    insert(position, *it);
			}

			iterator erase(iterator position)
			{
				if (position == begin())
				{
                    pop_front();
                    return (begin());
                }
				else if (position == --end())
				{
                    pop_back();
                    return (end());
                }
				else if (position == end())
                    return (position);
				else
				{
                    Node<T> *tmp = position.get_node()->prev;
                    tmp->next = position.get_node()->next;
					position.get_node()->next->prev = tmp;
					delete position.get_node();
					_length--;
					return (iterator(tmp->next));
				}
			}

			iterator erase(iterator first, iterator last)
            {
			    while  (first != last)
			        erase(first++);
			    return (last);
            }

            //swap

            void resize(size_type n, value_type val = value_type())
            {
			        for (size_type x = _length; x > n; x--)
                        pop_back();
			        for (size_type x = _length; x < n; x++)
			            push_back(val);
            }

            void clear()
            {
			    erase(begin(), end());
            }

            void swap (list<T> &x)
            {
			    list<T> tmp;

			    tmp.assign(x.begin(), x.end());
			    x.assign(begin(), end());
			    assign(tmp.begin(), tmp.end());
            }

            //Operations
	};
}